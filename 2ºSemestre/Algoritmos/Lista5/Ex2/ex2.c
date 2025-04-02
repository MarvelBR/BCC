#include <stdio.h>

void set_positive (int n, int vet[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);

        if (vet[i] < 0)
        {
            vet[i] = vet[i]*-1;
        }

        
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
    set_positive(n, vet);

    return 0;
}