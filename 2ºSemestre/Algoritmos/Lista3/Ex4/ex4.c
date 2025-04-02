#include <stdio.h>

int main(){

    int x;
    int y;

    printf("Digite o primeiro valor: ");
    scanf("%d", &x);

    printf("Digite o segundo valor: ");
    scanf("%d", &y);

    int i = 0;
    int soma = 0;
    while (i < y){
        i++;
        soma += x;
    }
    
    printf("%d x %d = %d", x, y, soma);

    return 0;
}