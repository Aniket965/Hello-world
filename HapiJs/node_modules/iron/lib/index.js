'use strict';

// Load modules

const Crypto = require('crypto');

const Boom = require('boom');
const Hoek = require('hoek');
const Cryptiles = require('cryptiles');


// Declare internals

const internals = {};


// Common defaults

exports.defaults = {
    encryption: {
        saltBits: 256,
        algorithm: 'aes-256-cbc',
        iterations: 1,
        minPasswordlength: 32
    },

    integrity: {
        saltBits: 256,
        algorithm: 'sha256',
        iterations: 1,
        minPasswordlength: 32
    },

    ttl: 0,                                             // Milliseconds, 0 means forever
    timestampSkewSec: 60,                               // Seconds of permitted clock skew for incoming expirations
    localtimeOffsetMsec: 0                              // Local clock time offset express in a number of milliseconds (positive or negative)
};


// Algorithm configuration

exports.algorithms = {
    'aes-128-ctr': { keyBits: 128, ivBits: 128 },       // Requires node 0.10.x
    'aes-256-cbc': { keyBits: 256, ivBits: 128 },
    'sha256': { keyBits: 256 }
};


// MAC normalization format version

exports.macFormatVersion = '2';                         // Prevent comparison of mac values generated with different normalized string formats
exports.macPrefix = 'Fe26.' + exports.macFormatVersion;


// Generate a unique encryption key

/*
    const options =  {
        saltBits: 256,                                  // Ignored if salt is set
        salt: '4d8nr9q384nr9q384nr93q8nruq9348run',
        algorithm: 'aes-128-ctr',
        iterations: 10000,
        iv: 'sdfsdfsdfsdfscdrgercgesrcgsercg',          // Optional
        minPasswordlength: 32
    };
*/

exports.generateKey = async function (password, options) {

    if (!password) {
        throw new Boom('Empty password');
    }

    if (!options ||
        typeof options !== 'object') {

        throw new Boom('Bad options');
    }

    const algorithm = exports.algorithms[options.algorithm];
    if (!algorithm) {
        throw new Boom('Unknown algorithm: ' + options.algorithm);
    }

    const result = {};

    if (Buffer.isBuffer(password)) {
        if (password.length < algorithm.keyBits / 8) {
            throw new Boom('Key buffer (password) too small');
        }

        result.key = password;
        result.salt = '';
    }
    else {
        if (password.length < options.minPasswordlength) {
            throw new Boom('Password string too short (min ' + options.minPasswordlength + ' characters required)');
        }

        let salt = options.salt;
        if (!salt) {
            if (!options.saltBits) {
                throw new Boom('Missing salt or saltBits options');
            }

            const randomSalt = Cryptiles.randomBits(options.saltBits);
            salt = randomSalt.toString('hex');
        }

        const derivedKey = await internals.pbkdf2(password, salt, options.iterations, algorithm.keyBits / 8, 'sha1');

        result.key = derivedKey;
        result.salt = salt;
    }

    if (algorithm.ivBits &&
        !options.iv) {

        const randomIv = Cryptiles.randomBits(algorithm.ivBits);
        result.iv = randomIv;
    }
    else if (options.iv) {
        result.iv = options.iv;
    }

    return result;
};


// Encrypt data
// options: see exports.generateKey()

exports.encrypt = async function (password, options, data) {

    const key = await exports.generateKey(password, options);
    const cipher = Crypto.createCipheriv(options.algorithm, key.key, key.iv);
    const encrypted = Buffer.concat([cipher.update(data, 'utf8'), cipher.final()]);

    return { encrypted, key };
};


// Decrypt data
// options: see exports.generateKey()

exports.decrypt = async function (password, options, data) {

    const key = await exports.generateKey(password, options);
    const decipher = Crypto.createDecipheriv(options.algorithm, key.key, key.iv);
    let dec = decipher.update(data, null, 'utf8');
    dec = dec + decipher.final('utf8');

    return dec;
};


// HMAC using a password
// options: see exports.generateKey()

exports.hmacWithPassword = async function (password, options, data) {

    const key = await exports.generateKey(password, options);
    const hmac = Crypto.createHmac(options.algorithm, key.key).update(data);
    const digest = hmac.digest('base64').replace(/\+/g, '-').replace(/\//g, '_').replace(/\=/g, '');

    const result = {
        digest,
        salt: key.salt
    };

    return result;
};


// Normalizes a password parameter into a { id, encryption, integrity } object
// password: string, buffer or object with { id, secret } or { id, encryption, integrity }

internals.normalizePassword = function (password) {

    const obj = {};

    if (password instanceof Object &&
        !Buffer.isBuffer(password)) {

        obj.id = password.id;
        obj.encryption = password.secret || password.encryption;
        obj.integrity = password.secret || password.integrity;
    }
    else {
        obj.encryption = password;
        obj.integrity = password;
    }

    return obj;
};


// Encrypt and HMAC an object
// password: string, buffer or object with { id, secret } or { id, encryption, integrity }
// options: see exports.defaults

exports.seal = async function (object, password, options) {

    const now = Date.now() + (options.localtimeOffsetMsec || 0);                 // Measure now before any other processing

    // Serialize object

    const objectString = internals.stringify(object);

    // Obtain password

    let passwordId = '';
    password = internals.normalizePassword(password);
    if (password.id) {
        if (!/^\w+$/.test(password.id)) {
            throw new Boom('Invalid password id');
        }

        passwordId = password.id;
    }

    // Encrypt object string

    const { encrypted, key } = await exports.encrypt(password.encryption, options.encryption, objectString);

    // Base64url the encrypted value

    const encryptedB64 = Hoek.base64urlEncode(encrypted);
    const iv = Hoek.base64urlEncode(key.iv);
    const expiration = (options.ttl ? now + options.ttl : '');
    const macBaseString = exports.macPrefix + '*' + passwordId + '*' + key.salt + '*' + iv + '*' + encryptedB64 + '*' + expiration;

    // Mac the combined values

    const mac = await exports.hmacWithPassword(password.integrity, options.integrity, macBaseString);

    // Put it all together

    // prefix*[password-id]*encryption-salt*encryption-iv*encrypted*[expiration]*hmac-salt*hmac
    // Allowed URI query name/value characters: *-. \d \w

    const sealed = macBaseString + '*' + mac.salt + '*' + mac.digest;
    return sealed;
};


// Decrypt and validate sealed string
// password: string, buffer or object with { id: secret } or { id: { encryption, integrity } }
// options: see exports.defaults

exports.unseal = async function (sealed, password, options) {

    const now = Date.now() + (options.localtimeOffsetMsec || 0);                 // Measure now before any other processing

    // Break string into components

    const parts = sealed.split('*');
    if (parts.length !== 8) {
        throw new Boom('Incorrect number of sealed components');
    }

    const macPrefix = parts[0];
    const passwordId = parts[1];
    const encryptionSalt = parts[2];
    const encryptionIv = parts[3];
    const encryptedB64 = parts[4];
    const expiration = parts[5];
    const hmacSalt = parts[6];
    const hmac = parts[7];
    const macBaseString = macPrefix + '*' + passwordId + '*' + encryptionSalt + '*' + encryptionIv + '*' + encryptedB64 + '*' + expiration;

    // Check prefix

    if (macPrefix !== exports.macPrefix) {
        throw new Boom('Wrong mac prefix');
    }

    // Check expiration

    if (expiration) {
        if (!expiration.match(/^\d+$/)) {
            throw new Boom('Invalid expiration');
        }

        const exp = parseInt(expiration, 10);
        if (exp <= (now - (options.timestampSkewSec * 1000))) {
            throw new Boom('Expired seal');
        }
    }

    // Obtain password

    if (password instanceof Object &&
        !(Buffer.isBuffer(password))) {

        password = password[passwordId || 'default'];
        if (!password) {
            throw new Boom('Cannot find password: ' + passwordId);
        }
    }
    password = internals.normalizePassword(password);

    // Check hmac

    const macOptions = Hoek.clone(options.integrity);
    macOptions.salt = hmacSalt;
    const mac = await exports.hmacWithPassword(password.integrity, macOptions, macBaseString);

    if (!Cryptiles.fixedTimeComparison(mac.digest, hmac)) {
        throw new Boom('Bad hmac value');
    }

    // Decrypt

    try {
        var encrypted = Hoek.base64urlDecode(encryptedB64, 'buffer');
    }
    catch (err) {
        throw Boom.boomify(err);
    }

    const decryptOptions = Hoek.clone(options.encryption);
    decryptOptions.salt = encryptionSalt;

    try {
        decryptOptions.iv = Hoek.base64urlDecode(encryptionIv, 'buffer');
    }
    catch (err) {
        throw Boom.boomify(err);
    }

    const decrypted = await exports.decrypt(password.encryption, decryptOptions, encrypted);

    // Parse JSON

    let object = null;
    try {
        object = JSON.parse(decrypted);
    }
    catch (err) {
        throw new Boom('Failed parsing sealed object JSON: ' + err.message);
    }

    return object;
};


internals.stringify = function (object) {

    try {
        return JSON.stringify(object);
    }
    catch (err) {
        throw new Boom('Failed to stringify object: ' + err.message);
    }
};


internals.pbkdf2 = function (...args) {

    return new Promise((resolve, reject) => {

        const next = (err, result) => {

            if (err) {
                return reject(Boom.boomify(err));
            }

            resolve(result);
        };

        args.push(next);
        Crypto.pbkdf2(...args);
    });
};
