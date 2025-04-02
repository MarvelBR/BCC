#include <stdio.h>

int main(){

    int x;

    printf("Digite um valor de 5 digitos: ");
    scanf("%d", &x);

    int unidade = x % 10;
    int novo_num1 = x/10;

    int unidade2 = novo_num1 % 10;
    int novo_num2 = novo_num1/10;

    int unidade3 = novo_num2 % 10;
    int novo_num3 = novo_num2/10;

    int unidade4 = novo_num3 % 10;
    int novo_num4 = novo_num3/10;
    
    int unidade5 = novo_num4 % 10;

    printf("%d %d %d %d %d", unidade5, unidade4, unidade3, unidade2, unidade);

    return 0;
}