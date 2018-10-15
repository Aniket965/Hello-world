'use strict';

// Load modules

const Charset = require('./charset');
const Encoding = require('./encoding');
const Language = require('./language');
const MediaType = require('./mediatype');


// Declare internals

const internals = {};


exports.charset = Charset.charset;
exports.charsets = Charset.charsets;

exports.encoding = Encoding.encoding;
exports.encodings = Encoding.encodings;

exports.language = Language.language;
exports.languages = Language.languages;

exports.mediaTypes = MediaType.mediaTypes;

exports.parseAll = function (requestHeaders) {

    return {
        charsets: Charset.charsets(requestHeaders['accept-charset']),
        encodings: Encoding.encodings(requestHeaders['accept-encoding']),
        languages: Language.languages(requestHeaders['accept-language']),
        mediaTypes: MediaType.mediaTypes(requestHeaders.accept)
    };
};
