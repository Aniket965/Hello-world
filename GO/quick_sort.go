package main

import (
	"fmt"
)

func QuickSort(arr []int, low int, high int) {

	if low < high {
		mid := partition(arr, low, high)
		QuickSort(arr, low, mid-1)
		QuickSort(arr, mid+1, high)
	}

}

func partition(arr []int, low int, high int) int {

	pivot := arr[high]
	i := low - 1
	for j := low; j <= high-1; j++ {
		if arr[j] <= pivot {
			i++
			temp := arr[i]
			arr[i] = arr[j]
			arr[j] = temp
		}
	}
	temp := arr[i+1]
	arr[i+1] = arr[high]
	arr[high] = temp
	return (i + 1)
}

func main() {

	var arr = []int{1, 9, 5, 4, 7, 6, 8}

	fmt.Println(arr)
	QuickSort(arr, 0, len(arr)-1)
	fmt.Println(arr)

}
