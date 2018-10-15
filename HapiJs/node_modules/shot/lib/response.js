'use strict';

// Load modules

const Http = require('http');
const Stream = require('stream');

const Symbols = require('./symbols');


// Declare internals

const internals = {};


exports = module.exports = internals.Response = class extends Http.ServerResponse {

    constructor(req, onEnd) {

        super({ method: req.method, httpVersionMajor: 1, httpVersionMinor: 1 });
        this._shot = { headers: null, trailers: {}, payloadChunks: [] };
        this._headers = {};      // This forces node@8 to always render the headers
        this.assignSocket(internals.nullSocket());

        this.once('finish', () => {

            const res = internals.payload(this);
            res.raw.req = req;
            process.nextTick(() => onEnd(res));
        });
    }

    writeHead() {

        const result = super.writeHead.apply(this, arguments);

        this._shot.headers = Object.assign({}, this._headers);       // Should be .getHeaders() since node v7.7

        // Add raw headers

        ['Date', 'Connection', 'Transfer-Encoding'].forEach((name) => {

            const regex = new RegExp('\\r\\n' + name + ': ([^\\r]*)\\r\\n');
            const field = this._header.match(regex);
            if (field) {
                this._shot.headers[name.toLowerCase()] = field[1];
            }
        });

        return result;
    }

    write(data, encoding, callback) {

        super.write(data, encoding, callback);
        this._shot.payloadChunks.push(new Buffer(data, encoding));
        return true;                                                    // Write always returns false when disconnected
    }

    end(data, encoding, callback) {

        if (data) {
            this.write(data, encoding);
        }

        super.end(callback);
        this.emit('finish');
    }

    destroy() {

    }

    addTrailers(trailers) {

        for (const key in trailers) {
            this._shot.trailers[key.toLowerCase().trim()] = trailers[key].toString().trim();
        }
    }
};


internals.Response.prototype[Symbols.injection] = true;


internals.payload = function (response) {

    // Prepare response object

    const res = {
        raw: {
            res: response
        },
        headers: response._shot.headers,
        statusCode: response.statusCode,
        statusMessage: response.statusMessage,
        trailers: {}
    };

    // Prepare payload and trailers

    const rawBuffer = Buffer.concat(response._shot.payloadChunks);
    res.rawPayload = rawBuffer;
    res.payload = rawBuffer.toString();
    res.trailers = response._shot.trailers;

    return res;
};


// Throws away all written data to prevent response from buffering payload

internals.nullSocket = function () {

    return new Stream.Writable({
        write(chunk, encoding, callback) {

            setImmediate(callback);
        }
    });
};
