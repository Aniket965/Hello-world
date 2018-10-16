'use strict';

// Load modules

const Hoek = require('hoek');


// Declare internals

const internals = {};


// https://tools.ietf.org/html/rfc7231#section-5.3.5
// Accept-Language: da, en-gb;q=0.8, en;q=0.7


exports.language = function (header, preferences) {

    Hoek.assert(!preferences || Array.isArray(preferences), 'Preferences must be an array');
    const languages = exports.languages(header);

    if (languages.length === 0) {
        languages.push('');
    }

    // No preferences.  Take the first charset.

    if (!preferences || preferences.length === 0) {
        return languages[0];
    }

    // If languages includes * return first preference

    if (languages.indexOf('*') !== -1) {
        return preferences[0];
    }

    // Try to find the first match in the array of preferences

    preferences = preferences.map((str) => str.toLowerCase());

    for (let i = 0; i < languages.length; ++i) {
        if (preferences.indexOf(languages[i].toLowerCase()) !== -1) {
            return languages[i];
        }
    }

    return '';
};


exports.languages = function (header) {

    if (header === undefined || typeof header !== 'string') {
        return [];
    }

    return header
        .split(',')
        .map(internals.getParts)
        .filter(internals.removeUnwanted)
        .sort(internals.compareByWeight)
        .map(internals.partToLanguage);
};


internals.getParts = function (item) {

    const result = {
        weight: 1,
        language: ''
    };

    const match = item.match(internals.partsRegex);
    if (!match) {
        return result;
    }

    result.language = match[1];
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


internals.removeUnwanted = function (item) {

    return item.weight !== 0 && item.language !== '';
};


internals.compareByWeight = function (a, b) {

    return a.weight < b.weight;
};


internals.partToLanguage = function (item) {

    return item.language;
};


internals.isNumber = function (n) {

    return !isNaN(parseFloat(n));
};
