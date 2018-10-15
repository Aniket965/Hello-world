'use strict';

// Load modules


// Declare internals

const internals = {};


// Accept: audio/*; q=0.2, audio/basic
// text/plain; q=0.5, text/html, text/x-dvi; q=0.8, text/x-c
// text/plain, application/json;q=0.5, text/html, */*;q=0.1
// text/plain, application/json;q=0.5, text/html, text/drop;q=0
// text/*, text/plain, text/plain;format=flowed, */*
// text/*;q=0.3, text/html;q=0.7, text/html;level=1, text/html;level=2;q=0.4, */*;q=0.5

exports.mediaTypes = function (header) {

    if (header === undefined || typeof header !== 'string') {
        return ['*/*'];
    }

    return header
        .split(',')
        .map(internals.getParts)
        .filter(internals.removeEmptyAndDisallowed)
        .sort(internals.compareByWeightAndSpecificity)
        .map(internals.partToMediaType);
};


internals.getParts = function (item) {

    const result = {
        weight: 1,
        mediaType: ''
    };

    const match = item.match(internals.partsRegex);

    if (!match) {
        return result;
    }

    result.mediaType = match[1];
    if (match[2] && internals.isNumber(match[2])) {
        const weight = parseFloat(match[2]);
        if (weight === 0 || (weight >= 0.001 && weight <= 1)) {
            result.weight = weight;
        }
    }
    return result;
};


//                         1: token              2: qvalue
internals.partsRegex = /\s*(.+\/.+?)(?:\s*;\s*[qQ]\=([01](?:\.\d*)?))?\s*$/;


internals.removeEmptyAndDisallowed = function (item) {

    return item.mediaType !== '' && item.weight !== 0;
};


internals.compareByWeightAndSpecificity = function (a, b) {

    if (a.weight !== b.weight) {
        return a.weight < b.weight;
    }

    // We have the same weight, so now look for specificity
    const aSlashParts = a.mediaType.split('/');
    const bSlashParts = b.mediaType.split('/');

    if (aSlashParts[0] !== bSlashParts[0]) {
        // First part of items are different so no
        // further specificity is implied.
        // Don't change order.
        return 0;
    }

    if (aSlashParts[1] !== '*' && bSlashParts[1] === '*') {
        return -1;
    }
    if (aSlashParts[1] === '*' && bSlashParts[1] !== '*') {
        return 1;
    }

    // look for items with extensions
    const aHasExtension = aSlashParts[1].indexOf(';') !== -1;
    const bHasExtension = bSlashParts[1].indexOf(';') !== -1;
    if (aHasExtension) {
        return -1;
    }
    else if (bHasExtension) {
        return 1;
    }

    return 0;
};


internals.partToMediaType = function (item) {

    return item.mediaType;
};


internals.isNumber = function (n) {

    return !isNaN(parseFloat(n));
};
