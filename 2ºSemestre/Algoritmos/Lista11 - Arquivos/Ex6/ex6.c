#include <stdio.h>

int append_string(const char *filepath, const char* text){

    FILE* file;

    file = fopen(filepath, "a");

    if (file == NULL)
    {
        return 0;
    }
    
    for (int i = 0; text[i] != 0; i++)
    {
        fputc(text[i], file);
    }
    
    fclose(file);

    return 1;
}

int main() {

    int resultado = append_string("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex6\\arquivo.txt", "Teste 2");

    if (resultado == 0)
    {
        printf("ERRO\n");
    } else{
        printf("Acrescentado no arquivo!\n");
    }
    
    return 0;
}