//Fizz Buzz challenge
//For multiples of 3 show "Fizz" instead of the number
//For multiples of 5 show "Buzz" instead of the number
//For numbers which are multiples of both 3 and 5 show "FizzBuzz"
//written by Paul Caoile [https://github.com/m2paulc]

const array1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,];
const array2 = [5,2,9,7,11,13,15,285,25,300,125,50,75,100];

//define an object containing the multiples
const fizzbuzz_obj = {3:'Fizz', 5:'Buzz'};

//define the function
function getFizzBuzz(obj, arr) {
  let newArray = [];
  let sizeOfArray = arr.length;
  let strOutput = '';
  for(let i=0; i < sizeOfArray; i++) {
    strOutput = '';
    for(let key in fizzbuzz_obj) {
      if(arr[i] % key === 0) {
        strOutput += fizzbuzz_obj[key];
      }
    }
    if(strOutput === '') {
      strOutput = arr[i];
    }
    // console.log(strOutput);
    newArray.push(strOutput);
  }
  return newArray;
}

console.log(getFizzBuzz(fizzbuzz_obj,array1));
console.log(getFizzBuzz(fizzbuzz_obj,array2));