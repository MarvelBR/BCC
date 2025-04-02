#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Informe o numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    if (soma == numero) {
        printf("Divisores de %d: ", numero);
        for (int i = 1; i <= numero / 2; i++) {
            if (numero % i == 0) {
                printf("%d ", i);
                if (i != numero / 2 && (i + 1) <= numero / 2) {
                    printf("+ ");
                }
            }
        }
        printf("= %d\n", soma);
        printf("Numero perfeito? Sim\n");
    } else {
        printf("Numero perfeito? Nao\n");
    }

    return 0;
}