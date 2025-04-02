#include <stdio.h>

int main(){

    int x;
    int y;
    int z;

    printf("Digite 3 valores: ");
    scanf("%d %d %d", &x, &y, &z);

    if (x > y && x > z){
        if (y > z){
           printf("Em ordem crescente: %d %d %d", x, y, z);
        }
        if (z > y){
           printf("Em ordem crescente: %d %d %d", x, z, y);
        }

    } else if (y > x && y > z){
        if (x > z){
           printf("Em ordem crescente: %d %d %d", y, x, z);
        }
        if (z > x){
           printf("Em ordem crescente: %d %d %d", y, z, x);
        }

    } else if (z > x && z > y){
        if (x > y){
           printf("Em ordem crescente: %d %d %d", z, x, y);
        }
        if (y > x){
           printf("Em ordem crescente: %d %d %d", z, y, x);
        }

    } else if (x == y && x > z){
           printf("Em ordem crescente: %d %d %d", x, y, z);

    } else if (x == z && x > y){
           printf("Em ordem crescente: %d %d %d", x, z, y);

    } else if (x == y && x == z){
           printf("Em ordem crescente: %d %d %d", x, z, y);

    } else if (y == z && y > x){
           printf("Em ordem crescente: %d %d %d", y, z, x);
    }

    return 0;
}