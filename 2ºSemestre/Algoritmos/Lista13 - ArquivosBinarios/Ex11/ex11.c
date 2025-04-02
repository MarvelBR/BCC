#include <stdio.h>
#include <stdlib.h>

struct Movie {
    int id;
    char nome[100];
};

typedef struct Movie Movie;

int defrag(const char* filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        return 0;
    }

    FILE *temp_file = fopen("temp.bin", "wb");
    if (!temp_file) {
        fclose(file);
        return 0;
    }

    Movie current;
    while (fread(&current, sizeof(Movie), 1, file)) {
        if (current.id != -1) {
            if (fwrite(&current, sizeof(Movie), 1, temp_file) != 1) {
                fclose(file);
                fclose(temp_file);
                return 0;
            }
        }
    }

    fclose(file);
    fclose(temp_file);

    if (remove(filepath) != 0) {
        return 0;
    }
    if (rename("temp.bin", filepath) != 0) {
        return 0;
    }

    return 1;
}

int main() {
    if (defrag("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex11\\movies.bin")) {
        printf("Desfragmentacao concluida com sucesso.\n");
    } else {
        printf("Erro ao desfragmentar o arquivo.\n");
    }

    return 0;
}