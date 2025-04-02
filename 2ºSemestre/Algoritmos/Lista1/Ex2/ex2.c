#include <stdio.h>

int main(){

    int a;
    int b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    int soma = a + b;
    int sub = a - b;

    printf("A soma dos 2 numeros resulta em: %d\n", soma);
    printf("A subtracao dos 2 numeros resulta em: %d\n", sub);

    return 0;
}