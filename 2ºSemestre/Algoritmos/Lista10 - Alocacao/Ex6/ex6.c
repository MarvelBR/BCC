#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* array_union(int n1, const int* v1, int n2, const int* v2){

    int* v3 = malloc((n1+n2)*sizeof(int));

    if (v3 == NULL)
    {
        return NULL;
    }
    

    for (int i = 0; i < n1+n2; i++)
    {
        if (i < n1)
        {
            v3[i] = v1[i];
        }
        else if (i >= n1 && i < n1+n2){
            v3[i] = v2[i-n1];
        }
        
    }
    

    return v3;
}

int main(){
    int v1[] = {1, 2, 3};
    int v2[] = {4, 5, 6, 7};
    int* v3 = array_union(3, v1, 4, v2);

    if (v3 == NULL)
    {
        printf("ERRO na Alocacao");
    } else{
        printf("v3 = {");
        for (int i = 0; i < 7; i++)
        {
            printf("%d,", v3[i]);
        }
        printf("\b}\n");
    }
    

    free(v3);

    return 0;
}