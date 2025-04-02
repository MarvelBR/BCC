#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar palavras e suas contagens
struct WordCount {
    char word[50];  // Tamanho máximo da palavra
    int count;
};

void count_all_words(const char* filepath) {
    if (!filepath) {
        printf("Caminho do arquivo inválido.\n");
        return;
    }

    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct WordCount words[1000];  // Máximo de palavras únicas
    int word_count = 0;
    char temp[51];

    // Lê palavra por palavra do arquivo
    while (fscanf(file, "%50s", temp) == 1) {
        // Remover pontuação manualmente (considerando apenas início e fim)
        int start = 0, end = strlen(temp) - 1;
        
        while ((temp[start] < 'A' || (temp[start] > 'Z' && temp[start] < 'a') || temp[start] > 'z') && start <= end) {
            start++;
        }
        
        while ((temp[end] < 'A' || (temp[end] > 'Z' && temp[end] < 'a') || temp[end] > 'z') && end >= start) {
            temp[end] = '\0';
            end--;
        }

        // Se a palavra só tinha símbolos, ignora (sem `continue`)
        if (start > end) {
            temp[0] = '\0';  // Esvazia a string
        } else {
            // Deslocar caracteres para remover prefixo de símbolos (sem `memmove`)
            int j = 0;
            for (int i = start; i <= end; i++) {
                temp[j++] = temp[i];
            }
            temp[j] = '\0';

            // Converter para minúsculas (sem ctype.h)
            for (int i = 0; temp[i]; i++) {
                if (temp[i] >= 'A' && temp[i] <= 'Z') {
                    temp[i] += 32;  // Transforma em minúscula
                }
            }

            // Verifica se a palavra já está na lista
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i].word, temp) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // Se a palavra não foi encontrada, adiciona à lista
            if (!found && word_count < 1000) {
                strcpy(words[word_count].word, temp);
                words[word_count].count = 1;
                word_count++;
            }
        }
    }

    fclose(file);

    // Imprime a contagem de cada palavra
    printf("Contagem de palavras:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    count_all_words("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex4\\arquivo.txt");
    return 0;
}