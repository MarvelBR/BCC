#include <stdio.h>

int max_line(int rows, int cols, int m[rows][cols]){
    int soma_maior = 0;
    int soma_menor = 0;
    for (int i = 0; i < rows; i++)
    {
        int soma = 0;
        for (int j = 0; j < cols; j++)
        {
            soma+= m[i][j];

            if (soma_maior < soma)
            {
                soma_maior = soma;
            }
            else if (soma_menor > soma)
            {
                soma_menor = soma;
            }
            else{
                soma_menor = soma_maior;
            }
        }
        
    }

    return soma_maior;
}



int main(){

    int mat[5][5] = {
    { 1, 2, 3, 4, 5}, // soma: 15
    { 2, 4, 6, 8,10}, // soma: 30 ← esta linha possui a maior soma
    { 1, 2, 3, 4, 7}, // soma: 17
    { 2, 0, 6, 1,10}, // soma: 19
    { 7, 3, 4, 0, 0} // soma: 14
    };

    int res = max_line(5, 5, mat);
    printf("Maior soma: %d\n", res);

    return 0;
}