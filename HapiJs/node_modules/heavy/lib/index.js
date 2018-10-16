'use strict';

// Load modules

const Boom = require('boom');
const Hoek = require('hoek');
const Joi = require('joi');


// Declare internals

const internals = {};


internals.schema = Joi.object({
    sampleInterval: Joi.number().min(0),
    maxHeapUsedBytes: Joi.number().min(0),
    maxEventLoopDelay: Joi.number().min(0),
    maxRssBytes: Joi.number().min(0)
})
    .unknown();


internals.defaults = {
    sampleInterval: 0,                          // Frequency of load sampling in milliseconds (zero is no sampling)
    maxHeapUsedBytes: 0,                        // Reject requests when V8 heap is over size in bytes (zero is no max)
    maxRssBytes: 0,                             // Reject requests when process RSS is over size in bytes (zero is no max)
    maxEventLoopDelay: 0                        // Milliseconds of delay after which requests are rejected (zero is no max)
};


exports = module.exports = internals.Heavy = function (options) {

    options = options || {};

    Joi.assert(options, internals.schema, 'Invalid load monitoring options');
    this.settings = Hoek.applyToDefaults(internals.defaults, options);
    Hoek.assert(this.settings.sampleInterval || (!this.settings.maxEventLoopDelay && !this.settings.maxHeapUsedBytes && !this.settings.maxRssBytes), 'Load sample interval must be set to enable load limits');

    this._eventLoopTimer = null;
    this._loadBench = new Hoek.Bench();
    this.load = {
        eventLoopDelay: 0,
        heapUsed: 0,
        rss: 0
    };
};


internals.Heavy.prototype.start = function () {

    if (!this.settings.sampleInterval) {
        return;
    }

    const loopSample = () => {

        this._loadBench.reset();
        const measure = () => {

            const mem = process.memoryUsage();

            // Retain the same this.load object to keep external references valid

            this.load.eventLoopDelay = (this._loadBench.elapsed() - this.settings.sampleInterval);
            this.load.heapUsed = mem.heapUsed;
            this.load.rss = mem.rss;

            loopSample();
        };

        this._eventLoopTimer = setTimeout(measure, this.settings.sampleInterval);
    };

    loopSample();
};


internals.Heavy.prototype.stop = function () {

    clearTimeout(this._eventLoopTimer);
    this._eventLoopTimer = null;
};


internals.Heavy.prototype.check = function () {

    if (!this.settings.sampleInterval) {
        return;
    }

    Hoek.assert(this._eventLoopTimer, 'Cannot check load when sampler is not started');

    const elapsed = this._loadBench.elapsed();
    const load = this.load;

    if (elapsed > this.settings.sampleInterval) {
        load.eventLoopDelay = Math.max(load.eventLoopDelay, elapsed - this.settings.sampleInterval);
    }

    if (this.settings.maxEventLoopDelay &&
        load.eventLoopDelay > this.settings.maxEventLoopDelay) {

        throw Boom.serverUnavailable('Server under heavy load (event loop)', load);
    }

    if (this.settings.maxHeapUsedBytes &&
        load.heapUsed > this.settings.maxHeapUsedBytes) {

        throw Boom.serverUnavailable('Server under heavy load (heap)', load);
    }

    if (this.settings.maxRssBytes &&
        load.rss > this.settings.maxRssBytes) {

        throw Boom.serverUnavailable('Server under heavy load (rss)', load);
    }
};
