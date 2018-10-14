// Implement sum

const sum = (a = 0, b = null) => {
  return b ? a + b : (c = 0) => a + c;
};

console.log(sum(2, 3));
console.log(sum(2)(3));
