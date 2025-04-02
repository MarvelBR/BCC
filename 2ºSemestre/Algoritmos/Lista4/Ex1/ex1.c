#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int trocar_primeiro_ultimo(int numero) {
    int negativo = numero < 0 ? -1 : 1;
    numero = abs(numero);

    int ultimo_digito = numero % 10;
    int primeiro_digito = numero;
    int divisor = 1;

    while (primeiro_digito >= 10) {
        primeiro_digito /= 10;
        divisor *= 10;
    }

    int parte_do_meio = numero % divisor;
    
    int novo_numero = ultimo_digito * divisor + parte_do_meio;
    novo_numero = novo_numero - (novo_numero % 10) + primeiro_digito;

    return novo_numero * negativo;
}

int main() {
    int numero;
    printf("Informe o numero: ");
    scanf("%d", &numero);

    int resultado = trocar_primeiro_ultimo(numero);
    printf("> %d\n", resultado);

    return 0;
}
