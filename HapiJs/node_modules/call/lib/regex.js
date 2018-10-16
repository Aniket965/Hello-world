'use strict';

// Load modules


// Declare internals

const internals = {};


exports.generate = function () {

    /*
        /path/{param}/path/{param?}
        /path/{param*2}/path
        /path/{param*2}
        /path/x{param}x
        /{param*}
    */

    const empty = '(?:^\\/$)';

    const legalChars = '[\\w\\!\\$&\'\\(\\)\\*\\+\\,;\\=\\:@\\-\\.~]';
    const encoded = '%[A-F0-9]{2}';

    const literalChar = '(?:' + legalChars + '|' + encoded + ')';
    const literal = literalChar + '+';
    const literalOptional = literalChar + '*';

    const midParam = '(?:\\{\\w+(?:\\*[1-9]\\d*)?\\})';                               // {p}, {p*2}
    const endParam = '(?:\\/(?:\\{\\w+(?:(?:\\*(?:[1-9]\\d*)?)|(?:\\?))?\\})?)?';     // {p}, {p*2}, {p*}, {p?}

    const partialParam = '(?:\\{\\w+\\??\\})';                                        // {p}, {p?}
    const mixedParam = '(?:(?:' + literal + partialParam + ')+' + literalOptional + ')|(?:' + partialParam + '(?:' + literal + partialParam + ')+' + literalOptional + ')|(?:' + partialParam + literal + ')';

    const segmentContent = '(?:' + literal + '|' + midParam + '|' + mixedParam + ')';
    const segment = '\\/' + segmentContent;
    const segments = '(?:' + segment + ')*';

    const path = '(?:^' + segments + endParam + '$)';

    //                1:literal               2:name   3:*  4:count  5:?
    const parseParam = '(' + literal + ')|(?:\\{(\\w+)(?:(\\*)(\\d+)?)?(\\?)?\\})';

    const expressions = {
        parseParam: new RegExp(parseParam, 'g'),
        validatePath: new RegExp(empty + '|' + path),
        validatePathEncoded: /%(?:2[146-9A-E]|3[\dABD]|4[\dA-F]|5[\dAF]|6[1-9A-F]|7[\dAE])/g
    };

    return expressions;
};
