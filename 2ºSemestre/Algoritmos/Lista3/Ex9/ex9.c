#include <stdio.h>

int main(){

    int x;
    printf("Digite um numero: ");
    scanf("%d", &x);

    while (x != 0)
    {
        int digito = x % 10;
        int novo_num = x / 10;

        x = novo_num;

        printf("%d\n", digito);
    }
    


    return 0;
}