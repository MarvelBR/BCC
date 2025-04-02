#include <stdio.h>

int save_string(const char *filepath, const char* text){

    FILE* file;

    file = fopen(filepath, "w");

    for (int i = 0; text[i] != 0; i++)
    {
        fputc(text[i], file);
    }
    
    fclose(file);

    return 1;
}

int main(){
    int resultado = save_string("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex5\\arquivo.txt", "Teste 120");

    if (resultado == 0)
    {
        printf("ERRO \n");
    } else{
        printf("Arquivo encontrado e reescrito");
    }

    return 0;
}