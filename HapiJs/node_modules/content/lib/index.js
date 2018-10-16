'use strict';

// Load modules

const Boom = require('boom');


// Declare internals

const internals = {};


/*
    RFC 7231 Section 3.1.1.1

    media-type = type "/" subtype *( OWS ";" OWS parameter )
    type       = token
    subtype    = token
    parameter  = token "=" ( token / quoted-string )
*/

//                             1: type/subtype    2: params
internals.contentTypeRegex = /^([^\/\s]+\/[^\s;]+)(.*)?$/;

//                                        1: "b"   2: b
internals.paramsRegex = /;\s*boundary=(?:"([^"]+)"|([^;"\s]+))/i;


exports.type = function (header) {

    if (!header) {
        throw Boom.badRequest('Invalid content-type header');
    }

    const match = header.match(internals.contentTypeRegex);
    if (!match) {
        throw Boom.badRequest('Invalid content-type header');
    }

    const result = {
        mime: match[1].toLowerCase()
    };

    if (result.mime.indexOf('multipart/') === 0) {
        const params = match[2];
        if (params) {
            const param = params.match(internals.paramsRegex);
            if (param) {
                result.boundary = param[1] || param[2];
            }
        }

        if (!result.boundary) {
            throw Boom.badRequest('Invalid content-type header: multipart missing boundary');
        }
    }

    return result;
};


/*
    RFC 6266 Section 4.1 (http://tools.ietf.org/html/rfc6266#section-4.1)

    content-disposition = "Content-Disposition" ":" disposition-type *( ";" disposition-parm )
    disposition-type    = "inline" | "attachment" | token                                           ; case-insensitive
    disposition-parm    = filename-parm | token [ "*" ] "=" ( token | quoted-string | ext-value)    ; ext-value defined in [RFC5987], Section 3.2

    Content-Disposition header field values with multiple instances of the same parameter name are invalid.

    Note that due to the rules for implied linear whitespace (Section 2.1 of [RFC2616]), OPTIONAL whitespace
    can appear between words (token or quoted-string) and separator characters.

    Furthermore, note that the format used for ext-value allows specifying a natural language (e.g., "en"); this is of limited use
    for filenames and is likely to be ignored by recipients.
*/


internals.contentDispositionRegex = /^\s*form-data\s*(?:;\s*(.+))?$/i;

//                                        1: name     2: *            3: ext-value                      4: quoted  5: token
internals.contentDispositionParamRegex = /([^\=\*\s]+)(\*)?\s*\=\s*(?:([^;'"\s]+\'[\w-]*\'[^;\s]+)|(?:\"([^"]*)\")|([^;\s]*))(?:\s*(?:;\s*)|$)/g;

exports.disposition = function (header) {

    if (!header) {
        throw Boom.badRequest('Missing content-disposition header');
    }

    const match = header.match(internals.contentDispositionRegex);
    if (!match) {
        throw Boom.badRequest('Invalid content-disposition header format');
    }

    const parameters = match[1];
    if (!parameters) {
        throw Boom.badRequest('Invalid content-disposition header missing parameters');
    }

    const result = {};
    parameters.replace(internals.contentDispositionParamRegex, ($0, $1, $2, $3, $4, $5) => {

        if ($2) {
            if (!$3) {
                throw Boom.badRequest('Invalid content-disposition header format includes invalid parameters');
            }

            try {
                result[$1] = decodeURIComponent($3.split('\'')[2]);
            }
            catch (err) {
                throw Boom.badRequest('Invalid content-disposition header format includes invalid parameters');
            }
        }
        else {
            result[$1] = $4 || $5 || '';
        }
    });

    if (!result.name) {
        throw Boom.badRequest('Invalid content-disposition header missing name parameter');
    }

    return result;
};
