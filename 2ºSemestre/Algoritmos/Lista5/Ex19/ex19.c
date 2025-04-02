#include <stdio.h>

void vector_intersection(int n1, int v1[n1], int n2, int v2[n2], int v3[])
{
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v2[j] == v1[i])
            {
                v3[j] = v2[j];
                count++;
            }
        }
    }

    printf("v3 = {");
    for (int i = 0; i < count; i++)
    {
        printf("%d,", v3[i]);
    }
    printf("\b}");
}


int main()
{
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[3] = {2, 3, 8};
    int v3[3] = {0};
    vector_intersection(5, v1, 3, v2, v3);

    return 0;
}