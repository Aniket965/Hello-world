package main

import (
	"fmt"
)

func sieve_of_eratosthenes(n int) {

	prime := make([]bool, n+1)

	for i := 0; i < n+1; i++ {
		prime[i] = true
	}

	for p := 2; p*p <= n; p++ {

		if prime[p] == true {

			for i := p * 2; i <= n; i += p {
				prime[i] = false
			}
		}
	}

	for q := 2; q <= n; q++ {

		if prime[q] == true {
			fmt.Printf(" %v", q)
		}
	}
}

func main() {

	a := 30
	sieve_of_eratosthenes(a)

}
