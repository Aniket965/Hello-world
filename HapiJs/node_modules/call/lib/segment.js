'use strict';

// Load modules

const Hoek = require('hoek');


// Declare internals

const internals = {};


exports = module.exports = internals.Segment = function () {

    this._edge = null;              // { segment, record }
    this._fulls = null;             // { path: { segment, record }
    this._literals = null;          // { literal: { segment, <node> } }
    this._param = null;             // <node>
    this._mixed = null;             // [{ segment, <node> }]
    this._wildcard = null;          // { segment, record }
};


internals.Segment.prototype.add = function (segments, record) {

    /*
        { literal: 'x' }        -> x
        { empty: false }        -> {p}
        { wildcard: true }      -> {p*}
        { mixed: /regex/ }      -> a{p}b
    */

    const current = segments[0];
    const remaining = segments.slice(1);
    const isEdge = !remaining.length;

    const literals = [];
    let isLiteral = true;
    for (let i = 0; i < segments.length && isLiteral; ++i) {
        isLiteral = segments[i].literal !== undefined;
        literals.push(segments[i].literal);
    }

    if (isLiteral) {
        this._fulls = this._fulls || {};
        let literal = '/' + literals.join('/');
        if (!record.settings.isCaseSensitive) {
            literal = literal.toLowerCase();
        }

        Hoek.assert(!this._fulls[literal], 'New route', record.path, 'conflicts with existing', this._fulls[literal] && this._fulls[literal].record.path);
        this._fulls[literal] = { segment: current, record };
    }
    else if (current.literal !== undefined) {               // Can be empty string

        // Literal

        this._literals = this._literals || {};
        const currentLiteral = (record.settings.isCaseSensitive ? current.literal : current.literal.toLowerCase());
        this._literals[currentLiteral] = this._literals[currentLiteral] || new internals.Segment();
        this._literals[currentLiteral].add(remaining, record);
    }
    else if (current.wildcard) {

        // Wildcard

        Hoek.assert(!this._wildcard, 'New route', record.path, 'conflicts with existing', this._wildcard && this._wildcard.record.path);
        Hoek.assert(!this._param || !this._param._wildcard, 'New route', record.path, 'conflicts with existing', this._param && this._param._wildcard && this._param._wildcard.record.path);
        this._wildcard = { segment: current, record };
    }
    else if (current.mixed) {

        // Mixed

        this._mixed = this._mixed || [];

        let mixed = this._mixedLookup(current);
        if (!mixed) {
            mixed = { segment: current, node: new internals.Segment() };
            this._mixed.push(mixed);
            this._mixed.sort(internals.mixed);
        }

        if (isEdge) {
            Hoek.assert(!mixed.node._edge, 'New route', record.path, 'conflicts with existing', mixed.node._edge && mixed.node._edge.record.path);
            mixed.node._edge = { segment: current, record };
        }
        else {
            mixed.node.add(remaining, record);
        }
    }
    else {

        // Parameter

        this._param = this._param || new internals.Segment();

        if (isEdge) {
            Hoek.assert(!this._param._edge, 'New route', record.path, 'conflicts with existing', this._param._edge && this._param._edge.record.path);
            this._param._edge = { segment: current, record };
        }
        else {
            Hoek.assert(!this._wildcard || !remaining[0].wildcard, 'New route', record.path, 'conflicts with existing', this._wildcard && this._wildcard.record.path);
            this._param.add(remaining, record);
        }
    }
};


internals.Segment.prototype._mixedLookup = function (segment) {

    for (let i = 0; i < this._mixed.length; ++i) {
        if (internals.mixed({ segment }, this._mixed[i]) === 0) {
            return this._mixed[i];
        }
    }

    return null;
};


internals.mixed = function (a, b) {

    const aFirst = -1;
    const bFirst = 1;

    const as = a.segment;
    const bs = b.segment;

    if (as.length !== bs.length) {
        return (as.length > bs.length ? aFirst : bFirst);
    }

    if (as.first !== bs.first) {
        return (as.first ? bFirst : aFirst);
    }

    for (let i = 0; i < as.segments.length; ++i) {
        const am = as.segments[i];
        const bm = bs.segments[i];

        if (am === bm) {
            continue;
        }

        if (am.length === bm.length) {
            return (am > bm ? bFirst : aFirst);
        }

        return (am.length < bm.length ? bFirst : aFirst);
    }

    return 0;
};


internals.Segment.prototype.lookup = function (path, segments, options) {

    let match = null;

    // Literal edge

    if (this._fulls) {
        match = this._fulls[options.isCaseSensitive ? path : path.toLowerCase()];
        if (match) {
            return { record: match.record, array: [] };
        }
    }

    // Literal node

    const current = segments[0];
    const nextPath = path.slice(current.length + 1);
    const remainder = (segments.length > 1 ? segments.slice(1) : null);

    if (this._literals) {
        const literal = options.isCaseSensitive ? current : current.toLowerCase();
        match = this._literals.hasOwnProperty(literal) && this._literals[literal];
        if (match) {
            const record = internals.deeper(match, nextPath, remainder, [], options);
            if (record) {
                return record;
            }
        }
    }

    // Mixed

    if (this._mixed) {
        for (let i = 0; i < this._mixed.length; ++i) {
            match = this._mixed[i];
            const params = current.match(match.segment.mixed);
            if (params) {
                const array = [];
                for (let j = 1; j < params.length; ++j) {
                    array.push(params[j]);
                }

                const record = internals.deeper(match.node, nextPath, remainder, array, options);
                if (record) {
                    return record;
                }
            }
        }
    }

    // Param

    if (this._param) {
        if (current ||
            (this._param._edge && this._param._edge.segment.empty)) {

            const record = internals.deeper(this._param, nextPath, remainder, [current], options);
            if (record) {
                return record;
            }
        }
    }

    // Wildcard

    if (this._wildcard) {
        return { record: this._wildcard.record, array: [path.slice(1)] };
    }

    return null;
};


internals.deeper = function (match, path, segments, array, options) {

    if (!segments) {
        if (match._edge) {
            return { record: match._edge.record, array };
        }

        if (match._wildcard) {
            return { record: match._wildcard.record, array };
        }
    }
    else {
        const result = match.lookup(path, segments, options);
        if (result) {
            return { record: result.record, array: array.concat(result.array) };
        }
    }

    return null;
};
