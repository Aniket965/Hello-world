package screens

import (
	termbox "github.com/nsf/termbox-go"
)

type MenuState int

const (
	MenuNewGame MenuState = iota
	MenuContinueLastGame
	MenuLeaderboard
)

var menuTexts = [3]string{
	"1) Start a New Game",
	"2) Continue Last Game",
	"3) Leaderboard",
}

var introText = "Welcome to Hangman game! To continue, please select action:"
var introSubtext = "Navigate with arrow keys and press Enter to select. Use backspace to go back after selection."

func (s *Switch) ShowMenu() {
	s.CurrentState = GameMenu
	termbox.Clear(termbox.ColorWhite, termbox.ColorBlack)

	renderMenu(s.MenuState)

	termbox.Sync()
}

// MenuUp, MenuDown and MenuEnter handles navigation in menu
func (s *Switch) MenuUp() {
	if s.MenuState > 0 {
		s.MenuState = s.MenuState - 1
	}
	s.ShowMenu()
}

func (s *Switch) MenuDown() {
	if s.MenuState < 2 {
		s.MenuState = s.MenuState + 1
	}
	s.ShowMenu()
}

func (s *Switch) MenuEnter(selectedLine MenuState) {
	switch selectedLine {
	case MenuNewGame:
		s.NewGame()
	case MenuContinueLastGame:
		s.ShowGame()
	case MenuLeaderboard:
		s.CurrentState = GameLeaderboard
		s.Leaderboard()
	}
}

func renderMenu(selectedLine MenuState) {
	printSimpleText(introText, 2, 5)
	printSimpleText(introSubtext, 3, 5)

	for i := 0; i < len(menuTexts); i++ {
		fg := termbox.ColorWhite
		bg := termbox.ColorBlack
		if i == int(selectedLine) {
			fg = termbox.ColorBlack
			bg = termbox.ColorWhite
		}
		for j, c := range menuTexts[i] {
			termbox.SetCell(j+10, i+5, c, fg, bg)
		}
	}
}
