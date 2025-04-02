#include <stdio.h>

int main(){

    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    if (x % 2 == 0){
        printf("O numero e par");
    } else {
        printf("O numero e impar");
    }
    
    return 0;
}