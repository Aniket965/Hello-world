function isPalindrome(word="racecar"){
    if(typeof word === "string"){
        word = [...word].reverse().join('').toLowerCase();;
        return `${word} is a palindrome`
    } else {
        return `${word} is not a palindrome`;
    }
}

console.log(isPalindrome());
