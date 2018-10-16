package main

import "fmt"

func generate(ch chan int) {
        for i := 2 ; ; i++ {
                ch <- i
        }
}

func filter(in chan int,out chan int,prime int) {
        for ;; {
                num := <-in
                if num %prime != 0 {
                        out <- num
                }
        }
}

func main() {
        ch := make(chan int)
        go generate(ch)
        // for test
        for i:= 0; i < 1000; i++ {
        //for ;; {
                prime := <-ch
                fmt.Print(prime, " ,")
                ch1 := make(chan int)
                go filter(ch,ch1,prime)
                ch = ch1
        }
}
