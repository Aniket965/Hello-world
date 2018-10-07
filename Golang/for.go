package main

import "fmt"

func main() {

	i := 1
	for i <= 10 {
		fmt.Println(i%4)
		i = i+1
	}

	for n:=0; n<=10; n++ {
		if n%3 == 0 {
			continue
		}
		fmt.Println(n)
	}

	for {
		fmt.Println("loop")
		break
	}
}
