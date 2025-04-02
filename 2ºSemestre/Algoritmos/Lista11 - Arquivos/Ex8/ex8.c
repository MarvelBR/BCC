#include <stdio.h>
#include <stdlib.h>

char* get_content(const char *filepath){

    FILE* file;

    file = fopen(filepath, "r");

    if (file == NULL)
    {
        return NULL;
    }
    
    char ch;
    int i = 1; //por causa do \0
    while ((ch = fgetc(file)) != EOF)
    {
        i++;
    }
    
    char* c = malloc(i * sizeof(char));

    if (c == NULL)
    {
        return NULL;
    }

    fclose(file);
    
    file = fopen(filepath, "r");
    i = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        c[i] = ch;
        i++;
    }

    c[i] = '\0';
    
    fclose(file);
    return c;
}

int main(){

    char* resultado = get_content("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex8\\arquivo.txt");

    if (resultado == NULL)
    {
        printf("Erro na Alocacao");

    } else{
        printf("%s", resultado);
    }
    
    free(resultado);

    return 0;
}