#include <stdio.h>

int check_symmetric(int d, int m[d][d]) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] != m[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int d = 3;
    int m1[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 8}
    };

    if (check_symmetric(d, m1)) {
        printf("A matriz e simetrica.\n");
    } else {
        printf("A matriz nao e simetrica.\n");
    }

    return 0;
}