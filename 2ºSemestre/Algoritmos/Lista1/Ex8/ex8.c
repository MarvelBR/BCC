#include <stdio.h>

int main(){

    int a, b, c;
    float peso1, peso2, peso3;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);

    printf("Digite o peso do primeiro valor: ");
    scanf("%f", &peso1);
    
    printf("Digite o peso do segundo valor: ");
    scanf("%f", &peso2);
    
    printf("Digite o peso do terceiro valor: ");
    scanf("%f", &peso3);

    float mediaPonderada = (a*peso1 + b*peso2 + c*peso3)/(peso1+peso2+peso3);

    printf("A media ponderada dos valores e = %.1f\n", mediaPonderada);
    

    return 0;
}