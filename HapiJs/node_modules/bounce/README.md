# bounce

Selective error catching and rewrite rules

[![Build Status](https://secure.travis-ci.org/hapijs/bounce.svg)](http://travis-ci.org/hapijs/bounce)

Lead Maintainer - [Eran Hammer](https://github.com/hueniverse)

## Introduction

Working with `async`/`await` introduces a new challange in handling errors. Unlike callbacks, which
provide a dual machanism for passing application errors via the callback `err` argument and
developer errors via exceptions, `await` combines these two channels into one.

It is common practice to ignore application errors in background processing or when there is no
useful fallback. In those cases, it is still imperative to allow developer errors to surface and
not get swallowed.

For more information read:
- [Learning to Throw Again](https://medium.com/@eranhammer/learning-to-throw-again-79b498504d28)
- [Catching without Awaiting](https://medium.com/@eranhammer/catching-without-awaiting-b2cb7df45790)

For example:

```js
async function email(user) {

    if (!user.address) {
        throw new Error('User has no email address');
    }

    const message = 'Welcome!';
    if (user.name) {
        message = `Welcome ${user.name}!`;
    }

    await mailer.send(user.address, message);
}

async function register(address, name) {

    const user = { address, name };
    const id = await db.user.insert(user);
    user.id = id;

    try {
        await email(user);
    }
    catch (err) { }             // Ignore errors

    return user;
}
```

This will fail silently every time the user has a `name` because it is reassigning a value to a
`const` variable. However, because `email()` errors are ignored, system errors are ignored as well.
The idea is that `email()` can be used in both critical and non-critical paths. In the critical
paths, errors are checked and addressed, but in the non-critical paths, errors are simply ignored.

This can be solved by adding a `rethrow()` statement:

```js
const Bounce = require('bounce');

async function register(address, name) {

    const user = { address, name };
    const id = await db.user.insert(user);
    user.id = id;

    try {
        await email(user);
    }
    catch (err) {
        Bounce.rethrow(err, 'system');  // Rethrows system errors and ignores application errors
    }

    return user;
}
```

## Usage

### `rethrow(err, types, [options])`

Throws the error passed if it matches any of the specified rules where:
- `err` - the error.
- `type` - a single item or an array of items of:
    - An error constructor (e.g. `SyntaxError`).
    - `'system'` - matches any languange native error or node assertions.
    - `'boom'` - matches [**boom**](https://github.com/hapijs/boom) errors.
    - an object where each property is compared with the error and must match the error property
      value. All the properties in the object must match the error but do not need to include all
      the error properties.
- `options` - optional object where:
    - `decorate` - an object which is assigned to the `err`, copying the properties onto the error.
    - `override` - an error used to override `err` when `err` matches. If used with `decorate`,
      the `override` object is modified.
    - `return` - if `true`, the error is returned instead of thrown. Defaults to `false`.

### `ignore(err, types, [options])`

The opposite action of `rethrow()`. Ignores any errors matching the specified `types`. Any error
not matching is thrown after applying the `options`.

### `background(operation, [action], [types], [options])`

Awaits for the value to resolve in the background and then apply either the `rethrow()` or `ignore()`
actions where:
- `operation` - a function, promise, or value that is `await`ed on inside a `try...catch` and any
  error thrown processed by the `action` rule.
- `action` - one of `'rethrow'` or `'ignore'`. Defaults to `'rethrow'`.
- `types` - same as the `types` argument passed to `rethrow()` or `ignore()`. Defaults to `'system'`.
- `options` - same as the `options` argument passed to `rethrow()` or `ignore()`.

### `isBoom(err)`

Returns `true` when `err` is a [**boom**](https://github.com/hapijs/boom) error.

### `isError(err)`

Returns `true` when `err` is an error.

### `isSystem(err)`

Return `true` when `err` is one of:
- `EvalError`
- `RangeError`
- `ReferenceError`
- `SyntaxError`
- `TypeError`
- `URIError`
- Node's `AssertionError`
