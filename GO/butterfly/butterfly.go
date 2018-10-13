package butterfly

import "fmt"

func butterfly() {
	var e int
	fmt.Scanf("Enter size of butterfly : %d", &e)

	for i := 0; i < e*2-1; i++ {
		for j := 0; j < e*2; j++ {
			if i < e { // upper half
				if i >= j {
					fmt.Print("*")
				} else {
					if i >= 2*e-j-1 {
						fmt.Print("*")
					} else {
						fmt.Print("_")
					}
				}
			} else { //lower half
				if i < 2*e-j-1 {
					fmt.Print("*")
				} else {
					if i < j {
						fmt.Print("*")
					} else {
						fmt.Print("_")
					}
				}
			}
		}
		fmt.Println()
	}
}
