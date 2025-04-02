#include <stdio.h>

void count_elements(int n, int vet[]){

    int max_value = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > max_value) {
            max_value = vet[i];
            //printf("%d \n", max_value);
        }
    }

    // Inicializar o vetor count com zeros
    int count[max_value + 1];
    for (int i = 0; i <= max_value; i++) {
        count[i] = 0;
        //printf("%d \n", count[i]);
    }

    // Contar as ocorrências de cada número
    for (int i = 0; i < n; i++) {
        count[vet[i]]++;
        //printf("%d \n", count[vet[i]]);
    }

    // Imprimir as contagens
    for (int i = 0; i <= max_value; i++) {
        if (count[i] > 0) {
            printf("O numero %d aparece %d vezes.\n", i, count[i]);
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

    count_elements(n, vet);

    return 0;
}