#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_words_sep(const char *path, const char* separators, int* words_count) {
    if (path == NULL || separators == NULL || words_count == NULL) return NULL;
    
    FILE *file = fopen(path, "r");
    if (!file) return NULL;
    
    *words_count = 0;
    int capacity = 10;
    char **words = malloc(capacity * sizeof(char*));
    if (!words) {
        fclose(file);
        return NULL;
    }
    
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file)) {
        int start = 0;
        int end = 0;
        int len = strlen(buffer);
        
        while (end <= len) {
            int is_separator = 0;
            for (int k = 0; separators[k] != '\0'; k++) {
                if (buffer[end] == separators[k] || buffer[end] == '\0' || buffer[end] == '\n') {
                    is_separator = 1;
                    break;
                }
            }
            if (is_separator) {
                if (start != end) {
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
                    int word_len = end - start;
                    words[*words_count] = malloc(word_len + 1);
                    if (!words[*words_count]) {
                        for (int i = 0; i < *words_count; i++) free(words[i]);
                        free(words);
                        fclose(file);
                        return NULL;
                    }
                    strncpy(words[*words_count], buffer + start, word_len);
                    words[*words_count][word_len] = '\0';
                    (*words_count)++;
                }
                start = end + 1;
            }
            end++;
        }
    }
    
    fclose(file);
    return words;
}

int main() {
    int count = 0;
    char **words = get_words_sep("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex10\\arquivo.txt", " ,;.:?!-", &count);
    
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