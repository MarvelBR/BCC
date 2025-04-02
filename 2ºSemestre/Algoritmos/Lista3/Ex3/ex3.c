#include <stdio.h>

int main(){

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    int i = 0;
    int soma = 0;

    while (i < num*2){
        i++;

        if (i % 2 != 0){
            soma += i;
        }
        
    }
    printf("O quadrado de %d = %d", num, soma);
    

    return 0;
}