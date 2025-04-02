#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int find_movie(const char* filepath, long id){

    FILE* file = fopen(filepath, "rb");

    if (file == NULL)
    {
        return -1;
    }
    
    Movie movie;
    int pos = 0;

    while (fread(&movie, sizeof(Movie), 1, file) == 1)
    {
        if (movie.id == id)
        {
            fclose(file);
            return pos;
        }
        pos++;
    }
    
    fclose(file);

    return -1;
}

int main(){

    // Exemplo de uso da função find_movie
    int pos = find_movie("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex6\\movies.bin", 23); // Deve retornar 5

    if (pos >= 0) {
        printf("Filme encontrado na posicao: %d\n", pos);
    } else {
        printf("Filme não encontrado.\n");
    }

    return 0;
}