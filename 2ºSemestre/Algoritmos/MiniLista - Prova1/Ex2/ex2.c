#include <stdio.h>

void vec_to_str(int n, int vec[], char str[]) {
    int pos = 0; 

    for (int i = 0; i < n; i++) {
        if (vec[i] < 0) {
            str[pos++] = '(';
            int abs_value = -vec[i];
            if (abs_value >= 10) {
                str[pos++] = (abs_value / 10) + '0';
                str[pos++] = (abs_value % 10) + '0';
            } else {
                str[pos++] = abs_value + '0';
            }
            str[pos++] = ')';
        } else {
            if (vec[i] >= 10) {
                str[pos++] = (vec[i] / 10) + '0';
                str[pos++] = (vec[i] % 10) + '0';
            } else {
                str[pos++] = vec[i] + '0';
            }
        }

        if (i < n - 1) {
            str[pos++] = ' ';
        }
    }

    str[pos] = '\0';
}

int main() {
    int v[] = {1, 2, -6, 7, 9, -1, 2};
    char st[20];
    vec_to_str(7, v, st);
    printf("%s", st); // Saída: "1 2 (6) 7 9 (1) 2"
    return 0;
}