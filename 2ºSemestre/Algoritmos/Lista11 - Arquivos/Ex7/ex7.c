#include <stdio.h>

int save_lines(const char *filepath, int n, const char text_lines[n][51]){

    FILE* file;

    file = fopen(filepath, "w");

    if (file == NULL)
    {
        return 0;
    }
    
    int count = 0;
    int count_atual = 0;
    for (int i = 0; i < n; i++)
    {
        fputs(text_lines[i], file);
        
        if (count > count_atual)
        {
            count_atual = count;
        }

        if (count_atual != count-1)
        {
            fputc('\n', file);
        }
        count++;
    }

    fclose(file);
    
    return 1;
}


int main(){

    const char linhas[3][51] = {
        "Linha 1: Olá, mundo!",
        "Linha 2: Essa é uma linha de teste.",
        "Linha 3: Última linha do arquivo."
    };

    int resultado = save_lines("C:\\Users\\erick\\Documents\\Algoritmos\\Lista11 - Arquivos\\Ex7\\arquivo.txt", 3, linhas);

    if (resultado == 0)
    {
        printf("ERRO\n");
    } else{
        printf("Recriado!\n");
    }

    return 0;
}