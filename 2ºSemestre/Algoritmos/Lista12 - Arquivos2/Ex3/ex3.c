#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void report_by_chars(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int word_counts[101] = {0}; 
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *start = buffer;
        char *end = buffer;

        while (*end != '\0') {
            // Encontrar o início de uma palavra
            while (*start != '\0' && (*start == ' ' || *start == ',' || *start == ';' || *start == '.' || *start == ':' || *start == '?' || *start == '!' || *start == '-' || *start == '\n')) {
                start++;
            }

            // Encontrar o final da palavra
            end = start;
            while (*end != '\0' && *end != ' ' && *end != ',' && *end != ';' && *end != '.' && *end != ':' && *end != '?' && *end != '!' && *end != '-' && *end != '\n') {
                end++;
            }

            // Calcular o comprimento da palavra
            int length = end - start;
            if (length > 0 && length < 101) {
                word_counts[length]++;
            }

            start = end;
        }
    }

    fclose(file);

    printf("Arquivo: %s\n", filepath);
    printf("Contagem de palavras por quantidade de letras:\n");
    for (int i = 1; i < 101; i++) {
        if (word_counts[i] > 0) {
            printf("> %d letra%s: %d\n", i, (i > 1) ? "s" : "", word_counts[i]);
        }
    }
}

int main() {
    
    report_by_chars("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex3\\arquivo.txt");
    return 0;
}