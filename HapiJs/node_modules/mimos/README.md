#mimos

Mime database interface.

[![Build Status](https://secure.travis-ci.org/hapijs/mimos.svg)](http://travis-ci.org/hapijs/mimos)
[![Current Version](https://img.shields.io/npm/v/mimos.svg)](https://www.npmjs.com/package/mimos)

Lead Maintainer - [Adam Bretz](https://github.com/arb)

Mimos is a convenience class for retrieving mime information objects.

## Usage

### `new Mimos([options])`

Creates a new Mimos object where:

- `[options]` - an option object the following keys
    - `[override]` - an object hash that is merged into the built in mime information specified [here](https://github.com/jshttp/mime-db). Each key value pair represents a single mime object. Each override value should follow this schema:
        - `key` - the key is the lower-cased correct mime-type. (Ex. "application/javascript").
        - `value` - the value should an object following the specifications outlined [here](https://github.com/jshttp/mime-db#data-structure). Additional values include:
          - `type` - specify the `type` value of result objects, defaults to `key`. See the example below for more clarification.
          - `predicate` - method with signature `function(mime)` when this mime type is found in the database, this function will run. This allows you make customizations to `mime` based on developer criteria.

### `mimos.path(path)`

Returns mime object where:

- `path` path to file including the file extension. Uses the `extension` values of the mime objects for lookup.

```js
const mimos = new Mimos();
const mime = mimos.path('/static/public/app.js');
// mime
/*
{
  source: 'iana',
  charset: 'UTF-8',
  compressible: true,
  extensions: [ 'js' ],
  type: 'application/javascript'
}
*/
```

### `mimos.type(type)`

Returns mime object where:

- `type` the content-type to find mime information about. Uses the `type` values of the mime objects for lookup.

```js
const mimos = new Mimos();
const mime = mimos.type('text/plain');
// mime
/*
{
  source: 'iana',
  compressible: true,
  extensions: ['txt', 'text', 'conf', 'def', 'list', 'log', 'in', 'ini'],
  type: 'text/plain'
}
*/
```

### Override Example

In certain situations, it can be helpful to override the built in mime type information. The optional argument to the Mimos constructor is used to override and add mime information. Below is an example to help understand how this works.

```js

const options = {
    override: {
        'node/module': {
            source: 'iana',
            compressible: true,
            extensions: ['node', 'module', 'npm'],
            type: 'node/module'
        },
        'application/javascript': {
            source: 'iana',
            charset: 'UTF-8',
            compressible: true,
            extensions: ['js', 'javascript'],
            type: 'text/javascript'
        },
        'text/html': {
            predicate: function(mime) {
                if (someCondition) {
                    mime.foo = 'test';
                }
                else {
                    mime.foo = 'bar';
                }
                return mime;
            }
        }
    }
}

const mimos = new Mimos(options);
console.dir(mimos.path('./node_modules/mimos.module'));
/*
{
  source: 'iana',
  compressible: true,
  extensions: ['node', 'module', 'npm'],
  type: 'node/module'
}
*/
console.dir(mimos.type('application/javascript'));
/*
Note: even though we asked for type 'application/javascript', the type value is 'text/javascript' because of the override. Always use the proper content-type for retrieval.
{
  source: 'iana',
  charset: 'UTF-8',
  compressible: true,
  extensions: ['js', 'javascript'],
  type: 'text/javascript'
}
*/
console.dir(mimos.type('text/html'));
/*
someCondition is true:
{
  source: 'iana',
  compressible: true,
  extensions: ['html','htm'],
  type: 'test/html',
  foo: 'test'
}

someCondition is false:
{
  source: 'iana',
  compressible: true,
  extensions: ['html','htm'],
  type: 'test/html',
  foo: 'bar'
}
*/
```
