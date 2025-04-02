#include <stdio.h>
#include <string.h>

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '.' || c == ',';
}

int compare_words(const char *str, const char *word, int word_len) {
    for (int i = 0; i < word_len; i++) {
        if (str[i] != word[i]) {
            return 0;
        }
    }
    return 1;
}

int count_occurrences(int n, int len, char lines[n][len], char word[]) {
    int count = 0;
    int word_len = strlen(word);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= len - word_len; j++) {
            // Verifica se a substring atual corresponde à palavra
            if (compare_words(&lines[i][j], word, word_len)) {
                // Verifica se a palavra encontrada é uma palavra completa
                if ((j == 0 || is_space(lines[i][j - 1])) && 
                    (is_space(lines[i][j + word_len]) || lines[i][j + word_len] == '\0')) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    char v[5][200] = {
        "computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
        "programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language.",
        "the source code of a program is written in one or more programming languages.",
        "the purpose of programming is to find a sequence of instructions that will automate the performance of a task for solving a given problem.",
        "the process of programming thus often requires expertise in several different subjects, including knowledge of the application domain, specialized algorithms, and formal logic."
    };

    int count = count_occurrences(5, 200, v, "programming");
    printf("Numero de ocorrencias: %d\n", count); //6

    return 0;
}