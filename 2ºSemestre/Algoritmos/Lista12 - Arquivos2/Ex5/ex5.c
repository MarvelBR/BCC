#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para remover pontuação e contar letras válidas
int limpar_palavra(char* palavra) {
    int tamanho = 0, i, j = 0;
    
    for (i = 0; palavra[i] != '\0'; i++) {
        if ((palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= 'a' && palavra[i] <= 'z')) {
            if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
                palavra[j] = palavra[i] + 32;  
            } else {
                palavra[j] = palavra[i];
            }
            j++;
            tamanho++;
        }
    }
    
    palavra[j] = '\0'; 
    return tamanho;
}

char** get_words(const char* filepath, int letters) {

    FILE* file = fopen(filepath, "r");
    if (!file) {
        return NULL;
    }

    char** palavras = NULL;
    char temp[51];
    int count = 0;

    while (fscanf(file, "%50s", temp) == 1) {
        int tamanho = limpar_palavra(temp);

        if (tamanho == letters) {
            char** novo_vetor = realloc(palavras, (count + 1) * sizeof(char*));
            if (!novo_vetor) {
                fclose(file);
                return NULL;
            }
            palavras = novo_vetor;

            palavras[count] = malloc((letters + 1) * sizeof(char));
            if (!palavras[count]) {
                fclose(file);
                return NULL;
            }

            strcpy(palavras[count], temp);
            count++;
        }
    }

    fclose(file);

    // Adiciona um ponteiro NULL ao final para indicar término do vetor
    char** final_vetor = realloc(palavras, (count + 1) * sizeof(char*));
    if (!final_vetor) {
        return NULL;
    }
    palavras = final_vetor;
    palavras[count] = NULL;

    return palavras;
}

int main() {

    char** resultado = get_words("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex5\\arquivo.txt", 11);
    if (resultado) {
        printf("Palavras com %d letras:\n", 11);
        for (int i = 0; resultado[i] != NULL; i++) {
            printf("%s\n", resultado[i]);
            free(resultado[i]); 
        }
        free(resultado); 
    } else {
        printf("Nenhuma palavra encontrada ou erro ao abrir arquivo.\n");
    }

    return 0;
}
