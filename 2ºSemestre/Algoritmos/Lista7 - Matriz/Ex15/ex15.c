#include <stdio.h>

int check_identity(int rows, int cols, int m[rows][cols]) {
    if (rows != cols) {
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j && m[i][j] != 1) {
                return 0;
            } else if (i != j && m[i][j] != 0) {
                return 0; 
            }
        }
    }
    return 1;
}

int main() {
    int rows = 3;
    int cols = 3;
    int m1[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    if (check_identity(rows, cols, m1)) {
        printf("A matriz e identidade.\n");
    } else {
        printf("A matriz nao e identidade.\n");
    }

    return 0;
}