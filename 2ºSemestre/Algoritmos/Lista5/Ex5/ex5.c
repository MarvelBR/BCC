#include <stdio.h>

void read_vector(int n, int vet[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
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

    read_vector(n, vet);

    return 0;
}