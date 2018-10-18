package main

import (
	"fmt"
)

func IsPrime(n int) bool {
	if n < 2 {
		return true
	} else if n == 2 {
		return true
	} else if n%2 == 0 {
		return false
	} else {
		i := 3
		for i*i <= n {
			if n%i == 0 {
				return false
			}
			i += 2
		}
		return true
	}
}

func main() {
	for i := 2; i < 10000; i++ {
		if IsPrime(i) {
			fmt.Println(i)
		}
	}
}
