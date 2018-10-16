'use strict';

var Hapi = require('hapi');

var server = Hapi.server({
    port: 3000,
    host: 'localhost'
});

server.route({
    method: 'GET',
    path: '/',
    handler: (request, h) => {
        return 'Hello world!';
    }
});

var helloWorld = async () => {
    await server.start();
    console.log(`Listening at: ${server.info.uri}`);
};

process.on('unhandledRejection', (err) => {
    console.log(err);
    process.exit(1);
});

helloWorld();
