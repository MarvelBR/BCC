#include <stdio.h>

int vector_insert(int n, int vet1[], int elem){
    for (int i = 0; i < n; i++)
    {
        if (vet1[i] == -1){
            vet1[i] = elem;
            return 1;
        }
        
    }
    return 0;
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

    if (vector_insert(n, vet, 18)) {
        printf("Elemento 18 inserido com sucesso.\n");
    } else {
        printf("Não foi possível inserir o elemento 18.\n");
    }

    if (vector_insert(n, vet, 7)) {
        printf("Elemento 7 inserido com sucesso.\n");
    } else {
        printf("Não foi possível inserir o elemento 7.\n");
    }

    // Exibe o vetor resultante
    printf("Vetor resultante: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}