function palindrome(str) {
    // Good luck!
    let myRegex = /[A-Za-z0-9]+/g; // all alpha-numeric
    let result = str.match(myRegex);
    let word = "";
    for (let i = 0; i < result.length; i++) {
        word = word + result[i];
    }
    word = word.toLowerCase();
    let tmp = word;
    let first = 0,
        last = word.length - 1;
    let flag = 0;
    while (true) {
        if (word[first] == tmp[last]) {
            if (first == word.length - 1 || last == 0) {
                break;
            }
            first = first + 1;
            last = last - 1;
        } else {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        return false;
    }
    return true;
}
// Basic solution not most performant by freeCodeCamp
// function palindrome(str) {
//     return str.replace(/[\W_]/g, '').toLowerCase() ===
//         str.replace(/[\W_]/g, '').toLowerCase().split('').reverse().join('');
// }

console.log(palindrome('never odd or even'));
