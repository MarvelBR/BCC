#include <stdio.h>

int main(){
    int a;
    int b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    int mult = a * b;
    int divInt = a / b;
    float divFloat = (float)a / b;

    printf("A multiplicacao dos numeros resulta em: %d\n", mult);
    printf("A divisao inteira dos numeros resulta em: %d\n", divInt);
    printf("A divisao flutuante dos numeros resulta em: %.2f\n", divFloat);

    return 0;
}