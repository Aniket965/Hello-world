// The Monkey Programming Language: https://interpreterbook.com/

let newGreeter = fn(greeting) {
  return fn(name) { puts(greeting + " " + name); } // not sure if this supports interpolation, builders, or interning
};

// `hello` is a greeter function that says "Hello"
let hello = newGreeter("Hello");

hello("Hacktoberfest!"); 
