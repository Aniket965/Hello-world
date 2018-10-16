package main

import (
	"fmt"
	"math/rand"
)

const max = 100

func partition(arr []int, low, high int) int {
	pivotIndex := low + rand.Int()%(high-low+1)
	pivot := arr[pivotIndex]
	arr[pivotIndex], arr[high] = arr[high], arr[pivotIndex]
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			arr[j], arr[low] = arr[low], arr[j]
			low++
		}
	}

	arr[low], arr[high] = arr[high], arr[low]
	return low
}

func quickSort(arr []int, low, high int) {
	if low > high {
		return
	}
	pi := partition(arr, low, high)
	quickSort(arr, low, pi-1)
	quickSort(arr, pi+1, high)
}

func main() {
	arr := []int{79, 10, 73, 1, 68, 56, 3}
	quickSort(arr, 0, len(arr)-1)
	fmt.Println(arr)
}
