#include <stdio.h>

int main(){

    int a;
    int b;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);

    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    int i = 0;
    int c = a;
    int d = b;
    while (c >= d){
        i++;
        c -= d;
    }
    
    printf("%d / %d = %d\n", a, b, i);
    printf("%d %% %d = %d", a, b, c);

    return 0;
}