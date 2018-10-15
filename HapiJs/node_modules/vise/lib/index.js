'use strict';

// Load modules

const Hoek = require('hoek');


// Declare internals

const internals = {};


exports = module.exports = internals.Vise = function (chunks) {

    this.length = 0;
    this._chunks = [];
    this._offset = 0;

    if (chunks) {
        chunks = [].concat(chunks);
        for (let i = 0; i < chunks.length; ++i) {
            this.push(chunks[i]);
        }
    }
};


internals.Vise.prototype.push = function (chunk) {

    Hoek.assert(Buffer.isBuffer(chunk), 'Chunk must be a buffer');

    const item = {
        data: chunk,
        length: chunk.length,
        offset: this.length + this._offset,
        index: this._chunks.length
    };

    this._chunks.push(item);
    this.length += chunk.length;
};


internals.Vise.prototype.shift = function (length) {

    if (!length) {
        return [];
    }

    const prevOffset = this._offset;
    const item = this._chunkAt(length);

    let dropTo = this._chunks.length;
    this._offset = 0;

    if (item) {
        dropTo = item.chunk.index;
        this._offset = item.offset;
    }

    // Drop lower chunks

    const chunks = [];
    for (let i = 0; i < dropTo; ++i) {
        const chunk = this._chunks.shift();
        if (i === 0 &&
            prevOffset) {

            chunks.push(chunk.data.slice(prevOffset));
        }
        else {
            chunks.push(chunk.data);
        }
    }

    if (this._offset) {
        chunks.push(item.chunk.data.slice(dropTo ? 0 : prevOffset, this._offset));
    }

    // Recalculate existing chunks

    this.length = 0;
    for (let i = 0; i < this._chunks.length; ++i) {
        const chunk = this._chunks[i];
        chunk.offset = this.length,
        chunk.index = i;

        this.length += chunk.length;
    }

    this.length -= this._offset;

    return chunks;
};


internals.Vise.prototype.at = internals.Vise.prototype.readUInt8 = function (pos) {

    const item = this._chunkAt(pos);
    return item ? item.chunk.data[item.offset] : undefined;
};


internals.Vise.prototype._chunkAt = function (pos) {

    if (pos < 0) {
        return null;
    }

    pos = pos + this._offset;

    for (let i = 0; i < this._chunks.length; ++i) {
        const chunk = this._chunks[i];
        const offset = pos - chunk.offset;
        if (offset < chunk.length) {
            return { chunk, offset };
        }
    }

    return null;
};


internals.Vise.prototype.chunks = function () {

    const chunks = [];

    for (let i = 0; i < this._chunks.length; ++i) {
        const chunk = this._chunks[i];
        if (i === 0 &&
            this._offset) {

            chunks.push(chunk.data.slice(this._offset));
        }
        else {
            chunks.push(chunk.data);
        }
    }

    return chunks;
};


internals.Vise.prototype.startsWith = function (value, pos, length) {

    pos = pos || 0;

    length = length ? Math.min(value.length, length) : value.length;
    if (pos + length > this.length) {                                   // Not enough length to fit value
        return false;
    }

    const start = this._chunkAt(pos);
    if (!start) {
        return false;
    }

    let j = start.chunk.index;
    for (let i = 0; j < this._chunks.length && i < length; ++j) {
        const chunk = this._chunks[j];

        let k = (j === start.chunk.index ? start.offset : 0);
        for (; k < chunk.length && i < length; ++k, ++i) {
            if (chunk.data[k] !== value[i]) {
                return false;
            }
        }
    }

    return true;
};
