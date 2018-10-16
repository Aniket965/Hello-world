![shot Logo](https://raw.github.com/hapijs/shot/master/images/shot.png)

Injects a fake HTTP request/response into a node HTTP server for simulating server logic, writing tests, or debugging. Does not use a socket
connection so can be run against an inactive server (server not in listen mode).

[![Build Status](https://secure.travis-ci.org/hapijs/shot.png)](http://travis-ci.org/hapijs/shot)

Lead Maintainer: [Matt Harrison](https://github.com/mtharrison)

## Example

```javascript
// Load modules

const Http = require('http');
const Shot = require('shot');


// Declare internals

const internals = {};


internals.main = function () {

    const dispatch = function (req, res) {

        const reply = 'Hello World';
        res.writeHead(200, { 'Content-Type': 'text/plain', 'Content-Length': reply.length });
        res.end(reply);
    };

    const server = Http.createServer(dispatch);

    Shot.inject(dispatch, { method: 'get', url: '/' }, (res) => {

        console.log(res.payload);
    });
};


internals.main();
```

Note how `server.listen` is never called.

## API

See the [API Reference](API.md)
