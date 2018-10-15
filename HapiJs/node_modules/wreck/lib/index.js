'use strict';

// Load modules

const Events = require('events');
const Http = require('http');
const Https = require('https');
const Stream = require('stream');
const Url = require('url');
const Zlib = require('zlib');

const Boom = require('boom');
const Hoek = require('hoek');

const Payload = require('./payload');
const Recorder = require('./recorder');
const Tap = require('./tap');


// Declare internals

const internals = {
    jsonRegex: /^application\/([a-z0-9.]*[+-]json|json)$/,
    shallowOptions: ['agent', 'agents', 'beforeRedirect', 'downstreamRes', 'payload', 'redirected']
};


// New instance is exported as module.exports

internals.Client = function (options = {}) {

    Hoek.assert(!options.agents || (options.agents.https && options.agents.http && options.agents.httpsAllowUnauthorized), 'Option agents must include "http", "https", and "httpsAllowUnauthorized"');

    this._defaults = Hoek.cloneWithShallow(options, internals.shallowOptions);

    this.agents = this._defaults.agents || {
        https: new Https.Agent({ maxSockets: Infinity }),
        http: new Http.Agent({ maxSockets: Infinity }),
        httpsAllowUnauthorized: new Https.Agent({ maxSockets: Infinity, rejectUnauthorized: false })
    };

    if (!options.events) {
        return;
    }

    this.events = new Events.EventEmitter();
    this._emit = function (...args) {

        this.events.emit(...args);
    };
};


internals.Client.prototype.defaults = function (options) {

    Hoek.assert(options && (typeof options === 'object'), 'options must be provided to defaults');

    options = Hoek.applyToDefaultsWithShallow(this._defaults, options, internals.shallowOptions);
    return new internals.Client(options);
};


internals.resolveUrl = function (baseUrl, path) {

    if (!path) {
        return baseUrl;
    }

    const parsedPath = Url.parse(path);
    if (parsedPath.host &&
        parsedPath.protocol) {

        return Url.format(parsedPath);
    }

    const parsedBase = Url.parse(baseUrl);
    parsedBase.pathname = parsedBase.pathname + parsedPath.pathname;
    parsedBase.pathname = parsedBase.pathname.replace(/[/]{2,}/g, '/');
    parsedBase.search = parsedPath.search;      // Always use the querystring from the path argument

    return Url.format(parsedBase);
};


internals.Client.prototype.request = function (method, url, options = {}) {

    try {
        options = Hoek.applyToDefaultsWithShallow(this._defaults, options, internals.shallowOptions);

        Hoek.assert(options.payload === undefined || typeof options.payload === 'string' || typeof options.payload === 'object', 'options.payload must be a string, a Buffer, a Stream, or an Object');
        Hoek.assert((options.agent === undefined || options.agent === null) || (typeof options.rejectUnauthorized !== 'boolean'), 'options.agent cannot be set to an Agent at the same time as options.rejectUnauthorized is set');
        Hoek.assert(options.beforeRedirect === undefined || options.beforeRedirect === null || typeof options.beforeRedirect === 'function', 'options.beforeRedirect must be a function');
        Hoek.assert(options.redirected === undefined || options.redirected === null || typeof options.redirected === 'function', 'options.redirected must be a function');
        Hoek.assert(options.gunzip === undefined || typeof options.gunzip === 'boolean' || options.gunzip === 'force', 'options.gunzip must be a boolean or "force"');
    }
    catch (err) {
        return Promise.reject(err);
    }

    options.beforeRedirect = options.beforeRedirect || ((redirectMethod, statusCode, location, resHeaders, redirectOptions, next) => next());

    if (options.baseUrl) {
        url = internals.resolveUrl(options.baseUrl, url);
        delete options.baseUrl;
    }

    const relay = {};
    const req = this._request(method, url, options, relay);
    const promise = new Promise((resolve, reject) => {

        relay.callback = (err, res) => {

            if (err) {
                reject(err);
                return;
            }

            resolve(res);
            return;
        };
    });

    promise.req = req;
    return promise;
};


internals.Client.prototype._request = function (method, url, options, relay, _trace) {

    const uri = Url.parse(url);

    if (options.socketPath) {
        uri.socketPath = options.socketPath;
        delete options.socketPath;
    }

    uri.method = method.toUpperCase();
    uri.headers = options.headers || {};
    const hasContentLength = internals.findHeader('content-length', uri.headers) !== undefined;

    if (options.payload && typeof options.payload === 'object' && !(options.payload instanceof Stream) && !Buffer.isBuffer(options.payload)) {
        options.payload = JSON.stringify(options.payload);
        if (!internals.findHeader('content-type', uri.headers)) {
            uri.headers['content-type'] = 'application/json';
        }
    }

    if (options.gunzip && internals.findHeader('accept-encoding', uri.headers) === undefined) {
        uri.headers['accept-encoding'] = 'gzip';
    }

    const payloadSupported = (uri.method !== 'GET' && uri.method !== 'HEAD' && options.payload !== null && options.payload !== undefined);
    if (payloadSupported &&
        (typeof options.payload === 'string' || Buffer.isBuffer(options.payload)) &&
        (!hasContentLength)) {

        uri.headers = Hoek.clone(uri.headers);
        uri.headers['content-length'] = Buffer.isBuffer(options.payload) ? options.payload.length : Buffer.byteLength(options.payload);
    }

    let redirects = (options.hasOwnProperty('redirects') ? options.redirects : false);      // Needed to allow 0 as valid value when passed recursively

    _trace = (_trace || []);
    _trace.push({ method: uri.method, url });

    const client = (uri.protocol === 'https:' ? Https : Http);

    if (options.rejectUnauthorized !== undefined && uri.protocol === 'https:') {
        uri.agent = options.rejectUnauthorized ? this.agents.https : this.agents.httpsAllowUnauthorized;
    }
    else if (options.agent || options.agent === false) {
        uri.agent = options.agent;
    }
    else {
        uri.agent = uri.protocol === 'https:' ? this.agents.https : this.agents.http;
    }

    if (options.secureProtocol !== undefined) {
        uri.secureProtocol = options.secureProtocol;
    }

    if (options.ciphers !== undefined) {
        uri.ciphers = options.ciphers;
    }

    if (this._emit) {
        this._emit('request', uri, options);
    }

    const start = Date.now();
    const req = client.request(uri);

    let shadow = null;                                                                      // A copy of the streamed request payload when redirects are enabled
    let timeoutId;

    const onError = (err) => {

        err.trace = _trace;
        return finishOnce(Boom.badGateway('Client request error', err));
    };

    req.once('error', onError);

    const onResponse = (res) => {

        // Pass-through response

        const statusCode = res.statusCode;
        const redirectMethod = internals.redirectMethod(statusCode, uri.method, options);

        if (redirects === false ||
            !redirectMethod) {

            return finishOnce(null, res);
        }

        // Redirection

        res.destroy();

        if (redirects === 0) {
            return finishOnce(Boom.badGateway('Maximum redirections reached', _trace));
        }

        let location = res.headers.location;
        if (!location) {
            return finishOnce(Boom.badGateway('Received redirection without location', _trace));
        }

        if (!/^https?:/i.test(location)) {
            location = Url.resolve(uri.href, location);
        }

        const redirectOptions = Hoek.cloneWithShallow(options, internals.shallowOptions);
        redirectOptions.payload = shadow || options.payload;                                    // shadow must be ready at this point if set
        redirectOptions.redirects = --redirects;

        return options.beforeRedirect(redirectMethod, statusCode, location, res.headers, redirectOptions, () => {

            const redirectReq = this._request(redirectMethod, location, redirectOptions, { callback: finishOnce }, _trace);

            if (options.redirected) {
                options.redirected(statusCode, location, redirectReq);
            }
        });
    };

    // Register handlers

    const finish = (err, res) => {

        if (err) {
            req.abort();
        }

        req.removeListener('response', onResponse);
        req.removeListener('error', onError);
        req.on('error', Hoek.ignore);
        clearTimeout(timeoutId);

        if (this._emit) {
            this._emit('response', err, { req, res, start, uri });
        }

        return relay.callback(err, res);
    };

    const finishOnce = Hoek.once(finish);

    req.once('response', onResponse);

    if (options.timeout) {
        timeoutId = setTimeout(() => {

            return finishOnce(Boom.gatewayTimeout('Client request timeout'));
        }, options.timeout);
        delete options.timeout;
    }

    // Custom abort method to detect early aborts

    const _abort = req.abort;
    let aborted = false;
    req.abort = () => {

        if (!aborted && !req.res && !req.socket) {
            process.nextTick(() => {

                // Fake an ECONNRESET error

                const error = new Error('socket hang up');
                error.code = 'ECONNRESET';
                finishOnce(error);
            });
        }

        aborted = true;
        return _abort.call(req);
    };

    // Write payload

    if (payloadSupported) {
        if (options.payload instanceof Stream) {
            let stream = options.payload;

            if (redirects) {
                const collector = new Tap();
                collector.once('finish', () => {

                    shadow = collector.collect();
                });

                stream = options.payload.pipe(collector);
            }

            internals.deferPipeUntilSocketConnects(req, stream);
            return req;
        }

        req.write(options.payload);
    }

    // Finalize request

    req.end();
    return req;
};


internals.deferPipeUntilSocketConnects = function (req, stream) {

    const onSocket = (socket) => {

        if (!socket.connecting) {
            return onSocketConnect();
        }

        socket.once('connect', onSocketConnect);
    };
    const onSocketConnect = () => {

        stream.pipe(req);
        stream.removeListener('error', onStreamError);
    };
    const onStreamError = (err) => {

        req.emit('error', err);
    };

    req.once('socket', onSocket);
    stream.on('error', onStreamError);
};


internals.redirectMethod = function (code, method, options) {

    switch (code) {
        case 301:
        case 302:
            return method;

        case 303:
            if (options.redirect303) {
                return 'GET';
            }
            break;

        case 307:
        case 308:
            return method;
    }

    return null;
};


internals.Client.prototype.read = function (res, options = {}) {

    return new Promise((resolve, reject) => {

        this._read(res, options, (err, payload) => {

            if (err) {
                reject(err);
                return;
            }

            resolve(payload);
            return;
        });
    });
};


internals.Client.prototype._read = function (res, options, callback) {

    options = Hoek.applyToDefaultsWithShallow(this._defaults, options, internals.shallowOptions);

    // Finish once

    let clientTimeoutId = null;

    const finish = (err, buffer) => {

        clearTimeout(clientTimeoutId);
        reader.removeListener('error', onReaderError);
        reader.removeListener('finish', onReaderFinish);
        res.removeListener('error', onResError);
        res.removeListener('close', onResAborted);
        res.removeListener('aborted', onResAborted);
        res.on('error', Hoek.ignore);

        if (err) {
            return callback(err);
        }

        if (!options.json) {
            return callback(null, buffer);
        }

        // Parse JSON

        if (buffer.length === 0) {
            return callback(null, null);
        }

        if (options.json === 'force') {
            return internals.tryParseBuffer(buffer, callback);
        }

        // mode is "smart", "strict" or true

        const contentType = (res.headers && internals.findHeader('content-type', res.headers)) || '';
        const mime = contentType.split(';')[0].trim().toLowerCase();

        if (!internals.jsonRegex.test(mime)) {
            if (options.json === 'strict') {
                return callback(Boom.notAcceptable('The content-type is not JSON compatible'));
            }

            return callback(null, buffer);
        }

        return internals.tryParseBuffer(buffer, callback);
    };

    const finishOnce = Hoek.once(finish);

    const clientTimeout = options.timeout;
    if (clientTimeout &&
        clientTimeout > 0) {

        clientTimeoutId = setTimeout(() => {

            finishOnce(Boom.clientTimeout());
        }, clientTimeout);
    }

    // Hander errors

    const onResError = (err) => {

        return finishOnce(err.isBoom ? err : Boom.internal('Payload stream error', err));
    };

    const onResAborted = () => {

        // Workaround https://github.com/nodejs/node/pull/20611
        // This is covered in node 10
        /* $lab:coverage:off$ */
        if (res.complete) {
            return;
        }
        /* $lab:coverage:on$ */

        return finishOnce(Boom.internal('Payload stream closed prematurely'));
    };

    res.once('error', onResError);
    res.once('close', onResAborted);
    res.once('aborted', onResAborted);

    // Read payload

    const reader = new Recorder({ maxBytes: options.maxBytes });

    const onReaderError = (err) => {

        if (res.destroy) {                          // GZip stream has no destroy() method
            res.destroy();
        }

        return finishOnce(err);
    };

    reader.once('error', onReaderError);

    const onReaderFinish = () => {

        return finishOnce(null, reader.collect());
    };

    reader.once('finish', onReaderFinish);

    if (options.gunzip) {
        const contentEncoding = options.gunzip === 'force' ?
            'gzip' :
            (res.headers && internals.findHeader('content-encoding', res.headers)) || '';

        if (/^(x-)?gzip(\s*,\s*identity)?$/.test(contentEncoding)) {
            const gunzip = Zlib.createGunzip();

            gunzip.once('error', onReaderError);

            res.pipe(gunzip).pipe(reader);
            return;
        }
    }

    res.pipe(reader);
};


internals.Client.prototype.toReadableStream = function (payload, encoding) {

    return new Payload(payload, encoding);
};


internals.Client.prototype.parseCacheControl = function (field) {

    /*
        Cache-Control   = 1#cache-directive
        cache-directive = token [ "=" ( token / quoted-string ) ]
        token           = [^\x00-\x20\(\)<>@\,;\:\\"\/\[\]\?\=\{\}\x7F]+
        quoted-string   = "(?:[^"\\]|\\.)*"
    */

    //                             1: directive                                        =   2: token                                              3: quoted-string
    const regex = /(?:^|(?:\s*\,\s*))([^\x00-\x20\(\)<>@\,;\:\\"\/\[\]\?\=\{\}\x7F]+)(?:\=(?:([^\x00-\x20\(\)<>@\,;\:\\"\/\[\]\?\=\{\}\x7F]+)|(?:\"((?:[^"\\]|\\.)*)\")))?/g;

    const header = {};
    const error = field.replace(regex, ($0, $1, $2, $3) => {

        const value = $2 || $3;
        header[$1] = value ? value.toLowerCase() : true;
        return '';
    });

    if (header['max-age']) {
        try {
            const maxAge = parseInt(header['max-age'], 10);
            if (isNaN(maxAge)) {
                return null;
            }

            header['max-age'] = maxAge;
        }
        catch (err) { }
    }

    return (error ? null : header);
};


// Shortcuts

internals.Client.prototype.get = function (uri, options) {

    return this._shortcut('GET', uri, options);
};


internals.Client.prototype.post = function (uri, options) {

    return this._shortcut('POST', uri, options);
};


internals.Client.prototype.patch = function (uri, options) {

    return this._shortcut('PATCH', uri, options);
};


internals.Client.prototype.put = function (uri, options) {

    return this._shortcut('PUT', uri, options);
};


internals.Client.prototype.delete = function (uri, options) {

    return this._shortcut('DELETE', uri, options);
};


internals.Client.prototype._shortcut = async function (method, uri, options = {}) {

    const res = await this.request(method, uri, options);

    let payload;
    try {
        payload = await this.read(res, options);
    }
    catch (err) {
        err.data = err.data || {};
        err.data.res = res;
        throw err;
    }

    if (res.statusCode < 400) {
        return { res, payload };
    }

    // Response error

    const data = {
        isResponseError: true,
        headers: res.headers,
        res,
        payload
    };

    throw new Boom(`Response Error: ${res.statusCode} ${res.statusMessage}`, { statusCode: res.statusCode, data });
};


internals.tryParseBuffer = function (buffer, next) {

    let payload;
    try {
        payload = JSON.parse(buffer.toString());
    }
    catch (err) {
        return next(Boom.badGateway(err.message, { payload: buffer }));
    }

    return next(null, payload);
};


internals.findHeader = function (headerName, headers) {

    const foundKey = Object.keys(headers)
        .find((key) => key.toLowerCase() === headerName.toLowerCase());

    return foundKey && headers[foundKey];
};


module.exports = new internals.Client();
