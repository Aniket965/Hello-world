// To run this file, you need to install nodejs
// node factoriel.js 6
// 6 is the factorial you want

var n = process.argv[2];
var i = n - 1;
var res = n;
while (i > 1) {
    res *= i;
    i--;
}
console.log(res);
