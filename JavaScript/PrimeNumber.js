var readline = require('readline');



// Function to check if a number is a prime number or not
let primeNumber = function() {
	let num = window.prompt('Enter a number to check')
	for (var i = 2; i < num; ++i) {
		if (num % i == 0)
      // Given Number is not a Prime Number.
			return 'Not a Prime Number';
	}
  // Given Number is a Prime Number.
	return 'Prime Number';
}

//Function to check if a number is a prime number in Node.js
let nodePrimeNumber = () => {
	let rl = readline.createInterface({
		input: process.stdin,
		output: process.stdout
	});
	
	rl.question("Enter a number to check: ", function(num) {
		// Converts input from string into number
		let number=parseInt(num);
		if(number===2){
			console.log(`${number} is a Prime Number`) 
		}
		//console.log(typeof(num));
		for (let i = 2; i < number; i++) {
			if (number % i === 0) {
				// Given Number is not a Prime Number.
				console.log(`${number} is not a Prime number`);
				return rl.close();
			} else {
				console.log(`${number} is a Prime Number`) 
				return rl.close();
			}
		}
		rl.close();
	});
}

nodePrimeNumber();

