#include <stdio.h>

void switch_diagonals(int d, int m1[d][d]) {
    for (int i = 0; i < d; i++) {
        int temp = m1[i][i];
        m1[i][i] = m1[i][d - i - 1];
        m1[i][d - i - 1] = temp;
    }

    printf("Matriz com diagonais trocadas:\n");
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int d = 3;
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    switch_diagonals(d, m1);

    return 0;
}