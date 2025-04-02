#include <stdio.h> 

struct Movie {
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int delete_movie(const char* filepath, long id) {
    FILE* file = fopen(filepath, "r+b");
    if (file == NULL) {
        return 0;
    }

    Movie temp;
    int pos = 0;

    while (fread(&temp, sizeof(Movie), 1, file) == 1) {
        if (temp.id == id) {
            temp.id = -1;
            
            fseek(file, pos * sizeof(Movie), SEEK_SET);
            fwrite(&temp, sizeof(Movie), 1, file);
            fclose(file);  
            return 1;
        }
        pos++;
    }

    fclose(file);  
    return 0;  
}

int main() {
    int resultado = delete_movie("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex9\\movies.bin", 8);

    if (resultado == 0) {
        printf("ERRO\n");
    } else {
        printf("SUCESSO\n");
    }

    return 0;
}