package main

import "fmt"

// Recursive implementation of Factorial
func factRec(n int) int {
	if n <= 1 {
		return 1
	}
	return n * factRec(n-1)
}

// Iterative implementation of Factorial
func factIter(n int) int {
	answer := 1
	for i := 2; i <= n; i++ {
		answer = answer * i
	}
	return answer
}

// Tail recursion implementation of factorial
func factTailRec(n int) int {
	return factTail(n, 1)
}

func factTail(n int, current int) int {
	if n <= 1 {
		return current
	}
	return factTail(n-1, current*n)
}

func main() {
	fmt.Println(factIter(5))
	fmt.Println(factRec(5))
	fmt.Println(factTailRec(5))
}
