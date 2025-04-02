#include <stdio.h>

int main(){

    int A;
    int B;
    char op;

    printf("    [ CALCULADORA SIMPLES ]\n");

    printf("Digite a operacao: ");
    scanf("%c", &op);
    //printf("\n");

    printf("Digite o primeiro valor: ");
    scanf("%d", &A);
    //printf("\n");

    printf("Digite o segundo valor: ");
    scanf("%d", &B);

    if (op == 43){
        printf("%d %c %d = %.2f", A, op, B, (float)A + B);

    } else if(op == 45){
        printf("%d %c %d = %.2f", A, op, B, (float)A - B);

    } else if(op == 42){
        printf("%d %c %d = %.2f", A, op, B, (float)A * B);

    } else if(op == 47){
        printf("%d %c %d = %.2f", A, op, B, (float)A / B);

    } else if(op == 37){
        printf("%d %c %d = %.2f", A, op, B, A % B);

    }
    
    return 0;
}