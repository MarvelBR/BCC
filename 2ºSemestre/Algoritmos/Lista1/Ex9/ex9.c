#include <stdio.h>

int main(){
    int a, b;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);

    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    float resto = a % b;
    float resto_sem_porcentagem = -1*(b * (a/b) - a);

    printf("O resto da divisao equivale a: %.2f\n", resto);
    printf("O resto da divisao sem porcentagem equivale a: %.2f\n", resto_sem_porcentagem);

    return 0;
}