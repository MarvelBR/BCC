#include <stdio.h>

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    

}

int main(){

    int m1[3][2] = {
        {1, 3},
        {1, 0},
        {1, 2}
    };

    int m2[3][2] = {
        {0, 0},
        {7, 5},
        {2, 1}
    };

    int m3[3][2];

    sum(3, 2, m1, m2, m3);

    return 0;
}