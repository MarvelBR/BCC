#include <stdio.h>

int max_sum_slice2(int n, int v[]){
    int max_atual = v[0];
    int max_total = v[0];
    
    for (int i = 1; i < n; i++)
    {
        if (max_atual + v[i] > v[i])
        {
            max_atual = v[i] + max_atual;
        } else{
            max_atual = v[i];
        }

        if (max_atual > max_total)
        {
            max_total = max_atual;
        }
        
        
    }

    return max_total;

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

    int soma_maxima = max_sum_slice2(n, vet);

    printf("%d ", soma_maxima);

    return 0;
}