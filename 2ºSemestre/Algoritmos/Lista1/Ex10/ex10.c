#include <stdio.h>

int main(){

    int a;

    printf("Digite um valor: ");
    scanf("%d", &a);

    int tabuada_1 = a*1;
    int tabuada_2 = a*2;
    int tabuada_3 = a*3;
    int tabuada_4 = a*4;
    int tabuada_5 = a*5;
    int tabuada_6 = a*6;
    int tabuada_7 = a*7;
    int tabuada_8 = a*8;
    int tabuada_9 = a*9;
    int tabuada_10 = a*10;

    printf("%d x 1 = %2d\n", a, tabuada_1);
    printf("%d x 2 = %2d\n", a, tabuada_2);
    printf("%d x 3 = %2d\n", a, tabuada_3);
    printf("%d x 4 = %2d\n", a, tabuada_4);
    printf("%d x 5 = %2d\n", a, tabuada_5);
    printf("%d x 6 = %2d\n", a, tabuada_6);
    printf("%d x 7 = %2d\n", a, tabuada_7);
    printf("%d x 8 = %2d\n", a, tabuada_8);
    printf("%d x 9 = %2d\n", a, tabuada_9);
    printf("%d x 10 = %2d\n", a, tabuada_10);



    return 0;
}