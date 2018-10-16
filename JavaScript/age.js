var year = prompt("What year were you born?");
var month = prompt("Month?");
var day = prompt("Day?");
var n = new Date(new Date() - (new Date(year + ", " + month + ", " + day))).getFullYear() - 1970;
console.log("You're " + n + "!");
