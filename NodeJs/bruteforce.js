function msleep(n) {
    Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, n);
}

function rand(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

var find = "Hacktoberfest".split('');
var result = [];

for(var i = 0; i < find.length; i++) {
  var notFound = true;
  while(notFound) {
    var randomChar = String.fromCharCode(rand(32, 126));
    result[i] = randomChar;
    
    msleep(5);
    process.stdout.write(result.join('') + "\r");
    
    if(find[i] == randomChar) {
      notFound = false;
    }
  }	
}

process.stdout.write(result.join('') + "\r\n");

