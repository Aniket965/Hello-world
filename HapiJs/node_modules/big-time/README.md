# Big-Time

[![Current Version](https://img.shields.io/npm/v/big-time.svg)](https://www.npmjs.org/package/big-time)
[![Build Status via Travis CI](https://travis-ci.org/arb/big-time.svg?branch=master)](https://travis-ci.org/arb/big-time)
[![belly-button-style](https://img.shields.io/badge/eslint-bellybutton-4B32C3.svg)](https://github.com/continuationlabs/belly-button)


Reworking of [long-timeout](https://github.com/tellnes/long-timeout) that has more features, follows correct semver, and has unit tests. Big-Time is a custom timer class to allow really long values into `setTimeout` that are larger than JavaScript would normally support (2^31-1).

## Usage

```js
'use strict';
const bt = require('big-time');

bt.setTimeout(() => {
  console.log('if you wait for this, it will eventually log');
}, Number.MAX_VALUE);

const timer = bt.setTimeout(() => {
  console.log('shorter');
}, 1000);
bt.clearTimeout(timer);
```

## API

### `bt.setTimeout(callback, delay, [arg1, arg2, arg3,...])`

Creates a new Big-Time timer object and starts the timer where:

- `callback` - the function to execute after `delay` milliseconds has passed. `callback` will be called with `arg1, arg2, arg3...` if they are passed into `setTimeout`, exactly like native `setTimeout`
- `delay` - an integer representing the number of milliseconds to wait before executing `callback`. Alternatively, a `Date` instance can be provided. In this scenario, the delay is computed by subtracting `Date.now()` from the `Date` instance.
- `[arg1, arg2, arg3,...]` - optional `N` number of extra parameters that will be passed back into `callback`.

### `bt.clearTimeout(timer)`

Clears a running Big-Time object.

### `Timeout.prototype.ref()`

When called, requests that the Node.js event loop not exit so long as the
`Timeout` is active. Calling `timeout.ref()` multiple times will have no effect.

By default, all `Timeout` objects are "ref'd", making it normally unnecessary to
call `timeout.ref()` unless `timeout.unref()` had been called previously.

Returns a reference to the `Timeout`.

### `Timeout.prototype.unref()`

When called, the active `Timeout` object will not require the Node.js event loop
to remain active. If there is no other activity keeping the event loop running,
the process may exit before the `Timeout` object's callback is invoked. Calling
`timeout.unref()` multiple times will have no effect.

Returns a reference to the `Timeout`.
