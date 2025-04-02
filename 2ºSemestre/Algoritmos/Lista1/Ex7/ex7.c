#include <stdio.h>

int main(){

    int a, b, c;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);

    float media = (a+b+c)/3;
    float mediaPonderada = a*0.1 + b*0.5 + c*0.4;

    printf("A media aritmetica dos valores e: %.1f\n", media);
    printf("A media ponderada dos valores e: %.1f\n", mediaPonderada);
    

    return 0;
}