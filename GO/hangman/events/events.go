package events

import (
	"unicode"

	"github.com/hitchnsmile/go-hangman/screens"
	termbox "github.com/nsf/termbox-go"
)

// Listens to all keystrokes and acts accordingly
func EventHandler(event chan termbox.Event, h *screens.Switch) {
	for {
		select {
		case e := <-event:
			if e.Type == termbox.EventKey {
				switch {
				case e.Key == termbox.KeyEsc || e.Key == termbox.KeyCtrlC:
					return
				case e.Key == termbox.KeyF2:
					if h.CurrentState == screens.GameLeaderboard {
						h.LeaderboardState.Board = screens.ShowLeaderboard
						h.Leaderboard()
					}
				case e.Key == termbox.KeyF3:
					if h.CurrentState == screens.GameLeaderboard {
						h.LeaderboardState.Board = screens.ShowLeaderboardFinished
						h.Leaderboard()
					}
				case e.Key == termbox.KeyF4:
					if h.CurrentState == screens.GameLeaderboard {
						h.LeaderboardState.Board = screens.ShowLeaderboardUnfinished
						h.Leaderboard()
					}
				case e.Key == termbox.KeyBackspace2 || e.Key == termbox.KeyBackspace:
					h.ShowMenu()
				case e.Key == termbox.KeyArrowDown:
					if h.CurrentState == screens.GameMenu {
						h.MenuDown()
					} else if h.CurrentState == screens.GameLeaderboard {
						h.LeaderboardDown()
					}
				case e.Key == termbox.KeyArrowUp:
					if h.CurrentState == screens.GameMenu {
						h.MenuUp()
					} else if h.CurrentState == screens.GameLeaderboard {
						h.LeaderboardUp()
					}
				case e.Key == termbox.KeyEnter:
					if h.CurrentState == screens.GameMenu {
						h.MenuEnter(h.MenuState)
					} else if h.CurrentState == screens.GameLeaderboard {
						h.GameID = h.LeaderboardState.SelectedID
						h.MenuEnter(screens.MenuContinueLastGame)
					}
				case e.Ch > 0:
					if h.CurrentState == screens.GameStarted {
						if unicode.IsLetter(e.Ch) {
							h.AddGuess(e.Ch)
						}
					}
				}
			}
		default:
		}
	}
}

// not really doing anything. Added just to have something easy to test in this package
func defaultLog() string {
	return "Something went wrong"
}
