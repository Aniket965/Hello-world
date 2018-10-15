package migration

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"log"
	"os"
)

func ImportAMPDealerDB(filepath string) error{
	if _, err := os.Stat(filepath); !os.IsNotExist(err){
		csvFile, err := os.Open(filepath)
		defer csvFile.Close()

		reader := csv.NewReader(bufio.NewReader(csvFile))

		if err != nil {
			fmt.Println(err)
		}

		for {
			cols, err := reader.Read()

			if err == io.EOF {
				break
			} else if err != nil {
				log.Fatal(err)
			}
            //Work through csv file data here

		}

	}
	return nil
}
