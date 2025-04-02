#include <stdio.h>
#include <stdlib.h>

int *get_largest(int n, int *v, int max)
{
    int max1 = v[0];
    int max2 = v[0];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max1 = v[0];
            max2 = v[0];
        }
        else
        {
            if (v[i] > max1)
            {
                max1 = v[i];
            }
            else
            {
                max2 = v[i];
            }
        }
    }

    int *v2 = malloc(n * sizeof(int));

    if (v2 == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < max; i++)
    {
        if (i == 0)
        {
            v2[i] = max1;
        }
        else
        {
            v2[i] = max2;
        }
    }

    return v2;
}

void print_vector(int n, const int *v)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", *v);
        v++;
    }
    printf("\b \n");
}

int main()
{

    int v0[] = {6, 10, 2, 1, 2, 3, 9};
    int *v1 = get_largest(7, v0, 2); // retorna vetor com os 2 maiores valores de v0

    if (v1 == NULL)
    {
        printf("Falha na alocação de memória.\n");
    }

    print_vector(2, v1); // imprime 10,9
    free(v1);            // libera array alocado na heap

    return 0;
}