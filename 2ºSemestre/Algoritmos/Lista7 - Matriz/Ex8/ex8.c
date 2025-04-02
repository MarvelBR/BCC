#include <stdio.h>

void put_totals(int rows, int cols, int m[rows][cols]){
    int soma;
    for (int i = 0; i < rows; i++)
    {
        printf("// ");
        soma = 0;
        for (int j = 0; j < cols; j++)
        {
            soma += m[i][j];
            

            if (j == cols-1)
            {
                m[i][j] = soma;
            }
            printf("%d ", m[i][j]);
            
        }
        printf("\n");
    }
    
}


int main(){

    int mat[4][5] = {
    { 1, 2, 3, 4, 0},
    { 2, 4, 6, 8, 0},
    { 3, 6, 9, 12, 0},// O último elemento de cada linha receberá a soma
    { 4, 8, 12,16, 0} // da linha.
    };

    put_totals(4, 5, mat);

    return 0;
}