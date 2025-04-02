#include <stdio.h>

void vector_defrag(int n, int vet[n]){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] != -1)
        {
            vet[j++] = vet[i];
            
        }
    }
    
    while (j < n)
    {
        vet[j++] = -1;
    }
    
}


int main(){

    int n;
    int valor;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];

    int i = 0;

    while (i < n)
    {
        printf("Digite os valores do vetor: ");
        scanf("%d", &valor);

        vet[i] = valor;
        i++;
    }

    vector_defrag(n, vet);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    
    
    return 0;
}