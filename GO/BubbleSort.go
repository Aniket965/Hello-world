package main
import "fmt"

func main() {

	x := []int{
		48, 96, 86, 68,
		57, 82, 63, 70,
		37, 34, 83, 27,
		19, 97, 9, 17,
	}
	end := len(x) - 1
	for {
		if end == 0 {
			break
		}
		for i := 0; i < len(x)-1; i++ {
			if x[i] > x[i+1] {
				x[i], x[i+1] = x[i+1], x[i]
			}
		}
		end -= 1
	}
	fmt.Println(x)
}
