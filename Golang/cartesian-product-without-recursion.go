package main

import (
	"fmt"
	"strings"
)

func main() {
	groups := []([]string){
		{"A1", "A2"},
		{"B1", "B2", "B3"},
		{"C1", "C2"},
	}

	combNum := 1
	for _, group := range groups {
		combNum *= len(group)
	}

	result := getEmptyArray(combNum, len(groups))
	pattern := combNum / len(groups[0])
	for i := 0; i < len(groups); i++ {
		groupIndex, patterAcum := 0, 0
		for u := 0; u < combNum; u++ {
			if patterAcum == pattern {
				if groupIndex < len(groups[i])-1 {
					groupIndex++
					patterAcum = 0
				} else {
					groupIndex = 0
					patterAcum = 0
				}
			}
			result[u][i] = groups[i][groupIndex]
			patterAcum++
		}
		if pattern > 1 {
			pattern /= len(groups[i+1])
		}
	}

	// Print
	for _, column := range result {
		fmt.Println(strings.Join(column, " | "))
	}
}

func getEmptyArray(rows, columns int) [][]string {
	result := make([][]string, rows)
	for i := range result {
		result[i] = make([]string, columns)
	}
	return result
}
