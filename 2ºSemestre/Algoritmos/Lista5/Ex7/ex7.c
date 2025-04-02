#include <stdio.h>
#include <math.h>

void distances(int n, int points[]){
    float distancia = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % 2 != 0 || n < 4)
        {
            break;
        }
        else{
            if (i + 2 >= n || i + 1 >= n || i+3 >= n)
            {
                break;
            } else{
                distancia = sqrtf(((points[i+2]-points[i])*(points[i+2]-points[i])) + ((points[i+3] - points[i+1]) * (points[i+3] - points[i+1])));
            }
        }
    }
    printf("%f", distancia);

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

    distances(n, vet);

    return 0;
}