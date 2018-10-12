package main

import (
	"fmt"
	"time"
)

const chars = "Hello, world!"

func main() {
	for _, c := range chars {
		fmt.Print(string(c))
		time.Sleep(50 * time.Millisecond)
	}
	fmt.Println()
}
