'use strict'

let a = 'ana'

let b = a.split('').reverse().join('')

console.log(`is ${a} an anagram? ${a === b}`);