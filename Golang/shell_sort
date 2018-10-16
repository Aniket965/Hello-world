package main

import (
	"fmt"
)

func shell_sort(arr []int, n int) {
	var j int
	for gap := (n / 2); gap > 0; gap /= 2 {
		for i := gap; i < n; i++ {
			temp := arr[i]
			for j = i; j >= gap && temp < arr[j-gap]; j -= gap {
				arr[j] = arr[j-gap]
			}
			arr[j] = temp
		}
	}
}

func main() {
	arr := []int{1322, 54, 5454, 7656, 45465, 467, 65417, 8645, 49841, 51, 618643, 1346413168, 1168798, 431645168, 46, 9790000987, 65451946}
	shell_sort(arr, len(arr))
	fmt.Println(arr)
}
