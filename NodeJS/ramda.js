// Run `npm install ramda` before executing.

let R = require('ramda')

let codes = [ 72, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 33 ]

function inspect (x) {
  console.log(x)
  return x
}

function toChar (code) {
  return String.fromCharCode(code)
}

const greetWorld = R.pipe(
  R.map(toChar),
  R.join(''),
  inspect
)

greetWorld(codes)
