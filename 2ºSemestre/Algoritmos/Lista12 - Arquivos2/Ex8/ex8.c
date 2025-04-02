#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[101];
    char value[101];
} Pair;

// Função para remover espaços extras no início e fim de uma string
void trim(char* str) {
    int start = 0, end = strlen(str) - 1;

    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }

    while (end > start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\r')) {
        end--;
    }

    int length = end - start + 1;
    memmove(str, str + start, length);
    str[length] = '\0';  
}

Pair* load_ini_file(const char* filepath, int* n) {

    FILE* file = fopen(filepath, "r");
    if (!file) {
        *n = 0;
        return NULL;
    }

    Pair* pairs = NULL;
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        trim(line);

        char* equal_sign = strchr(line, '=');
        if (!equal_sign) {
            continue;
        }

        *equal_sign = '\0'; 
        char* key = line;
        char* value = equal_sign + 1;

        trim(key);
        trim(value);

        Pair* new_pairs = realloc(pairs, (count + 1) * sizeof(Pair));
        if (!new_pairs) {
            fclose(file);
            free(pairs);
            *n = 0;
            return NULL;
        }
        pairs = new_pairs;

        strncpy(pairs[count].key, key, 100);
        pairs[count].key[100] = '\0';
        strncpy(pairs[count].value, value, 100);
        pairs[count].value[100] = '\0';
        count++;
    }

    fclose(file);
    *n = count;

    return pairs;
}

int main() {
    int n;
    Pair* pares = load_ini_file("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex8\\config.ini", &n);

    if (pares) {
        printf("Configurações carregadas (%d pares encontrados):\n", n);
        for (int i = 0; i < n; i++) {
            printf("Chave: \"%s\", Valor: \"%s\"\n", pares[i].key, pares[i].value);
        }
        free(pares);
    } else {
        printf("Erro ao carregar o arquivo ou arquivo vazio.\n");
    }

    return 0;
}