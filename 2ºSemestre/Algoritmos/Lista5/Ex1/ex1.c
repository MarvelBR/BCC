#include <stdio.h>

void print_even(int n, int vet[]) {
    for (int i = 0; i < n; i++)
    {
        vet[i] = i + 1;

        if (vet[i] % 2 == 0)
        {
            printf("%d\n", vet[i]);
        }
        
    }
    
}

int main (){

    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];

    print_even(n, vet);

    return 0;

}