![wreck Logo](https://raw.github.com/hapijs/wreck/master/images/wreck.png)

### HTTP Client Utilities

[![Npm Version](https://img.shields.io/npm/v/wreck.svg)](https://npmjs.com/package/wreck)
[![Node Version](https://img.shields.io/node/v/wreck.svg)](https://npmjs.com/package/wreck)
[![Build Status](https://secure.travis-ci.org/hapijs/wreck.svg)](http://travis-ci.org/hapijs/wreck)

Lead Maintainer: [Wyatt Preul](https://github.com/geek)

## Usage

<!-- eslint-disable no-undef -->
<!-- eslint-disable no-unused-vars -->
```javascript
const Wreck = require('wreck');

const example = async function () {

    const { res, payload } = await Wreck.get('http://example.com');
    console.log(payload.toString());
};

try {
    example();
}
catch (ex) {
    console.error(ex);
}
```

### Advanced
<!-- eslint-disable no-undef -->
<!-- eslint-disable no-unused-vars -->
```javascript
const Wreck = require('wreck');

const method = 'GET'; // GET, POST, PUT, DELETE
const uri = '/';
const readableStream = Wreck.toReadableStream('foo=bar');

const wreck = Wreck.defaults({
    headers: { 'x-foo-bar': 123 },
    agents: {
        https: new Https.Agent({ maxSockets: 100 }),
        http: new Http.Agent({ maxSockets: 1000 }),
        httpsAllowUnauthorized: new Https.Agent({ maxSockets: 100, rejectUnauthorized: false })
    }
});

// cascading example -- does not alter `wreck`
// inherits `headers` and `agents` specified above
const wreckWithTimeout = wreck.defaults({
    timeout: 5
});

// all attributes are optional
const options = {
    baseUrl: 'https://www.example.com',
    payload: readableStream || 'foo=bar' || Buffer.from('foo=bar'),
    headers: { /* http headers */ },
    redirects: 3,
    beforeRedirect: (redirectMethod, statusCode, location, resHeaders, redirectOptions, next) => next(),
    redirected: function (statusCode, location, req) {},
    timeout: 1000,    // 1 second, default: unlimited
    maxBytes: 1048576, // 1 MB, default: unlimited
    rejectUnauthorized: true || false,
    downstreamRes: null,
    agent: null,         // Node Core http.Agent
    secureProtocol: 'SSLv3_method', // The SSL method to use
    ciphers: 'DES-CBC3-SHA' // The TLS ciphers to support
};

const example = async function () {

    const promise = wreck.request(method, uri, options);
    try {
        const res = await promise;
        const body = await Wreck.read(res);
        console.log(body.toString());
    }
    catch (err) {
        // Handle errors
    }
};
```

Use `promise.req.abort()` to terminate the request early. Note that this is limited to the initial request only.
If the request was already redirected, aborting the original request will not abort execution of pending redirections.


### `defaults(options)`

Returns a *new* instance of Wreck which merges the provided `options` with those provided on a per-request basis. You can call defaults repeatedly to build up multiple http clients.
- `options` - Config object containing settings for both `request` and `read` operations.

### `request(method, uri, [options])`

Initiate an HTTP request.
- `method` - A string specifying the HTTP request method, defaulting to 'GET'.
- `uri` - The URI of the requested resource.
- `options` - An optional configuration object. To omit this argument but still
  use a callback, pass `null` in this position. The options object supports the
  following optional keys:
    - `baseUrl` - fully qualified uri string used as the base url. Most useful with `request.defaults`, for example when you want to do many requests to the same domain.
                  If `baseUrl` is `https://example.com/api/`, then requesting `/end/point?test=true` will fetch `https://example.com/api/end/point?test=true`. Any
                  querystring in the `baseUrl` will be overwritten with the querystring in the `uri` When `baseUrl` is given, `uri` must also be a string.
    - `socketPath` - `/path/to/unix/socket` for Server.
    - `payload` - The request body as a string, Buffer, Readable Stream, or an object that can be serialized using `JSON.stringify()`.
    - `headers` - An object containing request headers.
    - `redirects` - The maximum number of redirects to follow.
    - `redirect303` - if `true`, a HTTP 303 status code will redirect using a GET method. Defaults to no redirection on 303.
    - `beforeRedirect` - A callback function that is called before a redirect is triggered, using the signature
      `function(redirectMethod, statusCode, location, resHeaders, redirectOptions, next)` where:
          - `redirectMethod` - A string specifying the redirect method.
          - `statusCode` - HTTP status code of the response that triggered the redirect.
          - `location` - The redirect location string.
          - `resHeaders` - An object with the headers received as part of the redirection response.
          - `redirectOptions` - Options that will be applied to the redirect request. Changes to this object are applied to the redirection request.
          - `next` - the callback function called to perform the redirection using signature `function()`.
    - `redirected` - A callback function that is called when a redirect was triggered, using the signature `function(statusCode, location, req)` where:
      - `statusCode` - HTTP status code of the response that triggered the redirect.
      - `location` - The redirected location string.
      - `req` - The new [ClientRequest](http://nodejs.org/api/http.html#http_class_http_clientrequest) object which replaces the one initially returned.
    - `timeout` - The number of milliseconds to wait without receiving a response
      before aborting the request. Defaults to unlimited.
    - `maxBytes` - maximum size for response payload. Defaults to unlimited.
    - `rejectUnauthorized` - [TLS](http://nodejs.org/api/tls.html) flag indicating
      whether the client should reject a response from a server with invalid certificates.  This cannot be set at the
      same time as the `agent` option is set.
    - `downstreamRes`: downstream Resource dependency.
    - `agent` - Node Core [http.Agent](http://nodejs.org/api/http.html#http_class_http_agent).
      Defaults to either `wreck.agents.http` or `wreck.agents.https`.  Setting to `false` disables agent pooling.
    - `secureProtocol` - [TLS](http://nodejs.org/api/tls.html) flag indicating the SSL method to use, e.g. `SSLv3_method`
      to force SSL version 3. The possible values depend on your installation of OpenSSL. Read the official OpenSSL docs
      for possible [SSL_METHODS](http://www.openssl.org/docs/ssl/ssl.html#DEALING_WITH_PROTOCOL_METHODS).
    - `ciphers` - [TLS](https://nodejs.org/api/tls.html#tls_modifying_the_default_tls_cipher_suite) list of TLS ciphers to override node's default.
      The possible values depend on your installation of OpenSSL. Read the official OpenSSL docs
      for possible [TLS_CIPHERS](https://www.openssl.org/docs/man1.0.2/apps/ciphers.html#CIPHER-LIST-FORMAT).

Returns a promise that resolves into a node response object. The promise has a `req` property which is the instance of the node.js
[ClientRequest](http://nodejs.org/api/http.html#http_class_http_clientrequest) object.

### `read(response, options)`
- `response` - An HTTP Incoming Message object.
- `options` - `null` or a configuration object with the following optional keys:
    - `timeout` - The number of milliseconds to wait while reading data before
    aborting handling of the response. Defaults to unlimited.
    - `json` - A value indicating how to try to parse the payload as JSON. Defaults to `undefined` meaning no parse logic.
        - `true`, 'smart' - only try `JSON.parse` if the response indicates a JSON content-type.
        - `strict` - as 'smart', except returns an error for non-JSON content-type.
        - `force` - try `JSON.parse` regardless of the content-type header.
    - `gunzip` - A value indicating the behavior to adopt when the payload is gzipped. Defaults to `undefined` meaning no gunzipping.
        - `true` - only try to gunzip if the response indicates a gzip content-encoding.
        - `false` - explicitly disable gunzipping.
        - `force` - try to gunzip regardless of the content-encoding header.
    - `maxBytes` - The maximum allowed response payload size. Defaults to unlimited.

Returns a promise that resolves into the payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

#### Notes about gunzip

When using gunzip, HTTP headers `Content-Encoding`, `Content-Length`, `Content-Range` and `ETag` won't reflect the reality as the payload has been uncompressed.

### `get(uri, [options])`

Convenience method for GET operations.
- `uri` - The URI of the requested resource.
- `options` - Optional config object containing settings for both `request` and
  `read` operations.

Returns a promise that resolves into an object with the following properties:
    - `res` - The [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage)
       object, which is a readable stream that has "ended" and contains no more data to read.
    - `payload` - The payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

Throws any error that may have occurred during handling of the request or a Boom error object if the response has an error status
code (i.e. 4xx or 5xx). If the error is a boom error object it will have the following properties in addition to the standard boom
properties:
    - `data.isResponseError` - boolean, indicates if the error is a result of an error response status code
    - `data.headers` - object containing the response headers
    - `data.payload` - the payload in the form of a Buffer or as a parsed object
    - `data.res` - the [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage) object

### `post(uri, [options])`

Convenience method for POST operations.
- `uri` - The URI of the requested resource.
- `options` - Optional config object containing settings for both `request` and
  `read` operations.

Returns a promise that resolves into an object with the following properties:
    - `res` - The [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage)
       object, which is a readable stream that has "ended" and contains no more data to read.
    - `payload` - The payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

Throws any error that may have occurred during handling of the request or a Boom error object if the response has an error status
code (i.e. 4xx or 5xx). If the error is a boom error object it will have the following properties in addition to the standard boom
properties:
    - `data.isResponseError` - boolean, indicates if the error is a result of an error response status code
    - `data.headers` - object containing the response headers
    - `data.payload` - the payload in the form of a Buffer or as a parsed object
    - `data.res` - the [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage) object

### `patch(uri, [options])`

Convenience method for PATCH operations.
- `uri` - The URI of the requested resource.
- `options` - Optional config object containing settings for both `request` and
  `read` operations.

Returns a promise that resolves into an object with the following properties:
    - `res` - The [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage)
       object, which is a readable stream that has "ended" and contains no more data to read.
    - `payload` - The payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

Throws any error that may have occurred during handling of the request or a Boom error object if the response has an error status
code (i.e. 4xx or 5xx). If the error is a boom error object it will have the following properties in addition to the standard boom
properties:
    - `data.isResponseError` - boolean, indicates if the error is a result of an error response status code
    - `data.headers` - object containing the response headers
    - `data.payload` - the payload in the form of a Buffer or as a parsed object
    - `data.res` - the [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage) object

### `put(uri, [options])`

Convenience method for PUT operations.
- `uri` - The URI of the requested resource.
- `options` - Optional config object containing settings for both `request` and
  `read` operations.

Returns a promise that resolves into an object with the following properties:
    - `res` - The [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage)
       object, which is a readable stream that has "ended" and contains no more data to read.
    - `payload` - The payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

Throws any error that may have occurred during handling of the request or a Boom error object if the response has an error status
code (i.e. 4xx or 5xx). If the error is a boom error object it will have the following properties in addition to the standard boom
properties:
    - `data.isResponseError` - boolean, indicates if the error is a result of an error response status code
    - `data.headers` - object containing the response headers
    - `data.payload` - the payload in the form of a Buffer or as a parsed object
    - `data.res` - the [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage) object

### `delete(uri, [options])`

Convenience method for DELETE operations.
- `uri` - The URI of the requested resource.
- `options` - Optional config object containing settings for both `request` and
  `read` operations.

Returns a promise that resolves into an object with the following properties:
    - `res` - The [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage)
       object, which is a readable stream that has "ended" and contains no more data to read.
    - `payload` - The payload in the form of a Buffer or (optionally) parsed JavaScript object (JSON).

Throws any error that may have occurred during handling of the request or a Boom error object if the response has an error status
code (i.e. 4xx or 5xx). If the error is a boom error object it will have the following properties in addition to the standard boom
properties:
    - `data.isResponseError` - boolean, indicates if the error is a result of an error response status code
    - `data.headers` - object containing the response headers
    - `data.payload` - the payload in the form of a Buffer or as a parsed object
    - `data.res` - the [HTTP Incoming Message](https://nodejs.org/api/http.html#http_class_http_incomingmessage) object

### `toReadableStream(payload, [encoding])`

Creates a [readable stream](http://nodejs.org/api/stream.html#stream_class_stream_readable)
for the provided payload and encoding.
- `payload` - The Buffer or string to be wrapped in a readable stream.
- `encoding` - The encoding to use. Must be a valid Buffer encoding, such as 'utf8' or 'ascii'.

<!-- eslint-disable no-unused-vars -->
<!-- eslint-disable no-undef -->
```javascript
const stream = Wreck.toReadableStream(Buffer.from('Hello', 'ascii'), 'ascii');
const read = stream.read();
// read -> 'Hello'
```

### `parseCacheControl(field)`

Parses the provided *cache-control* request header value into an object containing
a property for each directive and it's value. Boolean directives, such as "private"
or "no-cache" will be set to the boolean `true`.
- `field` - The header cache control value to be parsed.

<!-- eslint-disable no-unused-vars -->
<!-- eslint-disable no-undef -->
```javascript
const result = Wreck.parseCacheControl('private, max-age=0, no-cache');
// result.private -> true
// result['max-age'] -> 0
// result['no-cache'] -> true
```

### `agents`

Object that contains the agents for pooling connections for `http` and `https`.
The properties are `http`, `https`, and `httpsAllowUnauthorized` which is an
`https` agent with `rejectUnauthorized` set to false.  All agents have
`maxSockets` configured to `Infinity`.  They are each instances of the Node.js
[Agent](http://nodejs.org/api/http.html#http_class_http_agent) and expose the
standard properties.

For example, the following code demonstrates changing `maxSockets` on the `http`
agent.

 ```js
 const Wreck = require('wreck');

 Wreck.agents.http.maxSockets = 20;
 ```

Below is another example that sets the certificate details for all HTTPS requests.

<!-- eslint-disable no-undef -->
```js
const HTTPS = require('https');
const Wreck = require('wreck');

Wreck.agents.https = new HTTPS.Agent({
    cert,
    key,
    ca
});
```

### Events

To enable events, use `Wreck.defaults({ events: true })`. Events are available via the
`events` emitter attached to the client returned by `Wreck.defaults()`.

#### `request`

The request event is emitted just before *wreck* makes a request.  The
handler should accept the following arguments `(uri, options)` where:

  - `uri` - the result of `Url.parse(uri)`. This will provide information about
  the resource requested.  Also includes the headers and method.
  - `options` - the options passed into the request function.  This will include
  a payload if there is one.

Since the `request` event executes on a global event handler, you can intercept
and decorate a request before its sent.


#### `response`

The response event is always emitted for any request that *wreck* makes.  The
handler should accept the following arguments `(err, details)` where:

  - `err` - a Boom error
  - `details` - object with the following properties
    - `req` - the raw `ClientHttp` request object
    - `res` - the raw `IncomingMessage` response object
    - `start` - the time that the request was initiated
    - `uri` - the result of `Url.parse(uri)`. This will provide information about
    the resource requested.  Also includes the headers and method.

This event is useful for logging all requests that go through *wreck*. The `err`
and `res` arguments can be undefined depending on if an error occurs.  Please
be aware that if multiple modules are depending on the same cached *wreck*
module that this event can fire for each request made across all modules.  The
`start` property is the timestamp when the request was started.  This can be
useful for determining how long it takes *wreck* to get a response back and
processed.
