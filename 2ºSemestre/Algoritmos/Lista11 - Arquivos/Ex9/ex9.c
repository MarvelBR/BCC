#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_words(const char *path, int* words_count) {
    if (path == NULL || words_count == NULL) return NULL;
    
    FILE *file = fopen(path, "r");
    if (!file) return NULL;
    
    *words_count = 0;
    int capacity = 10;
    char **words = malloc(capacity * sizeof(char*));
    if (!words) {
        fclose(file);
        return NULL;
    }
    
    char buffer[100];
    while (fscanf(file, "%99s", buffer) == 1) {
        if (*words_count >= capacity) {
            capacity *= 2;
            char **temp = realloc(words, capacity * sizeof(char*));
            if (!temp) {
                for (int i = 0; i < *words_count; i++) free(words[i]);
                free(words);
                fclose(file);
                return NULL;
            }
            words = temp;
        }
        words[*words_count] = malloc(strlen(buffer) + 1);
        if (!words[*words_count]) {
            for (int i = 0; i < *words_count; i++) free(words[i]);
            free(words);
            fclose(file);
            return NULL;
        }
        strcpy(words[*words_count], buffer);
        (*words_count)++;
    }
    
    fclose(file);
    return words;
}

int main() {
    int count = 0;
    char **words = get_words("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex9\\arquivo.txt", &count);
    
    printf("%d palavras:\n", count);

    if (words) {
        for (int i = 0; i < count; i++) {
            printf("%s\n", words[i]);
            free(words[i]);
        }
        free(words);
    }
    return 0;
}