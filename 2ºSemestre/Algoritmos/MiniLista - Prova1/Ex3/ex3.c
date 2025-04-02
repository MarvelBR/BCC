#include <stdio.h>

void uncompress(int n, int vec[]) {
    for (int i = 0; i < n; i++) {
        if (vec[i] == -1) {
            int value = vec[i + 1];
            int count = vec[i + 2];
            for (int j = 0; j < count; j++) {
                printf("%d ", value);
            }
            i += 2;
        } else {
            printf("%d ", vec[i]);
        }
    }
    printf("\n");
}

int main() {
    int vec[] = {1, -1, 2, 3, -1, 3, 2, 4, -1, 6, 3, -1, 5, 12};
    int n = sizeof(vec) / sizeof(vec[0]); 
    uncompress(n, vec);
    return 0;
}