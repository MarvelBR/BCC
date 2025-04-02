#include <stdio.h>

void vector_union(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{   
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
        count++;
    }
    
    for (int j = 0; j < n2; j++)
    {
        v3[j+count] = v2[j]; 
    }
    
    printf("v3 = {");
    for (int i = 0; i < n1+n2; i++)
    {
        
        printf("%d,", v3[i]);

    }
    printf("\b}");
}

int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[8] = {0};
    vector_union(5, v1, 3, v2, v3);

    return 0;
}