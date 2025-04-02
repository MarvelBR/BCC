#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_vector2D(int m, int n, const int **v)
{
    printf("v = {");
    for (int i = 0; i < m; i++)
    {
        printf("{");
        for (int j = 0; j < n; j++)
        {
            printf("%d,", v[i][j]);
        }
        printf("\b}, ");
    }
    printf("\b\b}\n");
}

int main()
{
    int m = 2;
    int n = 4;

    int **matriz = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        matriz[i] = malloc(n * sizeof(int));
    }

    int valor = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = valor++;
        }
    }

    print_vector2D(m, n, (const int **)matriz);

    for (int i = 0; i < m; i++)
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}
