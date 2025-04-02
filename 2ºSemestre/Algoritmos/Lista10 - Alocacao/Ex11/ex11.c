#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, int* n) {
    if (str == NULL || n == NULL) return NULL;
    
    *n = 0;
    int capacity = 10; // Capacidade inicial do vetor de strings
    char** result = malloc(capacity * sizeof(char*));
    if (!result) return NULL;
    
    int len = 0;
    while (str[len] != '\0') len++;
    
    char buffer[100];
    int buf_index = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (buf_index > 0) {
                buffer[buf_index] = '\0';
                result[*n] = malloc((buf_index + 1) * sizeof(char));
                if (!result[*n]) {
                    for (int j = 0; j < *n; j++) free(result[j]);
                    free(result);
                    return NULL;
                }
                
                for (int j = 0; j <= buf_index; j++) {
                    result[*n][j] = buffer[j];
                }
                (*n)++;
                buf_index = 0;
            }
        } else {
            buffer[buf_index++] = str[i];
        }
    }
    return result;
}

int main() {
    char str[] = " Texto de teste com varias palavras ";
    int size = 0;
    char** tokens = split(str, &size);
    
    printf("Sao %d palavras, sendo elas: \n", size);

    if (tokens) {
        for (int i = 0; i < size; i++) {
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
    }

    

    return 0;
}