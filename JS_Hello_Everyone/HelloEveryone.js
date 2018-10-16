console.log("Hello Everyone!");

var map = function(collection, iterator) {
  // map() is a useful primitive iteration function that works a lot
  // like each(), but in addition to running the operation on all
  // the members, it also maintains an array of results.

  let arr = [];

  if (Array.isArray(collection)) {
    for (let i = 0; i < collection.length; i++) {
      arr.push(iterator(collection[i], i, collection));
    }
  } else if (collection !== null && typeof collection === "object") {
    for (var i in collection) {
      arr.push(iterator(collection[i], i, collection));
    }
  }

  return arr;
};
