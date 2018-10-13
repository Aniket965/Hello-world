var messageCodes = [72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100,33];
var helloWorldMessage = String.fromCharCode.apply(null, messageCodes);
console.log(helloWorldMessage);