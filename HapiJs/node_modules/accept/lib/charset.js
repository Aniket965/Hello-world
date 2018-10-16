'use strict';

// Load modules

const Hoek = require('hoek');


// Declare internals

const internals = {};


// From https://tools.ietf.org/html/rfc7231#section-5.3.3
// Accept-Charset: iso-8859-5, unicode-1-1;q=0.8

exports.charset = function (header, preferences) {

    Hoek.assert(!preferences || Array.isArray(preferences), 'Preferences must be an array');
    const charsets = header
        .split(',')
        .map(internals.getParts)
        .filter(internals.removeEmpty)
        .sort(internals.compareByWeight);

    // Tack on a default return

    charsets.push({
        weight: 0.001,
        charset: ''
    });

    // No preferences.  Take the first non-disallowed charset

    if (!preferences || preferences.length === 0) {
        return charsets.filter(internals.removeDisallowed)[0].charset;
    }

    // Lower case all preferences

    preferences = preferences.map(internals.lowerCase);

    // Remove any disallowed preferences

    internals.removeDisallowedPreferences(charsets, preferences);

    // If charsets includes * (that isn't disallowed *;q=0) return first preference

    const splatLocation = internals.findCharsetItem(charsets, '*');
    if (splatLocation !== -1 && charsets[splatLocation].weight > 0) {
        return preferences[0];
    }

    // Try to find the first match in the array of preferences, ignoring case

    for (let i = 0; i < charsets.length; ++i) {
        if (preferences.indexOf(charsets[i].charset.toLowerCase()) !== -1 && charsets[i].weight > 0) {
            return charsets[i].charset;
        }
    }

    return '';
};


exports.charsets = function (header) {

    if (header === undefined || typeof header !== 'string') {
        return [];
    }

    header = header.toLowerCase();

    return header
        .split(',')
        .map(internals.getParts)
        .filter(internals.removeEmptyAndDisallowed)
        .sort(internals.compareByWeight)
        .map(internals.partToCharset);
};


internals.getParts = function (item) {

    const result = {
        weight: 1,
        charset: ''
    };

    const match = item.match(internals.partsRegex);
    if (!match) {
        return result;
    }

    result.charset = match[1];
    if (match[2] && internals.isNumber(match[2])) {
        const weight = parseFloat(match[2]);
        if (weight === 0 || (weight >= 0.001 && weight <= 1)) {
            result.weight = weight;
        }
    }
    return result;
};

//                         1: token               2: qvalue
internals.partsRegex = /\s*([^;]+)(?:\s*;\s*[qQ]\=([01](?:\.\d*)?))?\s*/;


internals.removeEmpty = function (item) {

    return item.charset !== '';
};


internals.removeDisallowed = function (item) {

    return item.weight !== 0;
};


internals.removeEmptyAndDisallowed = function (item) {

    return item.charset !== '' && item.weight !== 0;
};


internals.removeDisallowedPreferences = function (charsets, preferences) {

    for (let i = 0; i < charsets.length; ++i) {
        let location;
        if (charsets[i].weight === 0) {
            location = preferences.indexOf(charsets[i].charset.toLowerCase());
            if (location !== -1) {
                preferences.splice(location, 1);
            }
        }
    }
};


internals.compareByWeight = function (a, b) {

    return a.weight < b.weight;
};


internals.partToCharset = function (item) {

    return item.charset;
};


internals.isNumber = function (n) {

    return !isNaN(parseFloat(n));
};


internals.lowerCase = function (str) {

    return str.toLowerCase();
};


internals.findCharsetItem = function (charsets, charset) {

    for (let i = 0; i < charsets.length; ++i) {
        if (charsets[i].charset === charset) {
            return i;
        }
    }

    return -1;
};
