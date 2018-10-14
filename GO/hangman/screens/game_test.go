package screens

import (
	"testing"

	"github.com/magiconair/properties/assert"
)

func Test_getWord(t *testing.T) {
	tests := []struct {
		Tag          string
		ExpExistence bool
	}{
		{"t1", true},
	}

	for _, test := range tests {
		var exists bool = false
		newWord := getWord()
		if newWord != "" {
			exists = true
		}
		assert.Equal(t, test.ExpExistence, exists)
	}
}

func Test_renderGame(t *testing.T) {
	tests := []struct {
		Tag, Word string
		Guesses   []rune
		ExpState  GameState
	}{
		{"t1", "MILK", []rune{'K', 'D', 'H', 'R', 'L'}, GameStarted},
		{"t2", "DUNK", []rune{'V', 'D', 'X', 'W'}, GameStarted},
		{"t3", "COFFEE", []rune{'K', 'D', 'H', 'R', 'L', 'P'}, GameFinished},
		{"t4", "GAME", []rune{'K', 'D', 'G', 'A', 'E', 'M'}, GameFinished},
	}

	for _, test := range tests {
		newState := renderGame(test.Word, test.Guesses)
		assert.Equal(t, test.ExpState, newState)
	}
}
