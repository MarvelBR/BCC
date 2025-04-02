#include <stdio.h>

void merge(int n1, int v1[], int n2, int v2[], int v3[]){

    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n1+n2; i++)
    {
        if (v1[c1] < v2[c2] && c1 != n1)
        {
            v3[i] = v1[c1];
            c1++;
        }

        else{
            v3[i] = v2[c2];
            c2++;
        }
        printf("%d ", v3[i]);
        
    }

}

int main(){

    int n, n2;
    int valor, valor2;
    
    printf("Digite o tamanho do vetor: ");
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

    merge(n, vet, n2, vet2, vet3);

    return 0;
}