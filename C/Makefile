CC ?= GCC
CFLAGS += -Wall -O2

# https://stackoverflow.com/a/13963859/2281355
CSRCS = $(shell find . -iname '*.c' | sed 's/ /\\ /g')
BINS = $(shell echo '$(CSRCS)' | sed -e 's/.\/\([^.]*\).c\( \|$$\)/\1.a.out\2/g')

all: $(BINS) world
clean:
	rm -I $(BINS)
world:
	@echo "Hello, world"

%.a.out: %.c
	-$(CC) $(CFLAGS) $< -o "$@"

# files with space in their name are hardcoded now
.c:
	-echo ""
.y.c:
	-echo ""
hello\ .a.out: hello\ .c
implementation\ in\ C.a.out: implementation\ in\ C.c
Producer\ Consumer.a.out: Producer\ Consumer.c
ABCDE\ reverse\ pyramid.a.out: ABCDE\ reverse\ pyramid.c

.PHONY: all clean world

