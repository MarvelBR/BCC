CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = barbeiro_dorminhoco
SRC = barbeiro_dorminhoco.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
