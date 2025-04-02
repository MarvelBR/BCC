#include <stdio.h>

int main(){

    char x;

    printf("Digite algo: ");
    scanf("%c", &x);

    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
        if (x >= 'a' && x <= 'z'){
            printf("A letra e minuscula\n");
            char maiusc = x-32;
            printf("A letra digitada foi: %c", maiusc);
        }
        else if (x >= 'A' && x <= 'B'){
            printf("A letra e maiuscula\n");
            printf("A letra digitada foi: %c", x);
        }
        
    }

    else{
        printf("Nao e uma letra\n");
    }

    return 0;
}