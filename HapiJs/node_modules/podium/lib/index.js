'use strict';

// Load modules

const Hoek = require('hoek');
const Joi = require('joi');


// Declare internals

const internals = {
    schema: {
        base: Joi.object({
            name: Joi.string().required(),
            clone: Joi.boolean(),
            tags: Joi.boolean(),
            spread: Joi.boolean(),
            channels: Joi.array().items(Joi.string()).single().unique().min(1)
        })
    }
};


internals.schema.event = internals.schema.base.keys({
    shared: Joi.boolean()
});


internals.schema.listener = internals.schema.event.keys({
    listener: Joi.func().required(),
    count: Joi.number().integer().min(1),
    filter: {
        tags: Joi.array().items(Joi.string()).single().unique().min(1).required(),
        all: Joi.boolean()
    }
});


exports = module.exports = internals.Podium = function (events, options) {

    // Use descriptive names to avoid conflict when inherited

    this._eventListeners = Object.create(null);
    this._notificationsQueue = [];
    this._eventsProcessing = false;
    this._sourcePodiums = [];

    if (events) {
        this.registerEvent(events, options);
    }
};


internals.Podium.decorate = function (target, source) {

    internals.Podium.call(target, null);

    Object.keys(source._eventListeners).forEach((name) => {

        target._eventListeners[name] = {
            handlers: null,
            flags: source._eventListeners[name].flags
        };
    });
};


internals.Podium.validate = function (events) {

    const normalized = [];
    [].concat(events).forEach((event) => {

        if (typeof event === 'string') {
            event = { name: event };
        }

        normalized.push(Joi.attempt(event, internals.schema.event, 'Invalid event options'));
    });

    return normalized;
};


internals.Podium.prototype.registerEvent = function (events, options = {}) {

    events = Hoek.flatten([].concat(events));
    events.forEach((event) => {

        if (!event) {
            return;
        }

        if (event instanceof internals.Podium) {
            return this.registerPodium(event);
        }

        if (typeof event === 'string') {
            event = { name: event };
        }

        if (options.validate !== false) {                                                       // Defaults to true
            event = Joi.attempt(event, internals.schema.event, 'Invalid event options');
        }

        const name = event.name;
        if (this._eventListeners[name]) {
            Hoek.assert(event.shared, `Event ${name} exists`);
            return;
        }

        this._eventListeners[name] = { handlers: null, flags: event };
        this._sourcePodiums.forEach((podium) => {

            if (!podium._eventListeners[name]) {
                podium._eventListeners[name] = { handlers: null, flags: event };
            }
        });
    });
};


internals.Podium.prototype.registerPodium = function (podiums) {

    [].concat(podiums).forEach((podium) => {

        if (podium._sourcePodiums.indexOf(this) !== -1) {
            return;
        }

        podium._sourcePodiums.push(this);
        Object.keys(podium._eventListeners).forEach((name) => {

            if (!this._eventListeners[name]) {
                this._eventListeners[name] = { handlers: null, flags: podium._eventListeners[name].flags };
            }
        });
    });
};


internals.Podium.prototype.emit = async function (criteria, data, _generated) {

    criteria = internals.criteria(criteria);

    const name = criteria.name;
    Hoek.assert(name, 'Criteria missing event name');

    const event = this._eventListeners[name];
    Hoek.assert(event, `Unknown event ${name}`);
    Hoek.assert(!criteria.channel || typeof criteria.channel === 'string', 'Invalid channel name');
    Hoek.assert(!criteria.channel || !event.flags.channels || event.flags.channels.indexOf(criteria.channel) !== -1, `Unknown ${criteria.channel} channel`);
    Hoek.assert(!event.flags.spread || Array.isArray(data) || typeof data === 'function', 'Data must be an array for spread event');

    if (!event.handlers &&
        !this._sourcePodiums.length) {

        return;
    }

    if (typeof criteria.tags === 'string') {
        criteria.tags = [criteria.tags];
    }

    if (criteria.tags &&
        Array.isArray(criteria.tags)) {

        criteria.tags = Hoek.mapToObject(criteria.tags);
    }

    if (event.handlers) {
        const processing = [];

        const handlers = event.handlers.slice();                // Clone in case handlers are changed by listeners
        for (let i = 0; i < handlers.length; ++i) {
            const handler = handlers[i];

            if (handler.channels &&
                (!criteria.channel || handler.channels.indexOf(criteria.channel) === -1)) {

                continue;
            }

            if (handler.filter) {
                if (!criteria.tags) {
                    continue;
                }

                const match = Hoek.intersect(criteria.tags, handler.filter.tags, !handler.filter.all);
                if (!match ||
                    (handler.filter.all && match.length !== handler.filter.tags.length)) {

                    continue;
                }
            }

            if (handler.count) {
                --handler.count;
                if (handler.count < 1) {
                    internals.removeHandler(this, criteria.name, handler);
                }
            }

            if (!_generated &&
                typeof data === 'function') {

                data = data();
                _generated = true;
            }

            const update = (internals.flag('clone', handler, event) ? Hoek.clone(data) : data);
            const args = (internals.flag('spread', handler, event) && Array.isArray(update) ? update : [update]);

            if (internals.flag('tags', handler, event) &&
                criteria.tags) {

                args.push(criteria.tags);
            }

            try {
                const result = handler.listener.apply(null, args);
                if (result &&
                    typeof result.then === 'function') {

                    processing.push(result);
                }
            }
            catch (err) {
                processing.push(Promise.reject(err));
            }
        }

        if (processing.length) {
            await Promise.all(processing);
        }
    }

    if (this._sourcePodiums.length) {
        const podiums = this._sourcePodiums.slice();         // Clone in case modified while processing
        await Promise.all(podiums.map((podium) => podium.emit(criteria, data, _generated)));
    }
};


internals.Podium.prototype.on = internals.Podium.prototype.addListener = function (criteria, listener) {

    criteria = internals.criteria(criteria);
    criteria.listener = listener;

    if (criteria.filter &&
        (typeof criteria.filter === 'string' || Array.isArray(criteria.filter))) {

        criteria.filter = { tags: criteria.filter };
    }

    criteria = Joi.attempt(criteria, internals.schema.listener, 'Invalid event listener options');

    const name = criteria.name;
    const event = this._eventListeners[name];
    Hoek.assert(event, `Unknown event ${name}`);
    Hoek.assert(!criteria.channels || !event.flags.channels || Hoek.intersect(event.flags.channels, criteria.channels).length === criteria.channels.length, `Unknown event channels ${criteria.channels && criteria.channels.join(', ')}`);

    this._eventListeners[name].handlers = this._eventListeners[name].handlers || [];
    this._eventListeners[name].handlers.push(criteria);

    return this;
};


internals.Podium.prototype.once = function (criteria, listener) {

    criteria = Object.assign(internals.criteria(criteria), { count: 1 });

    if (listener) {
        return this.on(criteria, listener);
    }

    return new Promise((resolve) => this.on(criteria, (...args) => resolve(args)));
};


internals.Podium.prototype.removeListener = function (name, listener) {

    Hoek.assert(this._eventListeners[name], `Unknown event ${name}`);
    Hoek.assert(typeof listener === 'function', 'Listener must be a function');

    const handlers = this._eventListeners[name].handlers;
    if (!handlers) {
        return this;
    }

    const filtered = handlers.filter((handler) => handler.listener !== listener);
    this._eventListeners[name].handlers = (filtered.length ? filtered : null);
    return this;
};


internals.Podium.prototype.removeAllListeners = function (name) {

    Hoek.assert(this._eventListeners[name], `Unknown event ${name}`);
    this._eventListeners[name].handlers = null;
    return this;
};


internals.Podium.prototype.hasListeners = function (name) {

    Hoek.assert(this._eventListeners[name], `Unknown event ${name}`);
    return !!this._eventListeners[name].handlers;
};


internals.removeHandler = function (emitter, name, handler) {

    const handlers = emitter._eventListeners[name].handlers;
    const filtered = handlers.filter((item) => item !== handler);
    emitter._eventListeners[name].handlers = (filtered.length ? filtered : null);
};


internals.criteria = function (criteria) {

    return (typeof criteria === 'string' ? { name: criteria } : Hoek.clone(criteria));
};


internals.flag = function (name, handler, event) {

    return (handler[name] !== undefined ? handler[name] : event.flags[name]) || false;
};
