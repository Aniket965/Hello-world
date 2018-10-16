'use strict';

// Load modules

const Assert = require('assert');

const Code = require('code');
const Boom = require('boom');
const Bounce = require('..');
const Hoek = require('hoek');
const Lab = require('lab');


// Declare internals

const internals = {};


// Test shortcuts

const { describe, it } = exports.lab = Lab.script();
const expect = Code.expect;


describe('Bounce', () => {

    describe('rethrow()', () => {

        it('rethrows all errors', () => {

            const orig = new Error('Something');

            try {
                Bounce.rethrow(orig);
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.shallow.equal(orig);
            expect(error).to.be.an.error('Something');
        });

        it('rethrows only system errors', () => {

            try {
                Bounce.rethrow(new Error('Something'), 'system');
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            try {
                Bounce.rethrow(new URIError('Something'), 'system');
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something', URIError);
        });

        it('rethrows only boom errors', () => {

            try {
                Bounce.rethrow(new Error('Something'), 'boom');
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            try {
                Bounce.rethrow(Boom.badRequest('Something'), 'boom');
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something');
        });

        it('rethrows only boom/system errors', () => {

            try {
                Bounce.rethrow(new Error('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            try {
                Bounce.rethrow(Boom.badRequest('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something');

            try {
                Bounce.rethrow(new SyntaxError('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error3 = err;
            }

            expect(error3).to.be.an.error('Something', SyntaxError);
        });

        it('rethrows only specified errors', () => {

            try {
                Bounce.rethrow(new Error('Something'), URIError);
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            try {
                Bounce.rethrow(new URIError('Something'), URIError);
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something', URIError);
        });

        it('rethrows only specified errors', () => {

            try {
                Bounce.rethrow(new Error('Something'), URIError);
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            try {
                Bounce.rethrow(new URIError('Something'), URIError);
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something', URIError);
        });

        it('rethrows only errors matching a pattern', () => {

            try {
                Bounce.rethrow(new Error('Something'), { x: 1 });
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            const xErr = new Error('Something');
            xErr.x = 1;

            try {
                Bounce.rethrow(xErr, { x: 1 });
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something');
        });

        it('rethrows only errors matching a pattern (deep)', () => {

            try {
                Bounce.rethrow(new Error('Something'), { x: { y: 2 } });
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.not.exist();

            const xErr = new Error('Something');
            xErr.x = { y: 2, z: 4 };

            try {
                Bounce.rethrow(xErr, { x: { y: 2 } });
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.be.an.error('Something');
        });

        it('rethrows a decorated error', () => {

            const orig = new Error('Something');
            const decorate = { x: 1, y: 'z' };

            try {
                Bounce.rethrow(orig, Error, { decorate });
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.shallow.equal(orig);
            expect(error).to.be.an.error('Something');
            expect(error.x).to.equal(1);
            expect(error.y).to.equal('z');
        });

        it('throws a different error', () => {

            const orig = new Error('Something');

            try {
                Bounce.rethrow(orig, Error, { override: new Error('Else') });
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.not.shallow.equal(orig);
            expect(error).to.be.an.error('Else');
        });

        it('returns error instead of throwing', () => {

            const orig = new Error('Something');

            expect(() => Bounce.rethrow(orig, Error, { return: true })).to.not.throw();

            const error = Bounce.rethrow(orig, Error, { return: true });
            expect(error).to.shallow.equal(orig);
            expect(error).to.be.an.error('Something');
        });
    });

    describe('ignore()', () => {

        it('ignores system errors', () => {

            try {
                Bounce.ignore(new Error('Something'), 'system');
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.be.an.error('Something', Error);

            try {
                Bounce.ignore(new URIError('Something'), 'system');
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.not.exist();
        });

        it('ignores boom errors', () => {

            try {
                Bounce.ignore(new Error('Something'), 'boom');
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.be.an.error('Something', Error);

            try {
                Bounce.ignore(Boom.badRequest('Something'), 'boom');
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.not.exist();
        });

        it('ignores boom/system errors', () => {

            try {
                Bounce.ignore(new Error('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error1 = err;
            }

            expect(error1).to.be.an.error('Something', Error);

            try {
                Bounce.ignore(Boom.badRequest('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error2 = err;
            }

            expect(error2).to.not.exist();

            try {
                Bounce.ignore(new ReferenceError('Something'), ['boom', 'system']);
            }
            catch (err) {
                var error3 = err;
            }

            expect(error3).to.not.exist();
        });
    });

    describe('background()', () => {

        it('rethrows system errors', async () => {

            const test = async () => {

                await Hoek.wait(10);
                throw new SyntaxError('Something');
            };

            try {
                await Bounce.background(test(), 'rethrow', 'system');
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.exist();
        });

        it('rethrows system errors (defaults)', async () => {

            const test = async () => {

                await Hoek.wait(10);
                throw new SyntaxError('Something');
            };

            try {
                await Bounce.background(test());
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.exist();
        });

        it('ignores system errors', async () => {

            const test = async () => {

                await Hoek.wait(10);
                throw new Error('Something');
            };

            try {
                await Bounce.background(test(), 'rethrow', 'system');
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.not.exist();
        });

        it('ignores system errors (background)', () => {

            const test = async () => {

                await Hoek.wait(10);
                throw new Error('Something');
            };

            Bounce.background(test(), 'rethrow', 'system');
        });

        it('rethrows system errors (sync)', async () => {

            const test = () => {

                throw new SyntaxError('Something');
            };

            try {
                await Bounce.background(test, 'rethrow', 'system');
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.exist();
        });

        it('ignores system errors (sync)', async () => {

            const test = () => {

                throw new Error('Something');
            };

            try {
                await Bounce.background(test, 'rethrow', 'system');
            }
            catch (err) {
                var error = err;
            }

            expect(error).to.not.exist();
        });

        it('ignores system errors (background sync)', () => {

            const test = () => {

                throw new Error('Something');
            };

            Bounce.background(test, 'rethrow', 'system');
        });
    });

    describe('isBoom()', () => {

        it('identifies Boom as Boom', () => {

            expect(Bounce.isBoom(Boom.badRequest())).to.be.true();
        });

        it('identifies EvalError as non-boom', () => {

            expect(Bounce.isBoom(new EvalError())).to.be.false();
        });

        it('identifies object as non-boom', () => {

            expect(Bounce.isBoom({})).to.be.false();
        });

        it('identifies object with isBoom as non-boom', () => {

            expect(Bounce.isBoom({ isBoom: true })).to.be.false();
        });
    });

    describe('isError()', () => {

        it('identifies Error as error', () => {

            expect(Bounce.isError(new Error())).to.be.true();
        });

        it('identifies Boom as error', () => {

            expect(Bounce.isError(Boom.badRequest())).to.be.true();
        });

        it('identifies object as non-error', () => {

            expect(Bounce.isBoom({})).to.be.false();
        });
    });

    describe('isSystem()', () => {

        it('identifies EvalError as system', () => {

            expect(Bounce.isSystem(new EvalError())).to.be.true();
        });

        it('identifies RangeError as system', () => {

            expect(Bounce.isSystem(new RangeError())).to.be.true();
        });

        it('identifies ReferenceError as system', () => {

            expect(Bounce.isSystem(new ReferenceError())).to.be.true();
        });

        it('identifies SyntaxError as system', () => {

            expect(Bounce.isSystem(new SyntaxError())).to.be.true();
        });

        it('identifies TypeError as system', () => {

            expect(Bounce.isSystem(new TypeError())).to.be.true();
        });

        it('identifies URIError as system', () => {

            expect(Bounce.isSystem(new URIError())).to.be.true();
        });

        it('identifies node AssertionError as system', () => {

            expect(Bounce.isSystem(new Assert.AssertionError({}))).to.be.true();
        });

        it('identifies Error as non-system', () => {

            expect(Bounce.isSystem(new Error())).to.be.false();
        });

        it('identifies Boom as non-system', () => {

            expect(Bounce.isSystem(Boom.badRequest())).to.be.false();
        });

        it('identifies object as non-system', () => {

            expect(Bounce.isSystem({})).to.be.false();
        });

        it('identifies null as non-system', () => {

            expect(Bounce.isSystem(null)).to.be.false();
        });

        it('identifies boomified system as non-system', () => {

            expect(Bounce.isSystem(Boom.boomify(new TypeError()))).to.be.false();
        });
    });
});
