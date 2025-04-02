#include <stdio.h>
#include <stdlib.h>

void init_random(int rows, int cols, int m[rows][cols], int min, int max) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = rand() % (max - min + 1) + min;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
}


int main(){

    int v[4][6];

    init_random(4, 6, v, 5, 50);

    return 0;
}