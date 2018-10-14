//use array_name.charCodeAt(index) to get ASCII value of a character
//use String.fromCharCode(ASCII_VALUE) to get character
function rot13(str) { // LBH QVQ VG!
    let cipher, decipher;
    let arr = [];
    let myregex = /[A-Z]+$/;
    for (let i = 0; i < str.length; i++) {
        if (myregex.test(str[i])) {
            cipher = str.charCodeAt(i);
            decipher = (((cipher - 65) + 13) % 26) + 65;
            arr.push(String.fromCharCode(decipher));

        } else {
            arr.push(str[i]);
            continue;
        }
    }
    str = arr.join('');
    return str;
}

// Change the inputs below to test
console.log(rot13("SERR PBQR PNZC"));
