#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_word(const char* filepath, const char* word){

    FILE* file = fopen(filepath, "r");
    if(file == NULL){
        return -1;
    }

    char buffer[1000];
    int count = 0;
    while(fscanf(file, "%s", buffer) == 1){
        if(strcmp(buffer, word) == 0){
            count++;
        }
    }

    fclose(file);
    return count;

}


int main(){

    int resultado = count_word("C:\\Users\\erick\\Documents\\Algoritmos\\Lista12 - Arquivos2\\Ex1\\arquivo.txt", "Teste");

    if(resultado == -1){
        printf("Erro ao abrir o arquivo\n"); 
    }
    else{
        printf("A palavra 'Teste' aparece %d vezes no arquivo\n", resultado);
    }


    return 0;
}