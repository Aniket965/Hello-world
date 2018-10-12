package daos

import (
	"testing"

	"github.com/magiconair/properties/assert"
)

func Test_calculatePoints(t *testing.T) {
	tests := []struct {
		Tag, Word string
		Guesses   []rune
		ExpPoints int
	}{
		{"t1", "MILK", []rune{'K', 'D', 'H', 'R', 'L'}, 10},
		{"t2", "ROAD", []rune{'K', 'M', 'H', 'Q', 'L'}, -10},
		{"t3", "CALCULATOR", []rune{'T', 'D', 'A', 'S', 'O', 'P'}, 70},
	}

	for _, test := range tests {
		newPoints := calculatePoints(test.Word, test.Guesses)
		assert.Equal(t, test.ExpPoints, newPoints)
	}
}

func Test_isFinished(t *testing.T) {
	tests := []struct {
		Tag, Word   string
		Guesses     []rune
		ExpFinished int
	}{
		{"t1", "MILK", []rune{'K', 'D', 'H', 'R', 'L', 'I', 'M'}, GameWon},
		{"t2", "ROAD", []rune{'K', 'M', 'H', 'Q', 'L', 'Z'}, GameLost},
		{"t3", "CALCULATOR", []rune{'T', 'D', 'A', 'S', 'O', 'P'}, GameInProgress},
	}

	for _, test := range tests {
		newFinished := isFinished(test.Word, test.Guesses)
		assert.Equal(t, test.ExpFinished, newFinished)
	}
}
