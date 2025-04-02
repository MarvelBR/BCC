#include <stdio.h>

int find_sequence(int n1, int v1[], int n2, int v2[]){
    int contador = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                contador++;
            }
            
        }
    }

    if (contador == n2)
    {
        return 1;
        
    }
    return 0;
}

int main(){

    int vet1[] = {2, 5, 8, 15, 29, 45, 3, 6, 56, 21};
    int vet2[] = {5, 8, 45, 56};


    find_sequence(10, vet1, 4, vet2);

    return 0;
}