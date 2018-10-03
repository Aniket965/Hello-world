TARGET=hello
INCDIR=.
CC=gcc
CFLAGS=-I$(INCDIR) -Wall -Wextra -O3

OBJ = hello.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ) *~ core
