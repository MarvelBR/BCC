#include <stdio.h>

int main(){
    int x = 1;
    int maior = 0;
    int menor = 0;
    int i = 1;
    while (1){
        printf("Digite um novo valor: ");
        scanf("%d", &x); 

        if (x == 0)
        {
            break;
        }
        

        if (i == 1){
            maior = menor = x;
            i = 0;
        }

        else{
            if (x > maior){
                maior = x;
            }

            if(x < menor){
                menor = x;
            }
        }  
        
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);

    return 0;
}