#include <stdio.h>


void print_matriz(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d \n", m[i][j]);
        }
    }

}


int main(){

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print_matriz(3, 3, mat);

    return 0;
}