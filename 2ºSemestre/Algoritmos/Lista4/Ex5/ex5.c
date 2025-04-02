#include <stdio.h>

int main() {
    int altura, largura;

    printf("Altura x Largura: ");
    scanf("%d %d", &altura, &largura);

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("[]");
        }
        printf("\n");
    }

    return 0;
}