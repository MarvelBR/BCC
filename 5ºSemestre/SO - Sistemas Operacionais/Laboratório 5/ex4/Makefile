CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11
TARGETS = server client

.PHONY: all clean

all: $(TARGETS)

server: server.c
	$(CC) $(CFLAGS) -o $@ $<

client: client.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) $(SOCKET_PATH)
	rm -f /tmp/traducao_socket
