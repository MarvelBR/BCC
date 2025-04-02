#include <stdio.h>

void get_min_max(int n, const int* v, int* min, int* max){
    *max = *v;
    *min = *v;

    for (int i = 0; i < n; i++)
    {   
        if (*max < *v)
        {
            *max = *v;
            
        }
        else if (*min > *v){
            *min = *v;
            
        }
        v++;
    }
}

int main(){
    int v[3] = {5, 1, 0};
    int menor, maior;

    get_min_max(3, v, &menor, &maior);

    printf("Menor: %d, Maior: %d\n", menor, maior);

    return 0;
}