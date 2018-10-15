'use strict';

// Load modules

const BigTime = require('big-time');
const Boom = require('boom');
const Hoek = require('hoek');


// Declare internals

const internals = {};


internals.defaults = {
    maxByteSize: 100 * 1024 * 1024,          // 100MB
    allowMixedContent: false
};


internals.MemoryCacheEntry = function MemoryCacheEntry(key, value, ttl, allowMixedContent) {

    let valueByteSize = 0;

    if (allowMixedContent && Buffer.isBuffer(value)) {
        this.item = Buffer.alloc(value.length);
        // copy buffer to prevent value from changing while in the cache
        value.copy(this.item);
        valueByteSize = this.item.length;
    }
    else {
        // stringify() to prevent value from changing while in the cache
        this.item = JSON.stringify(value);
        valueByteSize = Buffer.byteLength(this.item);
    }

    this.stored = Date.now();
    this.ttl = ttl;

    // Approximate cache entry size without value: 144 bytes
    this.byteSize = 144 + valueByteSize + Buffer.byteLength(key.segment) + Buffer.byteLength(key.id);

    this.timeoutId = null;
};


exports = module.exports = internals.Connection = class {

    constructor(options) {

        Hoek.assert(this.constructor === internals.Connection, 'Memory cache client must be instantiated using new');
        Hoek.assert(!options || options.maxByteSize === undefined || options.maxByteSize >= 0, 'Invalid cache maxByteSize value');
        Hoek.assert(!options || options.allowMixedContent === undefined || typeof options.allowMixedContent === 'boolean', 'Invalid allowMixedContent value');

        this.settings = Hoek.applyToDefaults(internals.defaults, options || {});
        this.cache = null;
    }

    start() {

        if (!this.cache) {
            this.cache = new Map();
            this.byteSize = 0;
        }
    }

    stop() {

        // Clean up pending eviction timers

        if (this.cache) {
            this.cache.forEach((segment) => {

                segment.forEach((item) => BigTime.clearTimeout(item.timeoutId));
            });
        }

        this.cache = null;
        this.byteSize = 0;
    }

    isReady() {

        return !!this.cache;
    }

    validateSegmentName(name) {

        if (!name) {
            throw new Boom('Empty string');
        }

        if (name.indexOf('\u0000') !== -1) {
            throw new Boom('Includes null character');
        }

        return null;
    }

    get(key) {

        if (!this.cache) {
            throw new Boom('Connection not started');
        }

        const segment = this.cache.get(key.segment);
        if (!segment) {
            return null;
        }

        const envelope = segment.get(key.id);

        if (!envelope) {
            return null;
        }

        let item = null;
        if (Buffer.isBuffer(envelope.item)) {
            item = envelope.item;
        }
        else {
            try {
                item = JSON.parse(envelope.item);
            }
            catch (err) {
                throw new Boom('Bad value content');
            }
        }

        const result = {
            item,
            stored: envelope.stored,
            ttl: envelope.ttl
        };

        return result;
    }

    set(key, value, ttl) {

        if (!this.cache) {
            throw new Boom('Connection not started');
        }

        const envelope = new internals.MemoryCacheEntry(key, value, ttl, this.settings.allowMixedContent);

        let segment = this.cache.get(key.segment);
        if (!segment) {
            segment = new Map();
            this.cache.set(key.segment, segment);
        }

        const cachedItem = segment.get(key.id);
        if (cachedItem &&
            cachedItem.timeoutId) {

            BigTime.clearTimeout(cachedItem.timeoutId);
            this.byteSize -= cachedItem.byteSize;                   // If the item existed, decrement the byteSize as the value could be different
        }

        if (this.settings.maxByteSize &&
            (this.byteSize + envelope.byteSize > this.settings.maxByteSize)) {

            throw new Boom('Cache size limit reached');
        }

        envelope.timeoutId = BigTime.setTimeout(() => this.drop(key), ttl);

        segment.set(key.id, envelope);
        this.byteSize += envelope.byteSize;
    }

    drop(key) {

        if (!this.cache) {
            throw new Boom('Connection not started');
        }

        const segment = this.cache.get(key.segment);
        if (segment) {
            const item = segment.get(key.id);
            if (item) {
                BigTime.clearTimeout(item.timeoutId);
                this.byteSize -= item.byteSize;
            }

            segment.delete(key.id);
        }
    }
};
