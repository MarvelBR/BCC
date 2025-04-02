#include <stdio.h>

int main(){

    char x;

    printf("Digite algo: ");
    scanf("%c", &x);

    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')){
        printf("E uma letra, ");
        if (x != 'A' && x != 'E' && x != 'I' && x != 'O' && x != 'U' && x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u')
        {
            printf("consoante");
        } else{
            printf("vogal");
        }
        
    } else if (x >= '0' && x <= '9'){
        printf("E um numero");

    } else if ((x >= 33 && x <= 47) || (x >= 58 && x <= 64) || (x >= 92 && x <= 96) || (x >= 123 && x <= 126)){
        printf("E um simbolo");
    }
    
    return 0;
}