'use strict';

// Load modules

const Querystring = require('querystring');

const Boom = require('boom');
const Bounce = require('bounce');
const Cryptiles = require('cryptiles');
const Hoek = require('hoek');
const Iron = require('iron');
const Joi = require('joi');


// Declare internals

const internals = {};


internals.schema = Joi.object({
    strictHeader: Joi.boolean(),
    ignoreErrors: Joi.boolean(),
    isSecure: Joi.boolean(),
    isHttpOnly: Joi.boolean(),
    isSameSite: Joi.valid('Strict', 'Lax').allow(false),
    path: Joi.string().allow(null),
    domain: Joi.string().allow(null),
    ttl: Joi.number().allow(null),
    encoding: Joi.string().valid('base64json', 'base64', 'form', 'iron', 'none'),
    sign: Joi.object({
        password: [Joi.string(), Joi.binary(), Joi.object()],
        integrity: Joi.object()
    }),
    iron: Joi.object(),
    password: [Joi.string(), Joi.binary(), Joi.object()],

    // Used by hapi

    clearInvalid: Joi.boolean(),
    autoValue: Joi.any(),
    passThrough: Joi.boolean()
});


internals.defaults = {
    strictHeader: true,                             // Require an RFC 6265 compliant header format
    ignoreErrors: false,
    isSecure: true,
    isHttpOnly: true,
    isSameSite: 'Strict',
    path: null,
    domain: null,
    ttl: null,                                      // MSecs, 0 means remove
    encoding: 'none'                                // options: 'base64json', 'base64', 'form', 'iron', 'none'
};


exports.Definitions = internals.Definitions = function (options) {

    this.settings = Hoek.applyToDefaults(internals.defaults, options || {});
    Joi.assert(this.settings, internals.schema, 'Invalid state definition defaults');

    this.cookies = {};
    this.names = [];
};


internals.Definitions.prototype.add = function (name, options) {

    Hoek.assert(name && typeof name === 'string', 'Invalid name');
    Hoek.assert(!this.cookies[name], 'State already defined:', name);

    const settings = Hoek.applyToDefaults(this.settings, options || {}, true);
    Joi.assert(settings, internals.schema, 'Invalid state definition: ' + name);

    this.cookies[name] = settings;
    this.names.push(name);
};


internals.empty = new internals.Definitions();


// Header format

//                      1: name                2: quoted  3: value
internals.parseRx = /\s*([^=\s]*)\s*=\s*(?:(?:"([^\"]*)")|([^\;]*))(?:(?:;\s*)|$)/g;

internals.validateRx = {
    nameRx: {
        strict: /^[^\x00-\x20\(\)<>@\,;\:\\"\/\[\]\?\=\{\}\x7F]+$/,
        loose: /^[^=\s]*$/
    },
    valueRx: {
        strict: /^[^\x00-\x20\"\,\;\\\x7F]*$/,
        loose: /^(?:"([^\"]*)")|(?:[^\;]*)$/
    },
    domainRx: /^\.?[a-z\d]+(?:(?:[a-z\d]*)|(?:[a-z\d\-]*[a-z\d]))(?:\.[a-z\d]+(?:(?:[a-z\d]*)|(?:[a-z\d\-]*[a-z\d])))*$/,
    domainLabelLenRx: /^\.?[a-z\d\-]{1,63}(?:\.[a-z\d\-]{1,63})*$/,
    pathRx: /^\/[^\x00-\x1F\;]*$/
};

//                      1: name         2: value
internals.pairsRx = /\s*([^=\s]*)\s*=\s*([^\;]*)(?:(?:;\s*)|$)/g;


internals.Definitions.prototype.parse = async function (cookies) {

    const state = {};
    const names = [];
    const verify = cookies.replace(internals.parseRx, ($0, $1, $2, $3) => {

        const name = $1;
        const value = $2 || $3 || '';

        if (state[name]) {
            if (!Array.isArray(state[name])) {
                state[name] = [state[name]];
            }

            state[name].push(value);
        }
        else {
            state[name] = value;
            names.push(name);
        }

        return '';
    });

    // Validate cookie header syntax

    const failed = [];                                                // All errors

    if (verify !== '') {
        if (!this.settings.ignoreErrors) {
            throw Boom.badRequest('Invalid cookie header');
        }

        failed.push({ settings: this.settings, reason: `Header contains unexpected syntax: ${verify}` });
    }

    // Collect errors

    const errored = [];                                               // Unignored errors
    const record = (reason, name, value, definition) => {

        const details = {
            name,
            value,
            settings: definition,
            reason: typeof reason === 'string' ? reason : reason.message
        };

        failed.push(details);
        if (!definition.ignoreErrors) {
            errored.push(details);
        }
    };

    // Parse cookies

    const parsed = {};
    for (let i = 0; i < names.length; ++i) {
        const name = names[i];
        const value = state[name];
        const definition = this.cookies[name] || this.settings;

        // Validate cookie

        if (definition.strictHeader) {
            const reason = internals.validate(name, state);
            if (reason) {
                record(reason, name, value, definition);
                continue;
            }
        }

        // Check cookie format

        if (definition.encoding === 'none') {
            parsed[name] = value;
            continue;
        }

        // Single value

        if (!Array.isArray(value)) {
            try {
                const unsigned = await internals.unsign(name, value, definition);
                const result = await internals.decode(unsigned, definition);
                parsed[name] = result;
            }
            catch (err) {
                Bounce.rethrow(err, 'system');
                record(err, name, value, definition);
            }

            continue;
        }

        // Array

        const arrayResult = [];
        for (let j = 0; j < value.length; ++j) {
            const arrayValue = value[j];

            try {
                const unsigned = await internals.unsign(name, arrayValue, definition);
                const result = await internals.decode(unsigned, definition);
                arrayResult.push(result);
            }
            catch (err) {
                Bounce.rethrow(err, 'system');
                record(err, name, value, definition);
            }
        }

        parsed[name] = arrayResult;
    }

    if (errored.length) {
        const error = Boom.badRequest('Invalid cookie value', errored);
        error.states = parsed;
        error.failed = failed;
        throw error;
    }

    return { states: parsed, failed };
};


internals.validate = function (name, state) {

    if (!name.match(internals.validateRx.nameRx.strict)) {
        return 'Invalid cookie name';
    }

    const values = [].concat(state[name]);
    for (let i = 0; i < values.length; ++i) {
        if (!values[i].match(internals.validateRx.valueRx.strict)) {
            return 'Invalid cookie value';
        }
    }

    return null;
};


internals.macPrefix = 'hapi.signed.cookie.1';


internals.unsign = async function (name, value, definition) {

    if (!definition.sign) {
        return value;
    }

    const pos = value.lastIndexOf('.');
    if (pos === -1) {
        throw Boom.badRequest('Missing signature separator');
    }

    const unsigned = value.slice(0, pos);
    const sig = value.slice(pos + 1);

    if (!sig) {
        throw Boom.badRequest('Missing signature');
    }

    const sigParts = sig.split('*');
    if (sigParts.length !== 2) {
        throw Boom.badRequest('Invalid signature format');
    }

    const hmacSalt = sigParts[0];
    const hmac = sigParts[1];

    const macOptions = Hoek.clone(definition.sign.integrity || Iron.defaults.integrity);
    macOptions.salt = hmacSalt;
    const mac = await Iron.hmacWithPassword(definition.sign.password, macOptions, [internals.macPrefix, name, unsigned].join('\n'));
    if (!Cryptiles.fixedTimeComparison(mac.digest, hmac)) {
        throw Boom.badRequest('Invalid hmac value');
    }

    return unsigned;
};


internals.decode = async function (value, definition) {

    if (!value &&
        definition.encoding === 'form') {

        return {};
    }

    Hoek.assert(typeof value === 'string', 'Invalid string');

    // Encodings: 'base64json', 'base64', 'form', 'iron', 'none'

    if (definition.encoding === 'iron') {
        return await Iron.unseal(value, definition.password, definition.iron || Iron.defaults);
    }

    if (definition.encoding === 'base64json') {
        const decoded = (Buffer.from(value, 'base64')).toString('binary');
        try {
            return JSON.parse(decoded);
        }
        catch (err) {
            throw Boom.badRequest('Invalid JSON payload');
        }
    }

    if (definition.encoding === 'base64') {
        return (Buffer.from(value, 'base64')).toString('binary');
    }

    // encoding: 'form'

    return Querystring.parse(value);
};


internals.Definitions.prototype.format = async function (cookies) {

    if (!cookies ||
        (Array.isArray(cookies) && !cookies.length)) {

        return [];
    }

    if (!Array.isArray(cookies)) {
        cookies = [cookies];
    }

    const header = [];
    for (let i = 0; i < cookies.length; ++i) {
        const cookie = cookies[i];

        // Apply definition to local configuration

        const base = this.cookies[cookie.name] || this.settings;
        const definition = cookie.options ? Hoek.applyToDefaults(base, cookie.options, true) : base;

        // Validate name

        const nameRx = (definition.strictHeader ? internals.validateRx.nameRx.strict : internals.validateRx.nameRx.loose);
        if (!nameRx.test(cookie.name)) {
            throw Boom.badImplementation('Invalid cookie name: ' + cookie.name);
        }

        // Prepare value (encode, sign)

        const value = await exports.prepareValue(cookie.name, cookie.value, definition);

        // Validate prepared value

        const valueRx = (definition.strictHeader ? internals.validateRx.valueRx.strict : internals.validateRx.valueRx.loose);
        if (value &&
            (typeof value !== 'string' || !value.match(valueRx))) {

            throw Boom.badImplementation('Invalid cookie value: ' + cookie.value);
        }

        // Construct cookie

        let segment = cookie.name + '=' + (value || '');

        if (definition.ttl !== null &&
            definition.ttl !== undefined) {            // Can be zero

            const expires = new Date(definition.ttl ? Date.now() + definition.ttl : 0);
            segment = segment + '; Max-Age=' + Math.floor(definition.ttl / 1000) + '; Expires=' + expires.toUTCString();
        }

        if (definition.isSecure) {
            segment = segment + '; Secure';
        }

        if (definition.isHttpOnly) {
            segment = segment + '; HttpOnly';
        }

        if (definition.isSameSite) {
            segment = segment + `; SameSite=${definition.isSameSite}`;
        }

        if (definition.domain) {
            const domain = definition.domain.toLowerCase();
            if (!domain.match(internals.validateRx.domainLabelLenRx)) {
                throw Boom.badImplementation('Cookie domain too long: ' + definition.domain);
            }

            if (!domain.match(internals.validateRx.domainRx)) {
                throw Boom.badImplementation('Invalid cookie domain: ' + definition.domain);
            }

            segment = segment + '; Domain=' + domain;
        }

        if (definition.path) {
            if (!definition.path.match(internals.validateRx.pathRx)) {
                throw Boom.badImplementation('Invalid cookie path: ' + definition.path);
            }

            segment = segment + '; Path=' + definition.path;
        }

        header.push(segment);
    }

    return header;
};


exports.prepareValue = async function (name, value, options) {

    Hoek.assert(options && typeof options === 'object', 'Missing or invalid options');

    try {
        const encoded = await internals.encode(value, options);
        const signed = await internals.sign(name, encoded, options.sign);
        return signed;
    }
    catch (err) {
        throw Boom.badImplementation('Failed to encode cookie (' + name + ') value: ' + err.message);
    }
};


internals.encode = function (value, options) {

    // Encodings: 'base64json', 'base64', 'form', 'iron', 'none'

    if (value === undefined ||
        options.encoding === 'none') {

        return value;
    }

    if (options.encoding === 'iron') {
        return Iron.seal(value, options.password, options.iron || Iron.defaults);
    }

    if (options.encoding === 'base64') {
        return (Buffer.from(value, 'binary')).toString('base64');
    }

    if (options.encoding === 'base64json') {
        const stringified = JSON.stringify(value);
        return (Buffer.from(stringified, 'binary')).toString('base64');
    }

    // encoding: 'form'

    return Querystring.stringify(value);
};


internals.sign = async function (name, value, options) {

    if (value === undefined ||
        !options) {

        return value;
    }

    const mac = await Iron.hmacWithPassword(options.password, options.integrity || Iron.defaults.integrity, [internals.macPrefix, name, value].join('\n'));
    const signed = value + '.' + mac.salt + '*' + mac.digest;
    return signed;
};


internals.Definitions.prototype.passThrough = function (header, fallback) {

    if (!this.names.length) {
        return header;
    }

    const exclude = [];
    for (let i = 0; i < this.names.length; ++i) {
        const name = this.names[i];
        const definition = this.cookies[name];
        const passCookie = definition.passThrough !== undefined ? definition.passThrough : fallback;
        if (!passCookie) {
            exclude.push(name);
        }
    }

    return exports.exclude(header, exclude);
};


exports.exclude = function (cookies, excludes) {

    let result = '';
    const verify = cookies.replace(internals.pairsRx, ($0, $1, $2) => {

        if (excludes.indexOf($1) === -1) {
            result = result + (result ? ';' : '') + $1 + '=' + $2;
        }

        return '';
    });

    return verify === '' ? result : Boom.badRequest('Invalid cookie header');
};
