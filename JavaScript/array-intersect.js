function intersect (arr1, arr2) {
  return arr1.filter((item) => arr2.indexOf(item) >= 0)
}

module.exports = intersect
