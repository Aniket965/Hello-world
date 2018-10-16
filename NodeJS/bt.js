// shows nearby bluetooth device 
const bluetooth = require('node-bluetooth');

const device = new bluetooth.DeviceINQ();

device.listPairedDevices(console.log)

device
.on('finished',  console.log.bind(console, 'finished'))
.on('found', function found(address, name){
console.log(name'+'address)
}).scan()
