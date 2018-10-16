# ammo

HTTP Range processing utilities.

[![Npm Version](https://img.shields.io/npm/v/ammo.svg)](https://npmjs.com/package/ammo)
[![Build Status](https://secure.travis-ci.org/hapijs/ammo.png)](http://travis-ci.org/hapijs/ammo)

Lead Maintainer - [Gil Pedersen](https://github.com/kanongil)

## Usage

```js
// basic usage
const range = Ammo.header('bytes=1-5', 10);
// range --> [{ from: 1, to: 5 }]

// multiple ranges
const range = Ammo.header('bytes=1-5,7-10', 10);
// range --> [{ from: 1, to: 5 }, { from: 7, to: 9 }]

// streams (get range within a `source`)
const range = Ammo.header('bytes=1000-4000', 5000);
const stream = new Ammo.Stream(range[0]);
const buffer = async Wreck.read(source.pipe(stream));

// buffer is the portion of source within range
```

## API

### `header(header, length)`

Parses the range from a HTTP header.

* `header` - A string in the form of `bytes=from-to`, where `from` and `to` are
integers specifying the range. Both are optional. Multiple ranges can be passed
as a comma delimited list.
* `length` - A positive integer specifying the maximum length the range can
cover. If a `to` value passed in the `header` string is greater than `length`,
the `to` value is set as `length - 1`.

Returns an array of objects with the properties `from` and `to`, which specify
the beginning and ending of the range. Overlapping ranges are combined into one
object. Returns `null` for invalid input.

### `new Ammo.Stream(range)`

Creates a [`Transform Stream`](https://nodejs.org/api/stream.html) that extracts
the portion of a piped in stream within `range`.
* `range` - an object with the properties `from` and `to` that specify the range
of the piped in stream to read. Objects returned by `Ammo.header` can be passed
into `range`.
