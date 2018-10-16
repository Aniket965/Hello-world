// Simple way of reversing a string :)

const reverseString = str => {
  let newStr = "";
  for (let char of str) {
    newStr = char + newStr;
  }
  return newStr;
};

reverseString("Puppy");
