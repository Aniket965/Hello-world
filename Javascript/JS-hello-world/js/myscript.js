console.log("Hello World...!");
// Single Line Comment
/*
Multiline Comment
*/
// Boolean Data Type
console.log(true);
console.log(false);

// Number Data Type
console.log(0b10);
console.log(0B10);

console.log(010);
console.log(011);
console.log(09);

console.log(1);

console.log(0xA);
console.log(0XA);

console.log(1.25);
console.log(1.25e2);
console.log(1.25E2);
console.log(1.25e-2);

console.log('IJ\tSE');
console.log("IJ\tSE"); 
console.log("IJ'S'E");
console.log('IJ"S"E');

console.log(null);
console.log(undefined);

var _name = null;   
console.log(typeof _name);

// Object.defineProperty(typeof global === "object" ? global : window, "PI", {
//     value:        3.141593,
//     enumerable:   true,
//     writable:     false,
//     configurable: false
// });

var PI = 3.14;

var myArray = new Array();
myArray.push(10);
myArray.push("IJSE");
myArray.push(30);

console.log(myArray.length);
console.log(myArray.toString());

myArray.pop();
console.log(myArray.toString());

myArray.push(40);
console.log(myArray.toString());

myArray.splice(1,1);        // index,1
console.log(myArray.toString());

myArray.unshift("Suranga");
console.log(myArray.toString());

myArray.shift();
console.log(myArray.toString());

myArray = [10,20,30,40];
console.log(myArray.toString());

var index = myArray.indexOf(20);
console.log("Index of 20 : " + index);

index = myArray.indexOf(100);
console.log(index);

myArray = new Array("10,20","IJSE");
console.log(myArray.toString());

var twoDArray = [[10,20],[30,40]];
console.log(twoDArray[0][1]);

var twoDArray = new Array(new Array(10,20), new Array(30,40));
console.log(twoDArray[0][1]);

var index = twoDArray.indexOf(new Array(10,20));
console.log(index); // -1

// String casting
var myVar = "10";
console.log(+myVar);
console.log(parseInt(myVar));

myVar = "10.25";
console.log(parseFloat(myVar));
myVar = 10.25;
console.log("" + myVar);

// Unary Operators

// Prefix increment, postfix increment, prefix decrement, postfix decrement
a = 2;
a = a++ + ++a - 2 + a++ + a + a-- + ++a ;
console.log(a);

var result = void(1+3);
console.log(result);

a = 2;
result = void (a++);

console.log(result);

console.log(typeof a);

myVar = "10";

console.log(myVar === 10);

myVar = 10;

result = (myVar < 20) ? "kudai" : "lokui";

console.log(result);

myArray = [10,20,30,40,50];

for(var index in myArray){
    console.log(myArray[index]);
}

for(var property in window){
    console.log(property);
}

// for(var element of myArray){
//     console.log(element);
// }

function myFun(){
    console.log("This is void function");
}

myFun();

function myFun2(){
    return "This is return function";
}

result = myFun2();
console.log(result);

function printName(name){
    console.log("Name : " + name);
}

printName("Suranga");

function printDetails(){
    console.log(arguments[1]);
    for(var index in arguments){
        console.log(arguments[index]);
    }
}

printDetails("Suranga","IJSE");

function myMethod(){
    console.log("Method 1");
}

function myMethod(name){
    console.log("Method 2");
}

function myMethod(name,age){
    console.log("Method 3");
}

myMethod(); // Do not try to over load methods in javascript

function defaultParams(name){
    if (name === undefined) name = "IJSE";
    name = (typeof name === "undefined") ? "IJSE" : undefined;
    console.log(name);
}

defaultParams();

function varArgs(){
    for(var index in arguments){
        console.log(arguments[index]);
    }
}
varArgs("Suranga","Upul","Ganga","Kaputa");