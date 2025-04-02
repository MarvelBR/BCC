#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[51];
    float price;
} Product;

int save_records(const char* filepath, int n, const Product* prods) {

    FILE* file = fopen(filepath, "w");
    if (!file) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        char temp_name[51];
        strcpy(temp_name, prods[i].name);

        for (int j = 0; temp_name[j] != '\0'; j++) {
            if (temp_name[j] == ' ') {
                temp_name[j] = '@';
            }
        }

        fprintf(file, "%d %s %.6f\n", prods[i].id, temp_name, prods[i].price);
    }

    fclose(file);
    return 1;
}

int main() {
    Product produtos[] = {
        {4, "Monitor Axer", 970.0},
        {2, "Mouse Optron", 102.0},
        {89, "Teclado Pell", 130.0}
    };

    if (save_records("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex6\\arquivo.txt", 3, produtos)) {
        printf("Arquivo salvo com sucesso!\n");
    } else {
        printf("Erro ao salvar o arquivo.\n");
    }

    return 0;
}