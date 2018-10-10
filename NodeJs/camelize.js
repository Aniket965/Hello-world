const camelize = (text) => {
  return text.replace(/\W+(.)/g, (match, chr) => {
    return chr.toUpperCase();
  });
};

console.log(camelize("Hacktoberfest Exercise"));
console.log(camelize("Hacktoberfest exercises"));
console.log(camelize("HacktoberfestExercises"));
