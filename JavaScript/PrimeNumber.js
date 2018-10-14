// Function to check if a number is a prime number or not
let primeNumber = function() {
	let num = prompt('Enter a number to check')
	for (var i = 2; i < num; ++i) {
		if (num % i == 0)
      // Given Number is not a Prime Number.
			return 'Not a Prime Number';
	}
  // Given Number is a Prime Number.
	return 'Prime Number';
}

// Calling primeNumber and logging the result on console.
console.log(primeNumber());
