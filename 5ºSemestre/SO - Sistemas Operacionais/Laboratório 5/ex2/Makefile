CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11
TARGET  = file_handler

.PHONY: all clean

all: $(TARGET)

$(TARGET): file_handler.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET) dados.txt
