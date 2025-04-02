#include <stdio.h>

int file_exists(const char* filepath){

    FILE* file;

    file = fopen(filepath, "r"); //ler

    if (file == NULL)
    {   
        return 0;

    } else{
        return 1;
    }

    fclose(file);
}


int main(){
    int existe = file_exists("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex1\\arquivo.txt");

    if (existe == 0)
    {
        printf("ERRO: Arquivo nao existe\n");
    } else {
        printf("Arquivo encontrado.\n");
    }
    

    return 0;
}