package screens

import (
	"testing"

	"github.com/hitchnsmile/go-hangman/daos"
	"github.com/magiconair/properties/assert"
)

func Test_convertCurrentWord(t *testing.T) {
	tests := []struct {
		Tag, Word, Guesses, ExpWord string
	}{
		{"t1", "MILK", "IGDKL", "_ILK"},
		{"t2", "CURRENT", "DMSNX", "_____N_"},
		{"t3", "TRAIN", "", "_____"},
		{"t4", "TRANSLINE", "TSANLRI", "TRANSLIN_"},
		{"t5", "TRAFFIC", "FCIRTA", "TRAFFIC"},
	}

	for _, test := range tests {
		newWord := convertCurrentWord(test.Word, test.Guesses)
		assert.Equal(t, test.ExpWord, newWord)
	}
}

func Test_finishedStatus(t *testing.T) {
	tests := []struct {
		Tag            string
		FinishedStatus int
		ExpFinished    string
	}{
		{"t1", daos.GameWon, "COMPLETED"},
		{"t2", daos.GameLost, "FAILED"},
		{"t3", daos.GameInProgress, "IN PROGRESS"},
		{"t4", 3, ""},
	}

	for _, test := range tests {
		status := finishedStatus(test.FinishedStatus)
		assert.Equal(t, test.ExpFinished, status)
	}
}

func Test_printTableElement(t *testing.T) {
	tests := []struct {
		Tag  string
		X, Y int
		Text string
		ExpX int
	}{
		{"t1", 3, 5, "COLD", 7},
		{"t1", 6, 1, "COW", 9},
		{"t1", 8, 9, "TRACTOR", 15},
		{"t1", 53, 15, "SLEEP", 58},
	}

	for _, test := range tests {
		newPosition := printTableElement(test.X, test.Y, test.Text)
		assert.Equal(t, test.ExpX, newPosition)
	}
}

func Test_convertToPreparedResponse(t *testing.T) {
	tests := []struct {
		Tag       string
		Input     []daos.LeaderboardBoardData
		ExpOutput []LeaderboardBoard
	}{
		{
			"t1",
			[]daos.LeaderboardBoardData{daos.LeaderboardBoardData{ID: 4, Word: "TRAINING", Guesses: "DCVRE", Points: 40, Finished: 0}},
			[]LeaderboardBoard{LeaderboardBoard{ID: 4, Word: "_R______", Guesses: "DCVRE", Points: "40", Finished: "COMPLETED", Place: "1. "}},
		},
		{
			"t2",
			[]daos.LeaderboardBoardData{
				daos.LeaderboardBoardData{ID: 4, Word: "TRAINING", Guesses: "DCVRE", Points: 40, Finished: 0},
				daos.LeaderboardBoardData{ID: 5, Word: "CAMERA", Guesses: "QWERTXZ", Points: 20, Finished: 1},
				daos.LeaderboardBoardData{ID: 7, Word: "MODULE", Guesses: "FHDBS", Points: 20, Finished: 2},
				daos.LeaderboardBoardData{ID: 3, Word: "TABLE", Guesses: "KMHABC", Points: 0, Finished: 2},
				daos.LeaderboardBoardData{ID: 6, Word: "LAPTOP", Guesses: "DCVXRE", Points: 0, Finished: 1},
			},
			[]LeaderboardBoard{
				LeaderboardBoard{ID: 4, Word: "_R______", Guesses: "DCVRE", Points: "40", Finished: "COMPLETED", Place: "1. "},
				LeaderboardBoard{ID: 5, Word: "___ER_", Guesses: "QWERTXZ", Points: "20", Finished: "FAILED", Place: "2. "},
				LeaderboardBoard{ID: 7, Word: "__D___", Guesses: "FHDBS", Points: "20", Finished: "IN PROGRESS", Place: "3. "},
				LeaderboardBoard{ID: 3, Word: "_AB__", Guesses: "KMHABC", Points: "0", Finished: "IN PROGRESS", Place: "4. "},
				LeaderboardBoard{ID: 6, Word: "______", Guesses: "DCVXRE", Points: "0", Finished: "FAILED", Place: "5. "},
			},
		},
	}

	for _, test := range tests {
		newResponse := convertToPreparedResponse(test.Input)
		assert.Equal(t, test.ExpOutput, newResponse)
	}
}
