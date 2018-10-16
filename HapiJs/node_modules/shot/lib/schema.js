'use strict';

const Joi = require('joi');


const internals = {};


internals.url = Joi.alternatives(Joi.string().required(), Joi.object().keys({
    protocol: Joi.string(),
    hostname: Joi.string(),
    port: Joi.any(),
    pathname: Joi.string().required(),
    query: Joi.any()
}).required());


internals.options = Joi.object().keys({
    url: internals.url.required(),
    headers: Joi.object(),
    payload: Joi.any(),
    simulate: Joi.object().keys({
        end: Joi.boolean(),
        split: Joi.boolean(),
        error: Joi.boolean(),
        close: Joi.boolean()
    }),
    authority: Joi.string(),
    remoteAddress: Joi.string(),
    method: Joi.string().regex(/^[a-zA-Z0-9!#\$%&'\*\+\-\.^_`\|~]+$/)
}).min(1);


module.exports = Joi.object().keys({
    dispatchFunc: Joi.func().required(),
    options: Joi.alternatives(internals.options, internals.url).required(),
    callback: Joi.func()
});
