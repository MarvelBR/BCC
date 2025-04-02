#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** create_vector2D(int m, int n){

    int** m2 = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++)
    {
        m2[i] = malloc(n * sizeof(int));
    }
    

    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m2[i][j] = k;
            k++;
        }
        
    }
    
    return m2;
}

int main(){
    int m = 2;
    int n = 3;

    int** matriz2 = create_vector2D(m, n);

    printf("matriz = {");
    for (int i = 0; i < m; i++)
    {
        printf("{");
        for (int j = 0; j < n; j++)
        {
            printf("%d,", matriz2[i][j]);
        }
        printf("\b}, ");
    }
    printf("\b\b}\n");
    
    for (int i = 0; i < m; i++)
    {
        free(matriz2[i]);
    }
    
    free(matriz2);

    return 0;
}