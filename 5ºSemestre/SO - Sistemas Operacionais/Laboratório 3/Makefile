CC       = gcc
CFLAGS   = -I. -Wall -Wextra
LIBS     = -lpthread -lm
TARGETS  = busca_vetor_threads matriz_threads

.PHONY: all clean

all: $(TARGETS)

# Exercício 1 - Busca em Vetor
busca_vetor_threads: busca_vetor_threads.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Exercício 2 - Médias de Matriz
matriz.o: matriz/matriz.c matriz/matriz.h
	$(CC) $(CFLAGS) -c -o $@ $<

matriz_threads: matriz_threads.c matriz.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGETS) *.o
