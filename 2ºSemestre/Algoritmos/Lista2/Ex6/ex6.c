#include <stdio.h>

int main(){

    int a;
    int b;
    int c;
    int d;

    printf("Digite 4 valores: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a >= b && a >= c && a >= d){
        printf("A maior valor digitado foi: %d\n", a);

    } else if (b >= a && b >= c && b >= d) {
        printf("A maior valor digitado foi: %d\n", b);

    } else if (c >= a && c >= b && c >= d) {
        printf("A maior valor digitado foi: %d\n", c);

    } else if (d >= a && d >= b && d >= c) {
        printf("A maior valor digitado foi: %d\n", d);
    }
    


    return 0;
}