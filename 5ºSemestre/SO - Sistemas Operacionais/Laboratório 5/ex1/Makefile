CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11
TARGETS = writer reader

.PHONY: all clean

all: $(TARGETS)

writer: writer.c
	$(CC) $(CFLAGS) -o $@ $<

reader: reader.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) /tmp/fifo_ex1_strings
