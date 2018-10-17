// Author: Tejas Nanaware
// GitHub: github.com/Tejas-Nanaware
// This file provides the basics of ES6 using Babel

// Variables and constants
var a = 10;
let b = 10;
b = 25;
const c = 10;
a = 43;

// Arrow functions
const myFunc = (arg) => {
  console.log(arg);
}
myFunc(23);

// Inline arrow functions
const multiply = (n1, n2) => n1 * n2;
console.log(multiply(2,3))

// Import export functions
// Classes
class myPerson {
  constructor() {
    this.name='abc';
  }
  printMyName() {
    console.log(this.name);
  }
}
const my_person = new myPerson();
my_person.printMyName();

// ES6 Classes
class Human {
  gender = 'male';
  printGender = () => {
    console.log(this.gender);
  }
}
class Person extends Human {
  gender = 'female';
  name = 'abc'
  printMyName = () => {
    console.log(this.name);
  }
}
const person = new Person();
person.printMyName();
person.printGender();

// Spread and Rest operator ...
const numbers = [1,2,3];
const newNumbers = [...numbers,4,5];
console.log(newNumbers);

const filter = (...args) => args.filter(el => el === 1);
console.log(filter(1,2,3));

// Destructuring
// const numbers = [1,2,3];
[num1, , num3] = numbers;
console.log(num1,num3);
// Referenced and Primitive data types

// Array functions
// const numbers = [1,2,3];
const doubleNumbers = numbers.map((num) => {
  return num * 2;
});
console.log(numbers, doubleNumbers);
