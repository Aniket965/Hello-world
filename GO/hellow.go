package main

import (
	"fmt"
)

func main() {
	var str = "こんにちは世界"
	var lenstr = len(str) / 3
	for i := 0; i < lenstr; i++ {
		fmt.Println(string([]rune(str)[i]))
	}

}
