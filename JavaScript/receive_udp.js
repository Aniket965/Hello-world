var s_port = 41234;
var dgram = require("dgram");
var server = dgram.createSocket("udp4");

server.on("listening", function() {
  var address = server.address();
  console.log("server listening " + address.address + ":" + address.port);
});
server.on("message", function(msg, rinfo) {
  console.log("server got a message from " + rinfo.address + ":" + rinfo.port);
  console.log("  ASCII: " + msg);
});
server.on("error", function(err) {
  console.log("server error: \n" + err.stack);
  server.close();
});
server.on("close", function() {
  console.log("closed.");
});
server.bind(s_port);
