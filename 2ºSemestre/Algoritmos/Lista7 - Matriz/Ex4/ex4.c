#include <stdio.h>

float average(int rows, int cols, int m[rows][cols]){
    int soma = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            soma += m[i][j];
        }
        
    }

    float media = (float) soma/(rows*cols);
    printf("A media foi de: %.2f \n", media);
    return media;

}


int main(){

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    average(3, 3, mat);


    return 0;
}