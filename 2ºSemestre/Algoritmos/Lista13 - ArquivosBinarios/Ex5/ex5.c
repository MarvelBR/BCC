#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie;

Movie read_movie(const char* filepath, int pos){

    FILE* file = fopen(filepath, "rb");
    Movie movie = {0}; // Inicializa o registro como um Movie preenchido com zeros

    if (file == NULL)
    {
        printf("Erro!\n");
        return movie;
    }
    
    // Move o ponteiro para o início do registro especificado
    if (fseek(file, pos * sizeof(Movie), SEEK_SET) != 0) { //fseek() retorna 0 para sucesso ou outro valor quando posição é inválida.
        fclose(file);
        return movie;
    }

    // Lê o registro na posição indicada
    fread(&movie, sizeof(Movie), 1, file);

    fclose(file);
    return movie;
}

int main()
{
    // considerando o exemplo do exercício 3
    Movie movie = read_movie("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex5\\movies.bin", 20); // movie = {8,"Ghosts ofMars "}
    printf("ID: %d\n", movie.id);
    printf("Name: %s\n", movie.nome);

    return 0;
}