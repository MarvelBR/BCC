#include <stdio.h>

void print_vector(int n, const int* v){
    for (int i = 0; i < n; i++)
    {   
        printf("%d ", *v);
        v++;
    }
    
    printf("\n");
}

int main(){
    int v[3] = {1, 2, 4};

    print_vector(3, v);

    return 0;
}