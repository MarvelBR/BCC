#include <stdio.h>

int main(){

    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    if (num < 10)
    {

        if (num == 1 || num == 2 || num == 3 || num == 5 || num == 7 || num == 9)
        {
            printf("O numero e primo");
        } else{
            printf("Nao e primo");
        }
        
    } else {
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0 && num % 9 != 0){
            printf("O numero e primo");
        } else {
            printf("Nao e primo");
        }
        
    }

    return 0;
}