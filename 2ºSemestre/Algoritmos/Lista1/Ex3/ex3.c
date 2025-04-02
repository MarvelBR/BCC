#include <stdio.h>

int main(){
    float a;
    float b;

    printf("Digite o valor do primeiro lado do retangulo: ");
    scanf("%f", &a);

    printf("Digite o valor do segundo lado do retangulo: ");
    scanf("%f", &b);

    float perimetro = 2*a + 2*b;
    float area = a*b;

    printf("O perimetro desse retangulo tem tamanho: %.2f\n", perimetro);
    printf("A area desse retangulo tem tamanho: %.2f\n", area);

    return 0;
}