const express = require('express');
const path = require('path');
const server = express();
const port = process.env.PORT || 7777;

server.use(express.static(__dirname + '/build'))
server.use(express.json());

server.get('/*', (req, res) => {
  res.sendFile(path.join(__dirname + '/build/index.html'));
})

server.listen(port, (err) => {
  err ? console.error(err) : console.log(`Server listening on port ${port}`)
})
