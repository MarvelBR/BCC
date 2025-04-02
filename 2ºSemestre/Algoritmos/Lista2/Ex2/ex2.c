#include <stdio.h>

int main(){

    int x;

    printf("Digite um valor entre 0 e 9: ");
    scanf("%d", &x);

    if (0 <= x && x <= 9) {
       if (x == 0){
        printf("Zero\n");
       }
       if (x == 1){
        printf("Um\n");
       }
       if (x == 2){
        printf("Dois\n");
       }
       if (x == 3){
        printf("Tres\n");
       }
       if (x == 4){
        printf("Quatro\n");
       }
       if (x == 5){
        printf("Cinco\n");
       }
       if (x == 6){
        printf("Seis\n");
       }
       if (x == 7){
        printf("Sete\n");
       }
       if (x == 8){
        printf("Oito\n");
       }
       if (x == 9){
        printf("Nove\n");
       }
       
    } else {
        printf("ERRO!");
    }
    
    return 0;
}