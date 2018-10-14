package main

import (
	"fmt"
)

func sampleChannel(num string) <-chan string {
	newNum := make(chan string)
	go func() { newNum <- num + " World." }()
	return newNum
}

func main() {
	a := sampleChannel("Hello")
	fmt.Println(<-a)
}
