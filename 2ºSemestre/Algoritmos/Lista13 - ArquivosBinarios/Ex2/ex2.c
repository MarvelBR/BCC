#include <stdio.h>
#include <stdlib.h>

int *read_array(const char *filepath, int *n)
{

    FILE *file = fopen(filepath, "rb");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file); //Calcula o tamanho do arquivo, ao posicionar o cursor em seu final
    *n = file_size / sizeof(int); // Calcula a quantidade de inteiros no arquivo
    rewind(file); // Volta ao início do arquivo

    // Aloca memória para armazenar os inteiros
    int* array = malloc(*n * sizeof(int));

    if (array == NULL)
    {
        return NULL;
    }
    
    fread(array, sizeof(int), *n, file); // Lê os inteiros do arquivo para o vetor
    fclose(file);

    return array;
}

int main()
{
    int n; // Variável que receberá o tamanho do vetor
    // lê arquivo 'dados.bin' para 'v'. Preenche o tamanho de 'v' em 'n'.
    int *v = read_array("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex2\\dados.bin", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    
    free(v);

    return 0;
}