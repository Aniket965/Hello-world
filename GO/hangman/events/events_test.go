package events

import (
	"testing"

	"github.com/magiconair/properties/assert"
)

func Test_defaultLog(t *testing.T) {
	tests := []struct {
		Tag, ExpString string
	}{
		{"t1", "Something went wrong"},
	}
	for _, test := range tests {
		newString := defaultLog()
		assert.Equal(t, test.ExpString, newString)
	}
}
