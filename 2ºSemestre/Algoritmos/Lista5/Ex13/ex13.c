#include <stdio.h>

void vector_concat(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    for (int i = 0; i < n1+n2; i++)
    {
        if (i < n1)
        {
            v3[i] = v1[i];
        }
        else if (i >=n1 && i < n2+n1)
        {
            
            v3[i] = v2[i-n1];
            
        }
        
        printf("%d ", v3[i]);
    }
    
    

}

int main(){

    int n;
    int n2;
    int valor, valor2;
    
    printf("Digite o tamanho do vetor 1: ");
    scanf("%d", &n);

    int vet[n];

    int i = 0;
    int j = 0;

    while (i < n)
    {
        printf("Digite os valores do vetor: ");
        scanf("%d", &valor);

        vet[i] = valor;
        i++;
    }

    printf("Digite o tamanho do vetor 2: ");
    scanf("%d", &n2);
    int vet2[n2];
    int vet3 [n+n2];

    while (j < n2)
    {
        printf("Digite os valores do vetor 2: ");
        scanf("%d", &valor2);

        vet2[j] = valor2;
        j++;
    }

    vector_concat(n, vet, n2, vet2, vet3);

    return 0;
}