// Naming this your main package, if this isn't named main, code won't run
package main

// Importing the relevant packages
import "fmt"

//defining sum function
func Sum(x int, y int) int {
	        return x + y

}

func main() {

	var a int = 3             // Explicit type decalaration
  	b := 5                    // Implicit type declaration

    	fmt.Print("Enter 2 numbers: ")
      	fmt.Scanf("%d %d", &a, &b)      // Same as C

        sum := Sum(a, b)

	fmt.Printf("Sum: %d\n",sum);
}
