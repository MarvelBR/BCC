#include <stdio.h>

int main(){
    int x = 1;
    int i = -1;
    int soma = 0;
    while (x != 0){
        i++;
        printf("Digite um novo valor: ");
        scanf("%d", &x);
        soma += x;
    }
    printf("Soma: %d\n", soma);
    printf("Media: %.2f", (float)soma/i);

    return 0;
}