#include <stdio.h>

void replace_all(int n, int vet[], int elem){
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elem)
        {
            vet[i] = -1;
        }

        printf("%d ", vet[i]);
        
    }
    
}

int main(){

    int n;
    int valor;
    int elem;
    
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

    printf("Digite o elemento a ser substituido: ");
    scanf("%d", &elem);

    replace_all(n, vet, elem);

    return 0;
}