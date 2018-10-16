![catbox Logo](https://raw.github.com/hapijs/catbox/master/images/catbox.png)

Multi-strategy object caching service
Version: **10.x**

[![Build Status](https://secure.travis-ci.org/hapijs/catbox.svg)](http://travis-ci.org/hapijs/catbox)

Lead Maintainer: [Gil Pedersen](https://github.com/kanongil)

**catbox** is a multi-strategy key-value object store. It comes with extensions supporting a memory
cache,
 [Redis](http://redis.io/),
 [MongoDB](http://www.mongodb.org/),
 [Memcached](http://memcached.org/),
 [Riak](http://basho.com/riak/),
 [Amazon S3](http://aws.amazon.com/s3/),
 [RethinkDB](http://rethinkdb.com),
 [Couchbase](http://www.couchbase.com/),
 [Aerospike](http://www.aerospike.com/) and
 [LevelDB](http://leveldb.org/).

**catbox** provides two interfaces: a low-level `Client` and a high-level `Policy`.


### Installation

In order to reduce module dependencies, **catbox** does not include the external caching
strategies. To use other strategies, each service must be manually installed via npm or package
dependencies manually. The available strategies are:

- [Memory](https://github.com/hapijs/catbox-memory)
- [Redis](https://github.com/hapijs/catbox-redis)
- [MongoDB](https://github.com/hapijs/catbox-mongodb)
- [Memcached](https://github.com/hapijs/catbox-memcached)
- [Riak](https://github.com/DanielBarnes/catbox-riak)
- [Amazon S3](https://github.com/fhemberger/catbox-s3)
- [RethinkDB](https://github.com/codedmart/catbox-rethinkdb)
- [Couchbase](https://github.com/cmfatih/catbox-couchbase)
- [Aerospike](https://github.com/ooogway/catbox-aerospike)
- [LevelDB](https://github.com/mshick/catbox-multilevel)
- [Local Disk](https://github.com/mirusresearch/catbox-disk)


### `Client`

The `Client` object provides a low-level cache abstraction. The object is constructed using
`new Client(engine, options)` where:

- `engine` - is an object or a prototype function implementing the cache strategy:
    - function - a prototype function with the signature `function(options)`. **catbox** will call
      `new func(options)`.
    - object - a pre instantiated client implementation object. Does not support passing `options`.
- `options` - the strategy configuration object. Each strategy defines its own configuration
  options with the following common options:
    - `partition` - the partition name used to isolate the cached results across multiple clients.
      The partition name is used as the MongoDB database name, the Riak bucket, or as a key prefix
      in Redis and Memcached. To share the cache across multiple clients, use the same partition
      name.

Note that any implementation of client strategies must return deep copies of the stored data as the
API assumes that the object returned from a `get()` is owned by the called and can be safely
modified without affecting the cache copy.


#### API

The `Client` object provides the following methods:

- `await start()` - creates a connection to the cache server. Must be called before any other
  method is available. Any errors are thrown.
- `stop()` - terminates the connection to the cache server.
- `await get(key)` - retrieve an item from the cache engine if found where:
    - `key` - a cache key object (see below).
    - return value:
        - `null` is the item is not found.
        - throws an error if the request failed.
        - otherwise, an object with the following properties:
            - `item` - the value stored in the cache using `set()`.
            - `stored` - the timestamp when the item was stored in the cache (in milliseconds).
            - `ttl` - the remaining time-to-live (not the original value used when storing the
              object).
- `await set(key, value, ttl)` - store an item in the cache for a specified length of time, where:
    - `key` - a cache key object (see below).
    - `value` - the string or object value to be stored.
    - `ttl` - a time-to-live value in milliseconds after which the item is automatically removed
      from the cache (or is marked invalid).
    - any errors are thrown.
- `await drop(key)` - remove an item from cache where:
    - `key` - a cache key object (see below).
    - any errors are thrown.
- `isReady()` - returns `true` if cache engine determines itself as ready, `false` if it is not
  ready.
- `validateSegmentName(segment)` - returns `null` if the segment name is valid (see below),
  otherwise should return an instance of `Error` with an appropriate message.

Any method with a `key` argument takes an object with the following required properties:
- `segment` - a caching segment name string. Enables using a single cache server for storing
  different sets of items with overlapping ids.
- `id` - a unique item identifier string (per segment). Can be an empty string.


### `Policy`

The `Policy` object provides a convenient cache interface by setting a global policy which is
automatically applied to every storage action. The object is constructed using
`new Policy(options, [cache, segment])` where:

- `options` - is an object with the following optional keys (unless noted otherwise):
    - `expiresIn` - relative expiration expressed in the number of milliseconds since the item was
      saved in the cache. Cannot be used together with `expiresAt`.
    - `expiresAt` - time of day expressed in 24h notation using the 'HH:MM' format, at which point
      all cache records for the route expire. Uses local time. Cannot be used together with
      `expiresIn`.
    - `generateFunc` - a function used to generate a new cache item if one is not found in the
      cache when calling `get()`. The method's signature is `async function(id, flags)` where:
        - `id` - the `id` string or object provided to the `get()` method.
        - `flags` - an object used to pass back additional flags:
            - `ttl` - the cache ttl value in milliseconds. Set to `0` to skip storing in the cache.
              Defaults to the cache global policy.
    - `staleIn` - number of milliseconds to mark an item stored in cache as stale and attempt to
      regenerate it when `generateFunc` is provided. Must be less than `expiresIn`. Alternatively 
      function that returns staleIn value in milliseconds. The function signature is
      `function(stored, ttl)` where:
        - `stored` - the timestamp when the item was stored in the cache (in milliseconds).
        - `ttl` - the remaining time-to-live (not the original value used when storing the object).
    - `staleTimeout` - number of milliseconds to wait before returning a stale value while
      generateFunc is generating a fresh value.
    - `generateTimeout` - number of milliseconds to wait before returning a timeout error when the
      `generateFunc` function takes too long to return a value. When the value is eventually
      returned, it is stored in the cache for future requests. Required if `generateFunc` is
      present. Set to `false` to disable timeouts which may cause all `get()` requests to get stuck
      forever.
    - `dropOnError` - if `true`, an error or timeout in the `generateFunc` causes the stale value
      to be evicted from the cache. Defaults  to `true`.
    - `generateOnReadError` - if `false`, an upstream cache read error will stop the `get()` method
      from calling the generate function and will instead pass back the cache error. Defaults to
      `true`.
    - `generateIgnoreWriteError` - if `false`, an upstream cache write error will be passed back
      with the generated value when calling the `get()` method. Defaults to `true`.
    - `pendingGenerateTimeout` - number of milliseconds while generateFunc call is in progress for
      a given id, before a subsequent generateFunc call is allowed. Defaults to 0, no blocking of
      concurrent generateFunc calls beyond staleTimeout.
    - `getDecoratedValue` - if `true`, the return value of `policy.get()` calls is an object with
      `{ value, cached, report }`. Defaults to `false` which returns a plain value.
- `cache` - a `Client` instance (which has already been started).
- `segment` - required when `cache` is provided. The segment name used to isolate cached items
  within the cache partition.


#### API

The `Policy` object provides the following methods:

- `await get(id)` - retrieve an item from the cache. If the item is not found and the
  `generateFunc` method was provided, a new value is generated, stored in the cache, and returned.
  Multiple concurrent requests are queued and processed once. The method arguments are:
    - `id` - the unique item identifier (within the policy segment). Can be a string or an object
      with the required 'id' key.
    - return value:
        - the requested item if found, otherwise `null`.
        - any errors are thrown.
        - if `getDecoratedValue` is `true`, returns an object with the following properties:
            - `value` - the fetched or generated value.
            - `cached` - `null` if a valid item was not found in the cache, or an object with the
              following keys:
                - `item` - the cached `value`.
                - `stored` - the timestamp when the item was stored in the cache.
                - `ttl` - the cache ttl value for the record.
                - `isStale` - `true` if the item is stale.
            - `report` - an object with logging information about the generation operation
              containing the following keys (as relevant):
                - `msec` - the cache lookup time in milliseconds.
                - `stored` - the timestamp when the item was stored in the cache.
                - `isStale` - `true` if the item is stale.
                - `ttl` - the cache ttl value for the record.
                - `error` - lookup error.
- `await set(id, value, ttl)` - store an item in the cache where:
    - `id` - the unique item identifier (within the policy segment).
    - `value` - the string or object value to be stored.
    - `ttl` - a time-to-live **override** value in milliseconds after which the item is
      automatically removed from the cache (or is marked invalid). This should be set to `0` in
      order to use the caching rules configured when creating the `Policy` object.
    - any errors are thrown.
- `await drop(id)` - remove the item from cache where:
    - `id` - the unique item identifier (within the policy segment).
    - any errors are thrown.
- `ttl(created)` - given a `created` timestamp in milliseconds, returns the time-to-live left based
  on the configured rules.
- `rules(options)` - changes the policy rules after construction (note that items already stored
  will not be affected) where:
    - `options` - the same `options` as the `Policy` constructor.
- `isReady()` - returns `true` if cache engine determines itself as ready, `false` if it is not
  ready or if there is no cache engine set.
- `stats` - an object with cache statistics where:
    - `sets` - number of cache writes.
    - `gets` - number of cache `get()` requests.
    - `hits` - number of cache `get()` requests in which the requested id was found in the cache
      (can be stale).
    - `stales` - number of cache reads with stale requests (only counts the first request in a
      queued `get()` operation).
    - `generates` - number of calls to the generate function.
    - `errors` - cache operations errors.
