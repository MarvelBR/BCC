#include <stdio.h>

int print_content(const char *filepath){

    FILE* file;

    file = fopen(filepath, "r");

    if (file == NULL)
    {
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n");
    fclose(file);
    
    return 1;
}


int main(){

    int resultado = print_content("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex3\\arquivo.txt");

    if (resultado == 0)
    {
        printf("ERRO: Arquivo nao existe\n");
    } else{
        printf("Arquivo encontrado e lido");
    }

    return 0;
}