#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int update_movie(const char* filepath, const Movie* movie){

    FILE* file = fopen(filepath, "r+b"); // Abre o arquivo para leitura e escrita binária

    if (file == NULL)
    {
        return 0;
    }
    
    Movie temp;
    int pos = 0;

    while (fread(&temp, sizeof(Movie), 1, file) == 1) {
        if (temp.id == movie->id) {
            // Move o ponteiro para a posição correta
            fseek(file, pos * sizeof(Movie), SEEK_SET);
            
            // Escreve o novo registro na posição encontrada
            fwrite(movie, sizeof(Movie), 1, file);
            fclose(file);
            return 1; // Sucesso
        }
        pos++;
    }

    fclose(file);
    return 0;
}


int main() {

    Movie updated_movie = {10, "The Thing (Remastered)"};

    int resultado = update_movie("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex8\\movies.bin", &updated_movie);

    if (resultado == 0)
    {
        printf("ERRO");
    } else{
        printf("SUCESSO");
    }
    

    return 0;
}