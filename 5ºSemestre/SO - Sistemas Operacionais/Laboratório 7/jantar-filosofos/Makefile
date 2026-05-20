CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = jantar_filosofos
SRC = jantar_filosofos.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
