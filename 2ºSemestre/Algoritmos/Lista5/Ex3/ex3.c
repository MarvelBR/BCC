#include <stdio.h>

int find_max(int n, int vet[]){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= n)
        {
            break;
        }

        else{
            if (vet[i] >= vet[i+1]){

                max = vet[i];
            }
        
            if (vet[i] <= vet[i+1])
            {
                max = vet[i+1];
            }
        }
        
    }
    
    return max;
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

    printf("%d", find_max(n, vet));

    return 0;
}