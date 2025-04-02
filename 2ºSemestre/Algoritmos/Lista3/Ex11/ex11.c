#include <stdio.h>

int main(){

    int x;
    int inverso = 0;
    printf("Digite um numero: ");
    scanf("%d", &x);

    int original = x;

    while (x != 0)
    {
        int digito = x % 10;
        inverso = inverso * 10 + digito;
        x = x / 10;

    }

    if (original == inverso)
    {
        printf("%d = %d, Palindromo!", original, inverso);
    } else{
        printf("%d != %d, Nao e palindromo!", original, inverso);
    }
    

    return 0;
}