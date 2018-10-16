package main

import "fmt"

func pigeonhole_sort(arr []int) []int {
	max := arr[0]
	min := arr[0]

	for i := 0; i < len(arr); i++ {
		if arr[i] < min {
			min = arr[i]
		}
		if arr[i] > max {
			max = arr[i]
		}
	}

	rang := int(max - min + 1)

	holes := make([]int, rang)

	for i := 0; i < len(arr); i++ {
		holes[arr[i]-min] += arr[i]
	}

	return holes
}

func main() {
	arr := []int{323, 23, 21, 3123, 1}
	hole := pigeonhole_sort(arr)

	for i := 0; i < len(hole); i++ {
		if hole[i] > 0 {
			fmt.Println(hole[i])
		}
	}

}
