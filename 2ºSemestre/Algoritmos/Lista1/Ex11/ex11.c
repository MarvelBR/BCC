#include <stdio.h>

int main(){

    float a;

    printf("Digite um valor: ");
    scanf("%f", &a);

    int b = a;
    float c = a - b;

    printf("O valor digitado com 2 casas de precisao: %.2f\n", a);
    printf("A parte inteira = %d e a parte decimal = %.2f\n", b, c);
    printf("Sua representacao em notacao cientifica = %e", a);
    


    return 0;
}
