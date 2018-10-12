package screens

import (
	"fmt"

	"github.com/hitchnsmile/go-hangman/daos"
	_ "github.com/mattn/go-sqlite3"
	termbox "github.com/nsf/termbox-go"
)

type LeaderboardStates int

const (
	ShowLeaderboard LeaderboardStates = iota
	ShowLeaderboardFinished
	ShowLeaderboardUnfinished
)

const (
	leaderboardTitle        = "LEADERBOARD"
	leaderboardSubtitle     = "Choose game you wish to continue"
	leaderboardInstructions = "F2: Show all games | F3: Show completed games | F4: Show games in progress | Navigate with arrow Keys"
)

var leaderboardTableHeader = []string{"PLACE", "POINTS", "WORD", "GUESSSES", "STATUS"}

type LeaderboardBoard struct {
	ID       int
	Place    string
	Word     string
	Guesses  string
	Points   string
	Finished string
}

func (s *Switch) Leaderboard() {
	var boardRaw []daos.LeaderboardBoardData
	s.CurrentState = GameLeaderboard

	switch s.LeaderboardState.Board {
	case ShowLeaderboard:
		boardRaw = s.DB.GetBoard()
	case ShowLeaderboardFinished:
		boardRaw = s.DB.GetBoardFinished()
	case ShowLeaderboardUnfinished:
		boardRaw = s.DB.GetBoardUnfinished()
	}

	if len(boardRaw) == 0 {
		s.LeaderboardState.Selection = 0
	} else if s.LeaderboardState.Selection > len(boardRaw)-1 {
		s.LeaderboardState.Selection = len(boardRaw) - 1
	} else {
		s.LeaderboardState.SelectedID = boardRaw[s.LeaderboardState.Selection].ID
	}

	termbox.Clear(termbox.ColorWhite, termbox.ColorBlack)
	boardData := convertToPreparedResponse(boardRaw)
	drawBoard(boardData, s.LeaderboardState.Selection)
	termbox.Sync()
}

// Handles leaderboard navigation
func (s *Switch) LeaderboardDown() {
	s.LeaderboardState.Selection++
	s.Leaderboard()
}

func (s *Switch) LeaderboardUp() {
	if s.LeaderboardState.Selection > 0 {
		s.LeaderboardState.Selection--
	}
	s.Leaderboard()
}

func drawBoard(data []LeaderboardBoard, selected int) {
	printSimpleText(leaderboardTitle, 2, 5)
	printSimpleText(leaderboardSubtitle, 3, 5)
	printSimpleText(leaderboardInstructions, 4, 5)
	drawTable(6, 5, selected, data)
}

func drawTable(y, x, selected int, rows []LeaderboardBoard) {
	newPosition := x
	for i := 0; i < len(leaderboardTableHeader); i++ {
		maxPosition := newPosition

		if lastPosition := printTableElement(newPosition, y, leaderboardTableHeader[i]); lastPosition > maxPosition {
			maxPosition = lastPosition
		}

		// Ugly switch. But more secure than an additional loop. Problem in LeaderboardBoard struct. Should be fixed.
		switch leaderboardTableHeader[i] {
		case leaderboardTableHeader[0]:
			for j := range rows {
				if lastPosition := printTableElement(newPosition, y+j+1, rows[j].Place); lastPosition > maxPosition {
					maxPosition = lastPosition
				}
				if j == selected {
					printTableElement(x-1, y+j+1, "*")
				}
			}
		case leaderboardTableHeader[1]:
			for j := range rows {
				if lastPosition := printTableElement(newPosition, y+j+1, rows[j].Points); lastPosition > maxPosition {
					maxPosition = lastPosition
				}
			}
		case leaderboardTableHeader[2]:
			for j := range rows {
				if lastPosition := printTableElement(newPosition, y+j+1, rows[j].Word); lastPosition > maxPosition {
					maxPosition = lastPosition
				}
			}
		case leaderboardTableHeader[3]:
			for j := range rows {
				if lastPosition := printTableElement(newPosition, y+j+1, rows[j].Guesses); lastPosition > maxPosition {
					maxPosition = lastPosition
				}
			}
		case leaderboardTableHeader[4]:
			for j := range rows {
				if lastPosition := printTableElement(newPosition, y+j+1, rows[j].Finished); lastPosition > maxPosition {
					maxPosition = lastPosition
				}
			}
		}

		newPosition = maxPosition + 1
	}
}

func printTableElement(x, y int, text string) int {
	for _, c := range text {
		termbox.SetCell(x, y, c, termbox.ColorWhite, termbox.ColorBlack)
		x++
	}
	return x
}

func convertToPreparedResponse(raw []daos.LeaderboardBoardData) []LeaderboardBoard {
	var response []LeaderboardBoard
	for i := range raw {
		var tempResp LeaderboardBoard
		tempResp.ID = raw[i].ID
		tempResp.Place = fmt.Sprintf("%d. ", i+1)
		tempResp.Word = convertCurrentWord(raw[i].Word, raw[i].Guesses)
		tempResp.Points = fmt.Sprint(raw[i].Points)
		tempResp.Guesses = raw[i].Guesses
		tempResp.Finished = finishedStatus(raw[i].Finished)
		response = append(response, tempResp)
	}
	return response
}

func finishedStatus(finished int) string {
	switch finished {
	case daos.GameWon:
		return "COMPLETED"
	case daos.GameLost:
		return "FAILED"
	case daos.GameInProgress:
		return "IN PROGRESS"
	}
	return ""
}

func convertCurrentWord(word string, guesses string) string {
	newWord := ""
	for _, c := range word {
		needToChange := true
		for _, g := range guesses {
			if c == g {
				needToChange = false
			}
		}
		if needToChange {
			newWord = newWord + "_"
		} else {
			newWord = newWord + string(c)
		}
	}

	return newWord
}
