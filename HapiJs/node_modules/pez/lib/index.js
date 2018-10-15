'use strict';

// Load modules

const Stream = require('stream');

const B64 = require('b64');
const Boom = require('boom');
const Content = require('content');
const Hoek = require('hoek');
const Nigel = require('nigel');


// Declare internals

const internals = {};


/*
    RFC 2046 (http://tools.ietf.org/html/rfc2046)

    multipart-body = [preamble CRLF]
                    dash-boundary *( SPACE / HTAB ) CRLF body-part
                    *( CRLF dash-boundary *( SPACE / HTAB ) CRLF body-part )
                    CRLF dash-boundary "--" *( SPACE / HTAB )
                    [CRLF epilogue]

    boundary       = 0*69<bchars> bcharsnospace
    bchars         = bcharsnospace / " "
    bcharsnospace  = DIGIT / ALPHA / "'" / "(" / ")" / "+" / "_" / "," / "-" / "." / "/" / ":" / "=" / "?"
    dash-boundary  = "--" boundary

    preamble       = discard-text
    epilogue       = discard-text
    discard-text   = *(*text CRLF) *text

    body-part      = MIME-part-headers [CRLF *OCTET]
    OCTET          = <any 0-255 octet value>

    SPACE          = 32
    HTAB           = 9
    CRLF           = 13 10
*/


internals.state = {
    preamble: 0,                // Until the first boundary is received
    boundary: 1,                // After a boundary, waiting for first line with optional linear-whitespace
    header: 2,                  // Receiving part headers
    payload: 3,                 // Receiving part payload
    epilogue: 4
};


internals.defaults = {
    maxBytes: Infinity
};


exports.Dispenser = internals.Dispenser = function (options) {

    Stream.Writable.call(this);

    Hoek.assert(options !== null && typeof options === 'object',
        'options must be an object');
    const settings = Hoek.applyToDefaults(internals.defaults, options);

    this._boundary = settings.boundary;
    this._state = internals.state.preamble;
    this._held = '';

    this._stream = null;
    this._headers = {};
    this._name = '';
    this._pendingHeader = '';
    this._error = null;
    this._bytes = 0;
    this._maxBytes = settings.maxBytes;

    this._parts = new Nigel.Stream(Buffer.from('--' + settings.boundary));
    this._lines = new Nigel.Stream(Buffer.from('\r\n'));

    this._parts.on('needle', () => {

        this._onPartEnd();
    });

    this._parts.on('haystack', (chunk) => {

        this._onPart(chunk);
    });

    this._lines.on('needle', () => {

        this._onLineEnd();
    });

    this._lines.on('haystack', (chunk) => {

        this._onLine(chunk);
    });

    this.once('finish', () => {

        this._parts.end();
    });

    this._parts.once('close', () => {

        this._lines.end();
    });

    let piper = null;
    let finish = (err) => {

        if (piper) {
            piper.removeListener('data', onReqData);
            piper.removeListener('error', finish);
            piper.removeListener('aborted', onReqAborted);
        }

        if (err) {
            return this._abort(err);
        }

        this._emit('close');
    };

    finish = Hoek.once(finish);

    this._lines.once('close', () => {

        if (this._state === internals.state.epilogue) {
            if (this._held) {
                this._emit('epilogue', this._held);
                this._held = '';
            }
        }
        else if (this._state === internals.state.boundary) {
            if (!this._held) {
                this._abort(Boom.badRequest('Missing end boundary'));
            }
            else if (this._held !== '--') {
                this._abort(Boom.badRequest('Only white space allowed after boundary at end'));
            }
        }
        else {
            this._abort(Boom.badRequest('Incomplete multipart payload'));
        }

        setImmediate(finish);                  // Give pending events a chance to fire
    });

    const onReqAborted = () => {

        finish(Boom.badRequest('Client request aborted'));
    };

    const onReqData = (data) => {

        this._bytes += Buffer.byteLength(data);

        if (this._bytes > this._maxBytes) {
            finish(Boom.entityTooLarge('Maximum size exceeded'));
        }
    };

    this.once('pipe', (req) => {

        piper = req;
        req.on('data', onReqData);
        req.once('error', finish);
        req.once('aborted', onReqAborted);
    });
};

Hoek.inherits(internals.Dispenser, Stream.Writable);


internals.Dispenser.prototype._write = function (buffer, encoding, next) {

    if (this._error) {
        return next();
    }

    this._parts.write(buffer);
    return next();
};


internals.Dispenser.prototype._emit = function () {

    if (this._error) {
        return;
    }

    this.emit.apply(this, arguments);
};


internals.Dispenser.prototype._abort = function (err) {

    this._emit('error', err);
    this._error = err;
};


internals.Dispenser.prototype._onPartEnd = function () {

    this._lines.flush();

    if (this._state === internals.state.preamble) {
        if (this._held) {
            const last = this._held.length - 1;

            if (this._held[last] !== '\n' ||
                this._held[last - 1] !== '\r') {

                return this._abort(Boom.badRequest('Preamble missing CRLF terminator'));
            }

            this._emit('preamble', this._held.slice(0, -2));
            this._held = '';
        }

        this._parts.needle(Buffer.from('\r\n--' + this._boundary));                      // CRLF no longer optional
    }

    this._state = internals.state.boundary;

    if (this._stream) {
        this._stream.end();
        this._stream = null;
    }
    else if (this._name) {
        this._emit('field', this._name, this._held);
        this._name = '';
        this._held = '';
    }
};


internals.Dispenser.prototype._onPart = function (chunk) {

    if (this._state === internals.state.preamble) {
        this._held = this._held + chunk.toString();
    }
    else if (this._state === internals.state.payload) {
        if (this._stream) {
            this._stream.write(chunk);                                                 // Stream payload
        }
        else {
            this._held = this._held + chunk.toString();
        }
    }
    else {
        this._lines.write(chunk);                                                       // Look for boundary
    }
};


internals.Dispenser.prototype._onLineEnd = function () {

    // Boundary whitespace

    if (this._state === internals.state.boundary) {
        if (this._held) {
            this._held = this._held.replace(/[\t ]/g, '');                                // trim() removes new lines
            if (this._held) {
                if (this._held === '--') {
                    this._state = internals.state.epilogue;
                    this._held = '';

                    return;
                }

                return this._abort(Boom.badRequest('Only white space allowed after boundary'));
            }
        }

        this._state = internals.state.header;

        return;
    }

    // Part headers

    if (this._state === internals.state.header) {

        // Header

        if (this._held) {

            // Header continuation

            if (this._held[0] === ' ' ||
                this._held[0] === '\t') {

                if (!this._pendingHeader) {
                    return this._abort(Boom.badRequest('Invalid header continuation without valid declaration on previous line'));
                }

                this._pendingHeader = this._pendingHeader + ' ' + this._held.slice(1);                       // Drop tab
                this._held = '';
                return;
            }

            // Start of new header

            this._flushHeader();
            this._pendingHeader = this._held;
            this._held = '';

            return;
        }

        // End of headers

        this._flushHeader();

        this._state = internals.state.payload;

        let disposition;

        try {
            disposition = Content.disposition(this._headers['content-disposition']);
        }
        catch (err) {
            return this._abort(err);
        }

        if (disposition.filename !== undefined) {
            const stream = new Stream.PassThrough();
            const transferEncoding = this._headers['content-transfer-encoding'];

            if (transferEncoding &&
                transferEncoding.toLowerCase() === 'base64') {

                this._stream = new B64.Decoder();
                this._stream.pipe(stream);
            }
            else {
                this._stream = stream;
            }

            stream.name = disposition.name;
            stream.filename = disposition.filename;
            stream.headers = this._headers;
            this._headers = {};
            this._emit('part', stream);
        }
        else {
            this._name = disposition.name;
        }

        this._lines.flush();
        return;
    }

    // Epilogue

    this._held = this._held + '\r\n';                               // Put the new line back
};


internals.Dispenser.prototype._onLine = function (chunk) {

    if (this._stream) {
        this._stream.write(chunk);                      // Stream payload
    }
    else {
        this._held = this._held + chunk.toString();                 // Reading header or field
    }
};


internals.Dispenser.prototype._flushHeader = function () {

    if (!this._pendingHeader) {
        return;
    }

    const sep = this._pendingHeader.indexOf(':');

    if (sep === -1) {
        return this._abort(Boom.badRequest('Invalid header missing colon separator'));
    }

    if (!sep) {
        return this._abort(Boom.badRequest('Invalid header missing field name'));
    }

    this._headers[this._pendingHeader.slice(0, sep).toLowerCase()] = this._pendingHeader.slice(sep + 1).trim();
    this._pendingHeader = '';
};
