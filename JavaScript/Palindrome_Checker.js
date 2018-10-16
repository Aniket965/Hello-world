/* 1. With built in functions
\W matches any non-word character (equal to [^a-zA-Z0-9_])
_ matches the character _ literally (case sensitive)
*/

function isPalindrome(str) {
  return str.replace(/[\W_]/g, '').toLowerCase() ===
         str.replace(/[\W_]/g, '').toLowerCase().split('').reverse().join('');
}

console.log(isPalindrome("racecar"));

/*
2. With a for loop and straight forward regex
function isPalindrome(str) {
  var regex = /[^A-Za-z0-9]/g;
  str = str.toLowerCase().replace(regex, '');
  var len = str.length;
  for (var i = 0; i < len/2; i++) {
    if (str[i] !== str[len - 1 - i]) {
        return false;
    }
  }
  return true;
 }
*/
