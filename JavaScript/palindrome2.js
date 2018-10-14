const isPalindrome = (word) => {
    return word.split('').reverse().map(s => s.toLowerCase()).join('') === word.split('').map((s => s.toLowerCase())).join('')
}

console.log(isPalindrome('aibohphobia'))