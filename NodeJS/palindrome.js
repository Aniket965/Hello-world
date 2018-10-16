const palindrome = function (value) {
    
    let revValue = value.toLowerCase().split("").reverse().join("");
    return revValue == value.toLowerCase();
};

console.log("Welcome to Hacktoberfest 2018");
console.log("This is a simple palindrome program");
console.log("Examples: ");
console.log("'Hello' is " + (palindrome("Hello") ? "" : "not ") + "a palindrome");
console.log("'Madam' is " + (palindrome("Madam") ? "" : "not ") + "a palindrome");