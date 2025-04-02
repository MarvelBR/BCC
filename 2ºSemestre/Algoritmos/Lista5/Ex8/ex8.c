#include <stdio.h>

void reverse(int n, int vet[]){
    int vet_inv[n];
    for (int i = 0; i < n; i++)
    {
        if (i + 1 > n || n - (i+1) < 0){
            break;
        } else{
            vet_inv[i] = vet[n - (i+1)];
        }
        
        printf("%d ", vet_inv[i]);
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

    reverse(n, vet);

    return 0;
}