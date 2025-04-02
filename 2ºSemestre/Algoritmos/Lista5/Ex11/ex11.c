#include <stdio.h>

void vector_remove(int n, int vet1[], int pos){
    for (int i = 0; i < n; i++)
    {
        if (pos <= n)
        {
            vet1[pos] = -1;
        }
        printf("%d ", vet1[i]);
    }
    


}

int main(){

    int n;
    int valor;
    int pos;
    
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

    printf("Digite a posicao a ser removida: ");
    scanf("%d", &pos);

    vector_remove(n, vet, pos);

    return 0;
}