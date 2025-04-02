#include <stdio.h>
#include <stdlib.h>

struct Movie {
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int insert_sorted(const char* filepath, const Movie* movie) {
    FILE *file = fopen(filepath, "r+b");
    if (!file) {
        return 0;
    }

    Movie current;
    long insert_pos = -1;

    while (fread(&current, sizeof(Movie), 1, file)) {
        if (current.id > movie->id) {
            insert_pos = ftell(file) - sizeof(Movie);
            break;
        }
    }

    if (insert_pos == -1) {
        fseek(file, 0, SEEK_END);
        if (fwrite(movie, sizeof(Movie), 1, file) != 1) {
            fclose(file);
            return 0;
        }
    } else {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        long move_size = file_size - insert_pos;

        char *buffer = (char*)malloc(move_size);
        if (!buffer) {
            fclose(file);
            return 0;
        }

        fseek(file, insert_pos, SEEK_SET);
        if (fread(buffer, 1, move_size, file) != (size_t)move_size) {
            free(buffer);
            fclose(file);
            return 0;
        }

        fseek(file, insert_pos, SEEK_SET);
        if (fwrite(movie, sizeof(Movie), 1, file) != 1) {
            free(buffer);
            fclose(file);
            return 0;
        }

        if (fwrite(buffer, 1, move_size, file) != (size_t)move_size) {
            free(buffer);
            fclose(file);
            return 0;
        }

        free(buffer);
    }

    fclose(file);
    return 1;
}

int main() {
    Movie new_movie = {30, "New Movie40"};

    if (insert_sorted("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex10\\movies.bin", &new_movie)) {
        printf("Registro inserido com sucesso.\n");
    } else {
        printf("Erro ao inserir o registro.\n");
    }

    return 0;
}