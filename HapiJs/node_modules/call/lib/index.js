'use strict';

// Load modules

const Hoek = require('hoek');
const Boom = require('boom');

const Regex = require('./regex');
const Segment = require('./segment');


// Declare internals

const internals = {
    pathRegex: Regex.generate(),
    defaults: {
        isCaseSensitive: true
    }
};


exports.Router = internals.Router = function (options) {

    this.settings = Hoek.applyToDefaults(internals.defaults, options || {});

    this.routes = {};                               // Key: HTTP method or * for catch-all, value: sorted array of routes
    this.ids = {};                                  // Key: route id, value: record
    this.vhosts = null;                             // {} where Key: hostname, value: see this.routes

    this.specials = {
        badRequest: null,
        notFound: null,
        options: null
    };
};


internals.Router.prototype.add = function (config, route) {

    const method = config.method.toLowerCase();

    const vhost = config.vhost || '*';
    if (vhost !== '*') {
        this.vhosts = this.vhosts || {};
        this.vhosts[vhost] = this.vhosts[vhost] || {};
    }

    const table = (vhost === '*' ? this.routes : this.vhosts[vhost]);
    table[method] = table[method] || { routes: [], router: new Segment() };

    const analysis = config.analysis || this.analyze(config.path);
    const record = {
        path: config.path,
        route: route || config.path,
        segments: analysis.segments,
        params: analysis.params,
        fingerprint: analysis.fingerprint,
        settings: this.settings
    };

    // Add route

    table[method].router.add(analysis.segments, record);
    table[method].routes.push(record);
    table[method].routes.sort(internals.sort);

    const last = record.segments[record.segments.length - 1];
    if (last.empty) {
        table[method].router.add(analysis.segments.slice(0, -1), record);
    }

    if (config.id) {
        Hoek.assert(!this.ids[config.id], 'Route id', config.id, 'for path', config.path, 'conflicts with existing path', this.ids[config.id] && this.ids[config.id].path);
        this.ids[config.id] = record;
    }

    return record;
};


internals.Router.prototype.special = function (type, route) {

    Hoek.assert(Object.keys(this.specials).indexOf(type) !== -1, 'Unknown special route type:', type);

    this.specials[type] = { route };
};


internals.Router.prototype.route = function (method, path, hostname) {

    const segments = path.split('/').slice(1);

    const vhost = (this.vhosts && hostname && this.vhosts[hostname]);
    const route = (vhost && this._lookup(path, segments, vhost, method)) ||
        this._lookup(path, segments, this.routes, method) ||
        (method === 'head' && vhost && this._lookup(path, segments, vhost, 'get')) ||
        (method === 'head' && this._lookup(path, segments, this.routes, 'get')) ||
        (method === 'options' && this.specials.options) ||
        (vhost && this._lookup(path, segments, vhost, '*')) ||
        this._lookup(path, segments, this.routes, '*') ||
        this.specials.notFound || Boom.notFound();

    return route;
};


internals.Router.prototype._lookup = function (path, segments, table, method) {

    const set = table[method];
    if (!set) {
        return null;
    }

    const match = set.router.lookup(path, segments, this.settings);
    if (!match) {
        return null;
    }

    const assignments = {};
    const array = [];
    for (let i = 0; i < match.array.length; ++i) {
        const name = match.record.params[i];
        const value = internals.decode(match.array[i]);
        if (value.isBoom) {
            return this.specials.badRequest || value;
        }

        if (assignments[name] !== undefined) {
            assignments[name] = assignments[name] + '/' + value;
        }
        else {
            assignments[name] = value;
        }

        if (i + 1 === match.array.length ||                 // Only include the last segment of a multi-segment param
            name !== match.record.params[i + 1]) {

            array.push(assignments[name]);
        }
    }

    return { params: assignments, paramsArray: array, route: match.record.route };
};


internals.decode = function (value) {

    try {
        return decodeURIComponent(value);
    }
    catch (err) {
        return Boom.badRequest('Invalid request path');
    }
};


internals.Router.prototype.normalize = function (path) {

    if (path &&
        path.indexOf('%') !== -1) {

        // Uppercase %encoded values

        const uppercase = path.replace(/%[0-9a-fA-F][0-9a-fA-F]/g, (encoded) => encoded.toUpperCase());

        // Decode non-reserved path characters: a-z A-Z 0-9 _!$&'()*+,;=:@-.~
        // ! (%21) $ (%24) & (%26) ' (%27) ( (%28) ) (%29) * (%2A) + (%2B) , (%2C) - (%2D) . (%2E)
        // 0-9 (%30-39) : (%3A) ; (%3B) = (%3D)
        // @ (%40) A-Z (%41-5A) _ (%5F) a-z (%61-7A) ~ (%7E)

        const decoded = uppercase.replace(/%(?:2[146-9A-E]|3[\dABD]|4[\dA-F]|5[\dAF]|6[1-9A-F]|7[\dAE])/g, (encoded) => String.fromCharCode(parseInt(encoded.substring(1), 16)));

        path = decoded;
    }

    // Normalize path segments

    if (path &&
        (path.indexOf('/.') !== -1 || path[0] === '.')) {

        const hasLeadingDash = path[0] === '/';
        const segments = path.split('/');
        const normalized = [];
        let segment;

        for (let i = 0; i < segments.length; ++i) {
            segment = segments[i];
            if (segment === '..') {
                normalized.pop();
            }
            else if (segment !== '.') {
                normalized.push(segment);
            }
        }

        if (segment === '.' ||
            segment === '..') {         // Add trailing slash when needed

            normalized.push('');
        }

        path = normalized.join('/');

        if (path[0] !== '/' &&
            hasLeadingDash) {

            path = '/' + path;
        }
    }

    return path;
};


internals.Router.prototype.analyze = function (path) {

    Hoek.assert(internals.pathRegex.validatePath.test(path), 'Invalid path:', path);
    Hoek.assert(!internals.pathRegex.validatePathEncoded.test(path), 'Path cannot contain encoded non-reserved path characters:', path);

    const pathParts = path.split('/');
    const segments = [];
    const params = [];
    const fingers = [];

    for (let i = 1; i < pathParts.length; ++i) {                            // Skip first empty segment
        let segment = pathParts[i];

        // Literal

        if (segment.indexOf('{') === -1) {
            segment = this.settings.isCaseSensitive ? segment : segment.toLowerCase();
            fingers.push(segment);
            segments.push({ literal: segment });
            continue;
        }

        // Parameter

        const parts = internals.parseParams(segment);
        if (parts.length === 1) {

            // Simple parameter

            const item = parts[0];
            Hoek.assert(params.indexOf(item.name) === -1, 'Cannot repeat the same parameter name:', item.name, 'in:', path);
            params.push(item.name);

            if (item.wilcard) {
                if (item.count) {
                    for (let j = 0; j < item.count; ++j) {
                        fingers.push('?');
                        segments.push({});
                        if (j) {
                            params.push(item.name);
                        }
                    }
                }
                else {
                    fingers.push('#');
                    segments.push({ wildcard: true });
                }
            }
            else {
                fingers.push('?');
                segments.push({ empty: item.empty });
            }
        }
        else {

            // Mixed parameter

            const seg = {
                length: parts.length,
                first: typeof parts[0] !== 'string',
                segments: []
            };

            let finger = '';
            let regex = '^';
            for (let j = 0; j < parts.length; ++j) {
                const part = parts[j];
                if (typeof part === 'string') {
                    finger = finger + part;
                    regex = regex + Hoek.escapeRegex(part);
                    seg.segments.push(part);
                }
                else {
                    Hoek.assert(params.indexOf(part.name) === -1, 'Cannot repeat the same parameter name:', part.name, 'in:', path);
                    params.push(part.name);

                    finger = finger + '?';
                    regex = regex + '(.' + (part.empty ? '*' : '+') + ')';
                }
            }

            seg.mixed = new RegExp(regex + '$', (!this.settings.isCaseSensitive ? 'i' : ''));
            fingers.push(finger);
            segments.push(seg);
        }
    }

    return {
        segments,
        fingerprint: '/' + fingers.join('/'),
        params
    };
};


internals.parseParams = function (segment) {

    const parts = [];
    segment.replace(internals.pathRegex.parseParam, (match, literal, name, wilcard, count, empty) => {

        if (literal) {
            parts.push(literal);
        }
        else {
            parts.push({
                name,
                wilcard: !!wilcard,
                count: count && parseInt(count, 10),
                empty: !!empty
            });
        }

        return '';
    });

    return parts;
};


internals.Router.prototype.table = function (host) {

    const result = [];
    const collect = (table) => {

        if (!table) {
            return;
        }

        Object.keys(table).forEach((method) => {

            table[method].routes.forEach((record) => {

                result.push(record.route);
            });
        });
    };

    if (this.vhosts) {
        const vhosts = host ? [].concat(host) : Object.keys(this.vhosts);
        for (let i = 0; i < vhosts.length; ++i) {
            collect(this.vhosts[vhosts[i]]);
        }
    }

    collect(this.routes);

    return result;
};


internals.sort = function (a, b) {

    const aFirst = -1;
    const bFirst = 1;

    const as = a.segments;
    const bs = b.segments;

    if (as.length !== bs.length) {
        return (as.length > bs.length ? bFirst : aFirst);
    }

    for (let i = 0; ; ++i) {
        if (as[i].literal) {
            if (bs[i].literal) {
                if (as[i].literal === bs[i].literal) {
                    continue;
                }

                return (as[i].literal > bs[i].literal ? bFirst : aFirst);
            }
            return aFirst;
        }
        else if (bs[i].literal) {
            return bFirst;
        }

        return (as[i].wildcard ? bFirst : aFirst);
    }
};
