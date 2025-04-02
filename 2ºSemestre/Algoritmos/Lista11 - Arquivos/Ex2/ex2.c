#include <stdio.h>

int check_or_create(const char *filepath){

    FILE* file;

    file = fopen(filepath, "r");

    if (file != NULL)
    {
        return 1;
    }

    fclose(file);

    file = fopen(filepath, "w");

    if (file != NULL)
    {
        return 1;
    }

    fclose(file);

    return 0;
}

int main(){

    int resultado = check_or_create("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex2\\arquivo.txt");

    if (resultado == 0)
    {
        printf("ERRO: Arquivo nao pode ser criado\n");
    } else{
        printf("Arquivo encontrado/criado");
    }
    

    return 0;
}