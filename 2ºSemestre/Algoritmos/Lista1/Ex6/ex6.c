#include <stdio.h>

int main(){

    const float PI = 3.141593;
    float raio;

    printf("Digite o valor do raio do circulo: ");
    scanf("%f", &raio);

    float diametro = 2*raio;
    float circunferencia = 2*PI*raio;
    float areaDoCirculo = PI*raio*raio;

    printf("O diametro e: %.2f\n", diametro);
    printf("A circunferencia e: %.2f\n", circunferencia);
    printf("A area do circulo e: %.2f\n", areaDoCirculo);

    return 0;
}