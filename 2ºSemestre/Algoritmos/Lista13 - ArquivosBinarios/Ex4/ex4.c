#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int count_movies(const char* filepath){

    FILE* file = fopen(filepath, "rb");

    if (file == NULL)
    {
        return -1;
    }

    fseek(file, 0, SEEK_END); //Move o ponteiro pro final do arquivo!!!
    int file_size = ftell(file);

    int tamanho = file_size / sizeof(Movie);   // A quantidade de registros é o tamanho do arquivo dividido pelo tamanho de um Movie
    
    fclose(file);
    return tamanho;
}

int main()
{
    // considerando o exemplo do exercício anterior
    int size = count_movies("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex4\\movies.bin"); // size = 7

    if (size >= 0) {
        printf("Quantidade de filmes: %d\n", size);
    } else {
        printf("Erro ao contar filmes no arquivo.\n");
    }

    return 0;
}