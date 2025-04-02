#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int add_movie(const char* filepath, const Movie* movie){

    FILE* file = fopen(filepath, "ab");

    if (file == NULL)
    {
        return 0;
    }
    
    fwrite(movie, sizeof(Movie), 1, file);
    return 1;
}

int main(){

    Movie new_movie = {99, "Prince of Darkness"};

    int resultado = add_movie("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex7\\movies.bin", &new_movie);

    if (resultado == 0)
    {
        printf("ERRO");
    } else{
        printf("SUCESSO");
    }
    

    return 0;
}