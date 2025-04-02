#include <stdio.h>

int primo(int num){

    if (num < 10)
    {

        if (num == 1 || num == 2 || num == 3 || num == 5 || num == 7 || num == 9)
        {
            return 1;
        } else{
            return 0;
        }
        
    } else {
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0 && num % 9 != 0){
            return 1;
        } else {
            return 0;
        }
        
    }


}


int main(){
    int i;
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while (i <= 100)
    {
        i++;

        if (primo(i) == 1 && num % i == 0)
        {
            printf("%d e fator primo de %d\n", i, num);
        }
    }

    return 0;
}