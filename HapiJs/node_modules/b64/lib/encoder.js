'use strict';

/*
    Encode functions adapted from:
    Version 1.0 12/25/99 Copyright (C) 1999 Masanao Izumo <iz@onicos.co.jp>
    http://www.onicos.com/staff/iz/amuse/javascript/expert/base64.txt
*/

// Load modules

const Stream = require('stream');


// Declare internals

const internals = {};


exports.encode = function (buffer) {

    return Buffer.from(buffer.toString('base64'));
};


exports.Encoder = class Encoder extends Stream.Transform {
    constructor() {

        super();
        this._reminder = null;
    }

    _transform(chunk, encoding, callback) {

        let part = this._reminder ? Buffer.concat([this._reminder, chunk]) : chunk;
        const remaining = part.length % 3;
        if (remaining) {
            this._reminder = part.slice(part.length - remaining);
            part = part.slice(0, part.length - remaining);
        }
        else {
            this._reminder = null;
        }

        this.push(exports.encode(part));
        return callback();
    }

    _flush(callback) {

        if (this._reminder) {
            this.push(exports.encode(this._reminder));
        }

        return callback();
    }
};
