#include <stdio.h>

int count_lines(const char *filepath){

    FILE* file;
    int count = 1;

    file = fopen(filepath, "r");

    if (file == NULL)
    {
        count = -1;   
    }

    char ch;
    
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
        
    }

    printf("\n");
    fclose(file);
    
    return count;
}


int main(){

    int resultado = count_lines("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex4\\arquivo.txt");
    
    if (resultado == -1)
    {
        printf("ERRO: Arquivo nao existe\n");
    } else{
        printf("O arquivo tem %d linhas!", resultado);
    }
    
    return 0;
}