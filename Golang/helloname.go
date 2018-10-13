package main

import "os"
import "fmt"

func main()  {
	if len(os.Args) < 2 {
		fmt.Println("You did not pass a name");
		os.Exit(1);
	}
	fmt.Printf("Hello %s\n", os.Args[1])
}