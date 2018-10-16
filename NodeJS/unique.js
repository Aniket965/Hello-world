/**
 * Remove duplicate values from array
 */
module.exports = function unique (arr) {
  if (!Array.isArray(arr)) {
    throw TypeError('Input must be an Array')
  }

  if (arr.length === 0) {
    return arr
  }

  const set = new Set(arr)
  const uniqueArr = Array.from(set)

  return uniqueArr
}
