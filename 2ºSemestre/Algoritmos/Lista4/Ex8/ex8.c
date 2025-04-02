#include <stdio.h>

int main() {
    int linhas;

    printf("Linhas: ");
    scanf("%d", &linhas);

    for (int i = 1; i <= linhas; i++) {
        for (int j = 0; j < linhas - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("[]");
        }
        printf("\n");
    }

    return 0;
}
