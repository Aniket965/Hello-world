const feathers = require('@feathersjs/feathers');
const express = require('@feathersjs/express');
const app = express(feathers());

app.listen(8080);
