#include <stdio.h>

int main(){

    float x;
    printf("Digite um valor: ");
    scanf("%f", &x);

    if (x >= 0) {
        float y = x;
        printf("|x| e = %.2f\n", y);

    } else {
        float y = -x;
        printf("|x| e = %.2f\n", y);
    }
    
    return 0;
}