#include <stdio.h>

int main(){

    int num;
    int fibonacci;
    int termo1 = 1;
    int termo2 = 1;

    printf("Digite o numero: ");
    scanf("%d", &num);

    if (num == 1 || num == 2)
    {
        fibonacci = 1;
    }
    

    int i = 3;
    while (i <= num){
        i++;

        fibonacci = termo1 + termo2;
        termo1 = termo2;
        termo2 = fibonacci;
        
    }
    
    printf("O %d termo da serie de Fibonacci = %d", num, fibonacci);

    return 0;
}