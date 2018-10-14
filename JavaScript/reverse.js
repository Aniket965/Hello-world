function reverse(str) {
    return str.split('').reduce((reversed, cha) => {
        return cha + reversed
    }, '');
}

let array = "apple";
console.log(reverse(array))