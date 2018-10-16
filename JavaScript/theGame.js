function gamePlay(num) {
    return num * num - 3 + 4;
}


let number = prompt(`Enter a number:`);

let luckyNum = gamePlay(number);

alert(`Your lucky number is ${number}`);