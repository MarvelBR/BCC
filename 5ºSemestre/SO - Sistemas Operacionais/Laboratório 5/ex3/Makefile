CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11
TARGET  = vetor_soma

.PHONY: all clean

all: $(TARGET)

$(TARGET): vetor_soma.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
