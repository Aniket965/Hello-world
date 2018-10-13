const zlib = require('zlib');
const zmq = require('zeromq'); // npm install zeromq
const sock = zmq.socket('sub');

sock.connect('tcp://eddn.edcd.io:9500');
console.log('Worker connected to port 9500');

sock.subscribe('');

sock.on('message', topic => {
  console.log(JSON.parse(zlib.inflateSync(topic)));
});
