#include <stdio.h>

int check_upper_triangle(int d, int m[d][d]) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] != 0) {
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
        {0, 5, 6},
        {0, 0, 9}
    };

    if (check_upper_triangle(d, m1)) {
        printf("A matriz e um triangulo superior.\n");
    } else {
        printf("A matriz nao e um triangulo superior.\n");
    }

    return 0;
}