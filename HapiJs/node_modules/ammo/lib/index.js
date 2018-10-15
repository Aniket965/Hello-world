'use strict';

// Load modules

const Stream = require('stream');

const Hoek = require('hoek');


// Declare internals

const internals = {};


internals.Range = class {

    constructor(from, to) {

        this.from = from;
        this.to = to;
    }
};


exports.header = function (header, length) {

    // Parse header

    const parts = header.split('=');
    if (parts.length !== 2 ||
        parts[0] !== 'bytes') {

        return null;
    }

    const lastPos = length - 1;

    const result = [];
    const ranges = parts[1].match(/\d*\-\d*/g);

    // Handle headers with multiple ranges

    for (let i = 0; i < ranges.length; ++i) {
        let range = ranges[i];
        if (range.length === 1) {               // '-'
            return null;
        }

        let from;
        let to;
        range = range.split('-');
        if (range[0]) {
            from = parseInt(range[0], 10);
        }

        if (range[1]) {
            to = parseInt(range[1], 10);
            if (from !== undefined) {      // Can be 0
                // From-To
                if (to > lastPos) {
                    to = lastPos;
                }
            }
            else {
                // -To
                from = length - to;
                to = lastPos;
            }
        }
        else {
            // From-
            to = lastPos;
        }

        if (from > to) {
            return null;
        }

        result.push(new internals.Range(from, to));
    }

    if (result.length === 1) {
        return result;
    }

    // Sort and consolidate ranges

    result.sort((a, b) => a.from - b.from);

    const consolidated = [];
    for (let i = result.length - 1; i > 0; --i) {
        const current = result[i];
        const before = result[i - 1];
        if (current.from <= before.to + 1) {
            before.to = current.to;
        }
        else {
            consolidated.unshift(current);
        }
    }

    consolidated.unshift(result[0]);

    return consolidated;
};


exports.Stream = internals.Stream = class extends Stream.Transform {

    constructor(range) {

        if (!(range instanceof internals.Range)) {
            Hoek.assert(typeof range === 'object', 'Expected "range" object');

            const from = range.from || 0;
            Hoek.assert(typeof from === 'number', '"range.from" must be falsy, or a number');
            Hoek.assert(from === parseInt(from, 10) && from >= 0, '"range.from" must be a positive integer');

            const to = range.to || 0;
            Hoek.assert(typeof to === 'number', '"range.to" must be falsy, or a number');
            Hoek.assert(to === parseInt(to, 10) && to >= 0, '"range.to" must be a positive integer');

            Hoek.assert(to >= from, '"range.to" must be greater than or equal to "range.from"');

            range = new internals.Range(from, to);
        }

        super();

        this._range = range;
        this._next = 0;
    }

    processChunk(chunk) {

        // Read desired range from a stream

        const pos = this._next;
        this._next = this._next + chunk.length;

        if (this._next <= this._range.from ||       // Before range
            pos > this._range.to) {                 // After range

            return;
        }

        // Calc bounds of chunk to read

        const from = Math.max(0, this._range.from - pos);
        const to = Math.min(chunk.length, this._range.to - pos + 1);

        this.push(chunk.slice(from, to));
    }

    _transform(chunk, encoding, done) {

        try {
            this.processChunk(chunk);
        }
        catch (err) {
            return done(err);
        }

        return done();
    }
};
