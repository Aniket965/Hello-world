package main

import (
	"bufio"
	"fmt"
	"os"
)

func fill(grids [][]byte, row int, col int, rowSize int, colSize int) {
	// sanity checks
	if row < 0 || col < 0 || row >= rowSize || col >= colSize {
		return
	}
	if grids[row][col] == '*' || grids[row][col] == '#' {
		return
	}

	grids[row][col] = '#'

	fill(grids, row+1, col, rowSize, colSize)
	fill(grids, row-1, col, rowSize, colSize)
	fill(grids, row, col+1, rowSize, colSize)
	fill(grids, row, col-1, rowSize, colSize)
}

// Sample Input/Output
// Enter row and column size:
// 7 8
// Enter grids, use '#' as wall:
// ########
// #......#
// ###.....
// .##..###
// .##.####
// ##...#.#
// #####..#
// Enter x and y positions of filling (0-indexed):
// 1 1

// After flood fill:

// ########
// ########
// ########
// .#######
// .#######
// ######.#
// #####..#

func main() {
	var rowSize, colSize int
	fmt.Println("Enter row and column size:")
	_, err := fmt.Scanf("%d %d", &rowSize, &colSize)
	if err != nil {
		panic(err)
	}

	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	fmt.Println("Enter grids, use '#' as wall: ")
	grids := make([][]byte, rowSize)

	for i := 0; i < rowSize; i++ {
		grids[i], err = reader.ReadBytes('\n')
		if err != nil {
			panic(err)
		}

		grids[i] = grids[i][:len(grids[i])-2]
		if len(grids[i]) != colSize {
			fmt.Println("Number of characters in a line doesn't match column size")
			return
		}
	}

	fmt.Println("Enter x and y positions of filling (0-indexed):")
	var row, col int
	_, err = fmt.Scanf("%d %d", &row, &col)
	if err != nil {
		panic(err)
	}
	fill(grids, row, col, rowSize, colSize)
	fmt.Println("\nAfter flood fill:\n")
	for i := 0; i < rowSize; i++ {
		fmt.Println(string(grids[i]))
	}

}
