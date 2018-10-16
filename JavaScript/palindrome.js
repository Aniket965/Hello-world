// takes a string as the argument
function palindrome(str) {
// length of the string in len
    var len = str.length;
    // checks the mid value (for the loop)
    var mid = Math.floor(len/2);

// loop it and checks if the first character in the string is not same as the last then increment i
    for ( var i = 0; i < mid; i++ ) {
        if (str[i] !== str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}
