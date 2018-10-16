package main

import "fmt"

func main() {

	var a [5]int
	fmt.Println("emp:", a)

	a[4] = 100
	fmt.Println("set:", a)
	fmt.Println("get:", a[4])
	fmt.Println("len:", len(a))

	b := [5]int{10,20,30,40,50}
	fmt.Println("dcl:", b)

	var twoD [2][3]int
	for i :=0; i < 2; i++ {
		for j :=0; j<3; j++ {
			twoD[i][j] = i+j
		}
	}
	fmt.Println("2d matrix:", twoD)
}
