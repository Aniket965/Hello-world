package daos

import (
	"database/sql"
	"fmt"

	_ "github.com/mattn/go-sqlite3"
)

// Leaderboard passes Database struct pointer. In multi-user case should pass only transactions.
type Leaderboard struct {
	Database *sql.DB
}

type LeaderboardBoardData struct {
	ID       int
	Word     string
	Guesses  string
	Points   int
	Finished int
}

const (
	GameWon = iota
	GameLost
	GameInProgress
)

// SQL statements.
const (
	createTable              string = "CREATE TABLE IF NOT EXISTS leaderboard (id INTEGER PRIMARY KEY, word TEXT, guesses []INTEGER, points INTEGER, finished INTEGER)"
	insertGame               string = "INSERT INTO leaderboard (word, guesses, points, finished) VALUES (?, ?, ?, ?)"
	updateGame               string = "UPDATE leaderboard SET guesses=?, points=?, finished=? WHERE id=?"
	getLeaderboard           string = "SELECT * FROM leaderboard ORDER BY points DESC"
	getLeaderboardFinished   string = "SELECT * FROM leaderboard WHERE finished < 2 ORDER BY points DESC"
	getLeaderboardUnfinished string = "SELECT * FROM leaderboard WHERE finished = 2 ORDER BY id DESC"
	resumeGame               string = "SELECT word, guesses FROM leaderboard WHERE id=?"
	getLastGameID            string = "SELECT id FROM leaderboard WHERE finished = ? ORDER BY id DESC LIMIT 1"
)

func (l *Leaderboard) InitBoard() int {
	l.Database, _ = sql.Open("sqlite3", "./leaderboard.db")
	statement, _ := l.Database.Prepare(createTable)
	statement.Exec()
	return l.GetLastGameID()
}

func (l *Leaderboard) GetLastGameID() int {
	var id int
	row, err := l.Database.Prepare(getLastGameID)
	if err != nil {
		panic(err)
	}
	err = row.QueryRow(GameInProgress).Scan(&id)
	if err != nil {
		return 0
	}
	return id
}

func (l *Leaderboard) ResumeGame(id int) (string, []rune) {
	var oneRow LeaderboardBoardData
	var runes []rune
	row, err := l.Database.Prepare(resumeGame)
	if err != nil {
		panic(err)
	}
	defer row.Close()

	err = row.QueryRow(id).Scan(&oneRow.Word, &oneRow.Guesses)
	if err != nil {
		panic(err)
	}

	for _, c := range oneRow.Guesses {
		runes = append(runes, c)
	}

	return oneRow.Word, runes
}

func (l *Leaderboard) GetBoard() []LeaderboardBoardData {
	var oneRow LeaderboardBoardData
	var fullBoard []LeaderboardBoardData
	rows, _ := l.Database.Query(getLeaderboard)
	for rows.Next() {
		rows.Scan(&oneRow.ID, &oneRow.Word, &oneRow.Guesses, &oneRow.Points, &oneRow.Finished)
		fullBoard = append(fullBoard, oneRow)
	}
	return fullBoard
}

func (l *Leaderboard) GetBoardFinished() []LeaderboardBoardData {
	var oneRow LeaderboardBoardData
	var fullBoard []LeaderboardBoardData
	rows, _ := l.Database.Query(getLeaderboardFinished)
	for rows.Next() {
		rows.Scan(&oneRow.ID, &oneRow.Word, &oneRow.Guesses, &oneRow.Points, &oneRow.Finished)
		fullBoard = append(fullBoard, oneRow)
	}
	return fullBoard
}

func (l *Leaderboard) GetBoardUnfinished() []LeaderboardBoardData {
	var oneRow LeaderboardBoardData
	var fullBoard []LeaderboardBoardData
	rows, _ := l.Database.Query(getLeaderboardUnfinished)
	for rows.Next() {
		rows.Scan(&oneRow.ID, &oneRow.Word, &oneRow.Guesses, &oneRow.Points, &oneRow.Finished)
		fullBoard = append(fullBoard, oneRow)
	}
	return fullBoard
}

func (l *Leaderboard) InsertGame(word string, guesses []rune) int {
	var newRow LeaderboardBoardData
	newRow.Word = word
	newRow.Guesses = string(guesses)
	newRow.Finished = isFinished(word, guesses)
	newRow.Points = calculatePoints(word, guesses, newRow.Finished)
	statement, _ := l.Database.Prepare(insertGame)
	result, err := statement.Exec(newRow.Word, newRow.Guesses, newRow.Points, newRow.Finished)
	if err != nil {
		fmt.Println(err)
	}
	lastID, _ := result.LastInsertId()
	return int(lastID)
}

func (l *Leaderboard) UpdateGame(word string, guesses []rune, id int) {
	var newRow LeaderboardBoardData
	newRow.Guesses = string(guesses)
	newRow.Finished = isFinished(word, guesses)
	newRow.Points = calculatePoints(word, guesses, newRow.Finished)
	statement, _ := l.Database.Prepare(updateGame)
	_, err := statement.Exec(newRow.Guesses, newRow.Points, newRow.Finished, id)
	if err != nil {
		fmt.Println(err)
	}
}

func calculatePoints(word string, guesses []rune, finished int) int {
	switch finished {
	case GameWon:
		points := len(word) * 10

		for i := range guesses {
			penalty := 5
			for _, c := range word {
				if guesses[i] == c {
					penalty = 0
					break
				}
			}
			points = points - penalty
		}

		return points
	default:
		return 0
	}
}

func isFinished(word string, guesses []rune) int {
	wordGuessed := true
	for _, c := range word {
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

	}
	if wordGuessed {
		return GameWon
	}

	var correctGuesses int
	for i := range guesses {
		for _, c := range word {
			if guesses[i] == c {
				correctGuesses++
				break
			}
		}
	}
	if mistakes := len(guesses) - correctGuesses; mistakes >= 6 {
		return GameLost
	}

	return GameInProgress
}
