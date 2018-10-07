package main

import "fmt"
import "sort"

func main() {

	strs := []string{"c", "a", "b"}
	sort.Strings(strs)
	fmt.Println("Sorted Strings:", strs)

	ints := []int{7, 2, 5}
	sort.Ints(ints)
	fmt.Println("Sorted Integers:", ints)

	s := sort.IntsAreSorted(ints)
	fmt.Println("Sorted:", s)
}
