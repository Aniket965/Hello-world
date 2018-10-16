package main

import (
	"fmt"
)

func Abs(number float64) float64 {
	if number < 0 {
		return -number
	}
	return number
}

func Sqrt(number float64) (result float64) {
	result, previousResult, iteration := 1.0, 0.0, 0
	for ; iteration < 100 && Abs(result-previousResult) > 1e-7; iteration++ {
		previousResult = result
		result -= (result*result - number) / (2 * result)
	}
	return
}

func main() {
	var num float64
	fmt.Print("Input a number, and we'll calculate its square root: ")
	fmt.Scanln(&num)
	fmt.Printf("The square root of %f is: %f\n", num, Sqrt(num))
}
