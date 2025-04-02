#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* array_intersection(int n1, const int* v1, int n2, const int* v2){

    int* v3 = malloc((n1+n2)*sizeof(int));

    if (v3 == NULL)
    {
        return NULL;
    }
    
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v2[j] == v1[i])
            {
                v3[k] = v1[i];
                k++;
            }
            
        }
        
    }

    
    return v3;
}


int main(){
    int v1[] = {1,2,3,4};
    int v2[] = {3,5,2};

    int* v3 = array_intersection(4, v1, 3, v2);

    if (v3 == NULL)
    {
        printf("ERRO");
    } else{
        printf("v3 = {");
        for (int i = 0; i < 2; i++)
        {
            printf("%d,", v3[i]);
        }
        printf("\b}\n");
    }
    
    free(v3);
    
    return 0;
}