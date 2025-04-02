#include <stdio.h>
#include <stdlib.h>

int* create_vector(int n){
    int* v = malloc(n * sizeof(int));

    if (v == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    
    return v;
}

void print_vector(int n, const int* v){
    for (int i = 0; i < n; i++)
    {   
        printf("%d,", *v);
        v++;
    }
    printf("\b \n");
}


int main(){

    int* v1 = create_vector(7); // aloca array de 7 inteiros na heap

    if (v1 == NULL) {
        printf("Falha na alocação de memória.\n");
    }

    print_vector(7, v1); // imprime 0,0,0,0,0,0,0
    free(v1);// libera array alocado na heap

    return 0;
}