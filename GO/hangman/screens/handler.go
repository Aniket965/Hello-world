package screens

import "github.com/hitchnsmile/go-hangman/daos"

type GameState int

const (
	GameMenu GameState = iota
	GameStarted
	GameFinished
	GameLeaderboard
)

// Main struct of whole game. It acts as a session of a player. After small adjustments, can be easily used for multi-user/multiplayer cases
type Switch struct {
	CurrentState     GameState
	MenuState        MenuState
	LeaderboardState struct {
		Board      LeaderboardStates
		Selection  int
		SelectedID int
	}
	GameID   int
	GoalWord string
	Guesses  []rune
	Screen   [][]int
	DB       daos.Leaderboard
}
