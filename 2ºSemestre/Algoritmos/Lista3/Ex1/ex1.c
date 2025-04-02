#include <stdio.h>

int main(){

    int N;
    int i = 1;
    printf("Digite o numero de linhas: ");
    scanf("%d", &N);

    while (N >= i){
        printf("Linha %d\n", N);
        N--;
    }
    
    return 0;
}