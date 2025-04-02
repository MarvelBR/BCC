#include <stdio.h>

void init_values(int rows, int cols, int m[rows][cols], int start, int step){
    int soma = start;
    for (int i = 0; i < rows; i++)
    {
        printf("// ");
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = soma;
            soma+=step;
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

}


int main(){

    int v[4][6];

    init_values(4, 6, v, 10, 2);

    return 0;
}