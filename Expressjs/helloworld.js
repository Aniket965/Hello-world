const express = require('express');
const app = express();

var randNum = 0;
var a = 0;
var b = 0;

app.get('/', function (req, res) {
  randNum = Math.random();
  if (randNum < 0.5) {
    a++;
    res.send('<h1 style="color: red;">Hello World!</h1><h3>Page Visits: ' + a + '</h3>');
  } else {
    b++;
    res.send('<h1 style="color: blue;">Hello Hacktoberfest 2018!</h1><h3>Page Visits: ' + b + '</h3>');
  }
});

app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});