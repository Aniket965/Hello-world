package main

import "fmt"

func multiplication(nums ...int) {
	fmt.Print(nums, " ")
	total := 0
	for i, num := range nums {
		if i == 0 {
			total = num
		}
		total = total * num
	}
	fmt.Println(total)
}

func main() {
	multiplication(1, 2)
	multiplication(1, 2, 3)
	nums := []int{1, 2, 3, 4}
	multiplication(nums...)
}
