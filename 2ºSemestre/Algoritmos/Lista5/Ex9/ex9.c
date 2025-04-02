#include <stdio.h>

void vector_copy(int n, int vet2[], int vet1[]){
    for (int i = 0; i < n; i++)
    {
        vet2[i] = vet1[i];
        printf("%d ", vet2[i]);
    }
    
}

int main(){

    int n;
    int valor;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    int vet2[n];

    int i = 0;

    while (i < n)
    {
        printf("Digite os valores do vetor: ");
        scanf("%d", &valor);

        vet[i] = valor;
        i++;
    }

    vector_copy(n, vet2, vet);

    return 0;
}