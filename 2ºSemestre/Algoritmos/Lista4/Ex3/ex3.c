#include <stdio.h>

int converter_para_binario(int numero) {
    int binario = 0, fator = 1;

    while (numero > 0) {
        int resto = numero % 2;
        binario += resto * fator;
        fator *= 10;
        numero /= 2;
    }

    return binario;
}

int main() {
    int numero;
    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("O número deve ser positivo!\n");
        return 1;
    }

    int binario = converter_para_binario(numero);
    printf("%d (decimal) = %d (binario)\n", numero, binario);

    return 0;
}