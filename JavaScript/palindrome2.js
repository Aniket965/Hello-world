function isPalindrome(word){
    if(typeof word === "string"){
        let revWord = [...word].reverse().join('');
        return word.toLowerCase() === revWord.toLowerCase();
    } else {
        return false;
    }
}

console.log('isPalindrome("dad")::', isPalindrome('dad'));