package main

import (
	"fmt"
)

func sampleChannel(word string) <-chan string {
	newWord := make(chan string)
	go func() { newWord <- word + " World." }()
	return newWord
}

func main() {
	a := sampleChannel("Hello")
	fmt.Println(<-a)
}
