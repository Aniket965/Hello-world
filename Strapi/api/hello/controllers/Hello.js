'use strict';

/**
 * Hello.js controller
 */

module.exports = {

  // GET /hello
  world: async (ctx) => {
    // Will display "Hello World!".
    ctx.send('Hello World!');
  },

  // GET /hello/John
  sayHello: async (ctx) => {
    if (ctx.params.name === '') {
      return ctx.badRequest('Please provide a valid parameter.');
    }

    // Will display "Hello John" for example.
    ctx.send(`Hello ${ctx.params.name}!`);
  },

  // GET /hello/John?locale=en_US
  sayInternationalHello: async (ctx) => {
    if (ctx.params.name === '') {
      return ctx.badRequest('Please provide a valid parameter.');
    }

    // Will display "Hello John" in english.
    // Will display "Bonjour John" in french.
    ctx.send(ctx.i18n.__(`Hello %s`, ctx.params.name));
  }

};
