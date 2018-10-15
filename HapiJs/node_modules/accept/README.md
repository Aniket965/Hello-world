#Accept

HTTP Accept-* headers parsing.

[![npm version](https://badge.fury.io/js/accept.svg)](http://badge.fury.io/js/accept) [![Build Status](https://secure.travis-ci.org/hapijs/accept.png)](http://travis-ci.org/hapijs/accept) [![Dependency Status](https://david-dm.org/hapijs/accept.svg)](https://david-dm.org/hapijs/accept)

Lead Maintainer - [Mark Bradshaw](https://github.com/mark-bradshaw)

## Introduction

Accept helps to answer the question of how best to respond to a HTTP request, based on the requesting browser's capabilities.  Accept will parse the headers of a HTTP request and tell you what the preferred encoding is, what language should be used, and what charsets and media types are accepted.

Additional details about Accept headers and content negotiation can be found in [IETF RFC 7231, Section 5.3](https://tools.ietf.org/html/rfc7231#section-5.3).

## API

For information on using Accept see the [API documentation](API.md).
