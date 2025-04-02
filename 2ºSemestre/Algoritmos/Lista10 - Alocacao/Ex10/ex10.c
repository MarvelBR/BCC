#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **transpose(int m, int n, int v[m][n])
{

    int **transposta = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        transposta[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transposta[i][j] = v[j][i];
        }
    }

    return transposta;
}

int main()
{
    int m = 2;
    int n = 3;
    int matriz[2][3] = {{1, 2, 3},
                        {5, 6, 7}};

    //transposta[3][2] = {1, 5},
    //                   {2, 6},
    //                   {3, 7},

    int** transposta2 = transpose(2, 3, matriz);

    printf("matriz = {");
    for (int i = 0; i < n; i++)
    {
        printf("{");
        for (int j = 0; j < m; j++)
        {
            printf("%d,", transposta2[i][j]);
        }
        printf("\b}, ");
    }
    printf("\b\b}\n");

    for (int i = 0; i < n; i++)
    {
        free(transposta2[i]);
    }

    free(transposta2);

    return 0;
}