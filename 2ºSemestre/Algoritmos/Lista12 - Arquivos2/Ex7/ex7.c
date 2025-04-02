#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[51];
    float price;
} Product;

Product* load_records(const char* filepath, int* n) {

    FILE* file = fopen(filepath, "r");
    if (!file) {
        *n = 0;
        return NULL;
    }

    int count = 0;
    int temp_id;
    char temp_name[51];
    float temp_price;

    while (fscanf(file, "%d %50s %f", &temp_id, temp_name, &temp_price) == 3) {
        count++;
    }

    if (count == 0) {
        fclose(file);
        *n = 0;
        return NULL;
    }

    rewind(file);

    Product* products = (Product*)malloc(count * sizeof(Product));
    if (!products) {
        fclose(file);
        *n = 0;
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        fscanf(file, "%d %50s %f", &products[i].id, products[i].name, &products[i].price);

        for (int j = 0; products[i].name[j] != '\0'; j++) {
            if (products[i].name[j] == '@') {
                products[i].name[j] = ' ';
            }
        }
    }

    fclose(file);
    *n = count; 
    return products;
}

int main() {
    int n;
    Product* produtos = load_records("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex7\\arquivo.txt", &n);

    if (produtos) {
        printf("Produtos carregados (%d encontrados):\n", n);
        for (int i = 0; i < n; i++) {
            printf("ID: %d, Nome: %s, Preco: %.2f\n", produtos[i].id, produtos[i].name, produtos[i].price);
        }
        free(produtos);
    } else {
        printf("Erro ao carregar o arquivo ou arquivo vazio.\n");
    }

    return 0;
}