console.log("Demo of JS reduce()");
const arr = [{id: 1, age: 27, name: "Lenny"}, {id: 2, age: 30, name: "Jimmy"}, {id: 3, age: 45, name: "Manny"}];
console.log(`Array: ${JSON.stringify(arr, null, 2)}`);

const result = arr.reduce((acc, curr) => {
      acc[curr.id] = curr;
      return acc;
    }, {});

console.log(`Equivalent object: ${JSON.stringify(result, null, 2)}`);

const age_sum = arr.reduce((acc, curr) => {
      acc += curr.age;
      return acc;
    }, 0);

console.log(`Total age: ${JSON.stringify(age_sum, null, 2)}`);
