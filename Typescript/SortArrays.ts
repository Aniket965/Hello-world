  // Sort arrays
  const arr: ReadonlyArray<string> = ['xyz', 'abc'];
  const copy = arr.slice().sort();
  
  console.log("Sort a String without mutation:", "")
  console.log("arr: ", arr);
  console.log("copy: ", copy);
  
  // Sorting an array of numbers in descending order
  const foo = [100, 220, 4];
  foo.sort((a,b) => b - a);
  
  console.log("Sort numbers in an array:", "")
  console.log("foo: ", foo);
  
  const movies = [
      {
          name: "Movie 1",
          year: 1994
      },
      {
          name: "Movie 2",
          year: 1972
      },
      {
          name: "Movie 3",
          year: 1974
      },
      {
          name: "Movie 4",
          year: 2008
      }
]
// Sorts in ascending order
movies.sort((b,a) => b.year - a.year);

console.log("Sort on an attribute of an object: ", "")
movies.forEach(function(movie) {
    console.log("", movie.name)
})