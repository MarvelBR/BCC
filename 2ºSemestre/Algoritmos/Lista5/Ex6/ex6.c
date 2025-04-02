#include <stdio.h>

int is_sorted(int n, int vet[]){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= n)
        {
            break;
        }
        else{
            if (vet[i] <= vet[i+1])
            {
                j++;
                if (j == n-1)
                {
                    return 1;
                }
                
            } 
            if (vet[i] > vet[i+1])
            {
                return 0;
            }
            
            
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

    //is_sorted(n, vet);

    printf("%d", is_sorted(n, vet));

    return 0;
}