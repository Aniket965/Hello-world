package main

import (
	"fmt"
	"math/rand"
)

func generateRandomNumber() int {
	randomInt := rand.Intn(101)
	if randomInt != 0 {
		return randomInt
	}
	return generateRandomNumber()
}

func main() {
	fmt.Println("********************************************")
	fmt.Println("******** HERE IS YOUR GUESSING GAME ********")
	fmt.Println("********************************************")
	fmt.Println()
	fmt.Println("Rules: You got 3 tries to guess the correct number")
	fmt.Println("Guess the correct number which is between 1 to 100")
	answer := generateRandomNumber()
	tries := 3
	for i := tries; i >= 0; i-- {
		var guess int
		fmt.Println()

		if i == 0 {
			fmt.Println("Sorry, you lost")
			break
		}

		fmt.Println(i, "trie(s) remaining.")
		fmt.Scanf("%d", &guess)

		if guess > answer {
			fmt.Println("Your guess is more than expected.")
		} else if guess < answer {
			fmt.Println("Your guess is low than expected.")
		} else {
			fmt.Println("Congratulations! You gussed it.")
			break
		}
	}
}
