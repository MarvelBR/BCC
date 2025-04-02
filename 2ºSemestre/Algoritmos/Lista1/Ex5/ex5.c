#include <stdio.h>

int main(){

    const float PI = 3.141593;
    float graus;

    printf("Digite o grau: ");
    scanf("%f", &graus);

    float radianos = graus * (PI/180);

    printf("Em radianos: %f rad\n", radianos);

    return 0;
}