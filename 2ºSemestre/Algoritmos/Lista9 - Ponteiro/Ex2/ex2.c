#include <stdio.h>

void add(int* a, int* b){
    int soma = *a + *b;

    *a = soma;
}

int main(){
    int a = 10;
    int b = 20;

    add(&a, &b);

    printf("%d", a);

    return 0;
}