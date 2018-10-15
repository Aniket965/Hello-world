// Typical interview exercises
//
// Exercise 1
// Implement sum

const sum = (a = 0, b = null) => {
  return b ? a + b : (c = 0) => a + c;
};

console.log(sum(2, 3));
console.log(sum(2)(3));

// - - - - - - - - - - - - - - - - - - - - -
// Exercise 2
// What's the output of this code?

console.log(1);
console.log(setTimeout(() => { console.log(2) }), 0);
console.log(setTimeout(() => { console.log(3) }),1000);
console.log(4);

// output is:
// 1 -> 4 -> 2 -> 3

// - - - - - - - - - - - - - - - - - - - - -
