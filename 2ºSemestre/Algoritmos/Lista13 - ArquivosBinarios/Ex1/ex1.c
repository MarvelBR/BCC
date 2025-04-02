#include <stdio.h>

void write_array(const char *filepath, const int *v, int n){
    
    FILE* file = fopen(filepath, "wb");

    if (file == NULL)
    {
        printf("ERRO");
    }
    
    fwrite(v, sizeof(int), n, file);

    fclose(file);
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cria arquivo 'dados.bin' com conteúdo de 'v'
    write_array("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex1\\dados.bin", v, 10);

    return 0;
}