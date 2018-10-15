package main

import (
	"github.com/hitchnsmile/go-hangman/events"
	"github.com/hitchnsmile/go-hangman/screens"
	termbox "github.com/nsf/termbox-go"
)

func main() {
	// refer to Switch in screens/handler.go
	var h screens.Switch

	// termbox used to manipulate cells in terminal and distinguish keystrokes
	err := termbox.Init()
	if err != nil {
		panic(err)
	}
	defer termbox.Close()

	// creating channel for all events (keystrokes) and listening for it
	event := make(chan termbox.Event)
	go func() {
		for {
			event <- termbox.PollEvent()
		}
	}()

	// Initializing session with assigning last game ID to it for quick "continue previous" experience
	h.GameID = h.DB.InitBoard()

	// Instantly shows menu
	h.ShowMenu()

	// Handles all keystrokes
	events.EventHandler(event, &h)
}
