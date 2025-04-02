#include <stdio.h>

int main(){

    int dias_totais;

    printf("Digite a quantidade de dias: ");
    scanf("%d", &dias_totais);

    float resto_anos = (float)dias_totais/365;
    int anos = resto_anos;
    float resto_semanas = ((resto_anos - anos)*365)/7;
    int semanas = resto_semanas;
    float dias = (resto_semanas - semanas)*7;

    printf("%d ano(s), %d semana(s) e %.0f dias", anos, semanas, dias);

    return 0;
}