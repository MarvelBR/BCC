#include <stdio.h>

int main(){
    char a = 'a';
    char* p_a = &a;

    int x = 10;
    int* p_x = &x;

    double y = 35.5;
    double* p_y = &y; 

    printf("a: %c\n", a);
    printf("&a: %p\n", &a);
    
    printf("*p_a: %c\n", *p_a);
    printf("p_a: %p\n", p_a);

    printf("x: %d\n", x);
    printf("&x: %p\n", &x);

    printf("*p_x: %d\n", *p_x);
    printf("p_x: %p\n", p_x);

    printf("y: %f\n", y); //valor
    printf("&y: %p\n", &y); //endereço

    printf("*p_y: %f\n", *p_y); //valor
    printf("p_y: %p\n", p_y); //endereço
    

    return 0;
}