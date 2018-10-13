console.log(`=== demo of js Array-object filter() ===`);

arr = [
    {"name": 'abc', "num": 123}, 
    {"name": 'def', "num": 456}, 
    {"name": 'ghi', "num": 789}
  ];

// orig
console.log(`Orig array: ${JSON.stringify(arr, null, 2)}`);

console.log("---search---");
// filter to search an item
var searchString = 'ghi';
var result = arr.filter(function(item) {return item["name"] === searchString});

console.log(`Search 'ghi' result: ${JSON.stringify(result)}`);


console.log("---delete---");
// filter to delete an item
arr = arr.filter(function(item) {return item["name"] !== searchString});
console.log(`After deleting 'ghi', array: ${JSON.stringify(arr, null, 2)}`);