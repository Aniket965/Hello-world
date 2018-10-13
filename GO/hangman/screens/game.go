package screens

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
	"unicode"

	termbox "github.com/nsf/termbox-go"
)

const (
	NewGame = iota
	Mistake1
	Mistake2
	Mistake3
	Mistake4
	Mistake5
	GameOver
)

var hangmanPaint = [7][9]string{
	{"      _______", "     |/      |", "     |      ", "     |      ", "     |       ", "     |      ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |      ", "     |       ", "     |      ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |       |", "     |       |", "     |      ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |      \\|", "     |       |", "     |      ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |      \\|/", "     |       |", "     |      ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |      \\|/", "     |       |", "     |      / ", "     |", "  ___|___"},
	{"      _______", "     |/      |", "     |      (_)", "     |      \\|/", "     |       |", "     |      / \\", "     |", "  ___|___"},
}

var gameText = "Try to guess this word. Good luck!"
var gameGuesses = "Already guessed: "
var gameWonText = "YOU WON! CONGRATULATIONS!"
var gameOverText = "GAME OVER, YOU LOST!"

func (s *Switch) NewGame() {
	s.GoalWord = getWord()
	s.Guesses = s.Guesses[:0]
	s.CurrentState = GameStarted
	s.GameID = s.DB.InsertGame(s.GoalWord, s.Guesses)
	s.ShowGame()
}

func (s *Switch) ShowGame() {
	if s.GameID == 0 {
		s.NewGame()
		return
	}
	termbox.Clear(termbox.ColorWhite, termbox.ColorBlack)
	s.GoalWord, s.Guesses = s.DB.ResumeGame(s.GameID)
	fmt.Println(s.GoalWord, s.Guesses, s.GameID)
	s.CurrentState = renderGame(s.GoalWord, s.Guesses)
	termbox.Sync()
}

func (s *Switch) AddGuess(c rune) {
	if s.CurrentState == GameFinished {
		return
	}

	c = unicode.ToUpper(c)
	for i := range s.Guesses {
		if s.Guesses[i] == c {
			return
		}
	}
	s.Guesses = append(s.Guesses, c)
	s.DB.UpdateGame(s.GoalWord, s.Guesses, s.GameID)
	s.ShowGame()
}

func renderGame(word string, guesses []rune) GameState {
	var mistakes int
	var correctGuesses int

	for i := range guesses {
		for _, c := range word {
			if guesses[i] == c {
				correctGuesses++
				break
			}
		}
		printSimpleText(gameGuesses, 20, 5)
		termbox.SetCell(i+5, 21, guesses[i], termbox.ColorWhite, termbox.ColorBlack)
	}
	mistakes = len(guesses) - correctGuesses

	if mistakes >= GameOver {
		mistakes = GameOver
		printSimpleText(gameOverText, 2, 5)
		printSimpleText("Correct word: "+word, 4, 5)
		printHangman(mistakes)
		return GameFinished
	} else {
		wordGuessed := true
		for j, c := range word {
			printing := '_'
			for i := range guesses {
				if guesses[i] == c {
					printing = c
					break
				}
			}
			if printing == '_' {
				wordGuessed = false
			}

			termbox.SetCell(j+5, 6, printing, termbox.ColorWhite, termbox.ColorBlack)
		}
		if wordGuessed {
			printSimpleText(gameWonText, 2, 5)
			printHangman(mistakes)
			return GameFinished
		} else {
			printSimpleText(gameText, 2, 5)
			printHangman(mistakes)
			return GameStarted
		}

	}

}

func printSimpleText(text string, yPosition, xPosition int) {
	for j, c := range text {
		termbox.SetCell(j+xPosition, yPosition, c, termbox.ColorWhite, termbox.ColorBlack)
	}
}

func printHangman(mistakes int) {
	for i := range hangmanPaint[mistakes] {
		printSimpleText(hangmanPaint[mistakes][i], i+10, 5)
	}
}

func getWord() string {
	rand.Seed(time.Now().UTC().UnixNano())
	randomWord := WordsList[rand.Intn(len(WordsList))]
	return strings.ToUpper(randomWord)
}
