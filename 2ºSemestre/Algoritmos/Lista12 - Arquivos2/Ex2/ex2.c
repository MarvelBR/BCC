#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_word(const char* filepath, const char* old_str, const char* new_str) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        return -1; 
    }

    char temp_filename[] = "temp_replace.txt";
    FILE* temp_file = fopen(temp_filename, "w");
    if (!temp_file) {
        fclose(file);
        return -1; 
    }

    char buffer[1024];
    int count = 0;
    size_t old_len = strlen(old_str);
    size_t new_len = strlen(new_str);

    while (fgets(buffer, sizeof(buffer), file)) {
        char* read_ptr = buffer;
        
        while (*read_ptr) {
            int match = 1;
            for (size_t i = 0; i < old_len; i++) {
                if (read_ptr[i] != old_str[i]) {
                    match = 0;
                    break;
                }
            }

            if (match) {
                fwrite(new_str, sizeof(char), new_len, temp_file);
                read_ptr += old_len;
                count++;
            } else {
                fputc(*read_ptr, temp_file);
                read_ptr++;
            }
        }
    }

    fclose(file);
    fclose(temp_file);

    if (remove(filepath) != 0 || rename(temp_filename, filepath) != 0) {
        return -1;
    }

    return count;
}

int main() {

    int result = replace_word("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex2\\arquivo.txt","Teste","exemplo");
    
    if (result >= 0) {
        printf("Substituicoes realizadas: %d\n", result);
    } else {
        printf("Erro ao processar o arquivo.\n");
    }

    return 0;
}