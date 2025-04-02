#include <stdio.h>

int count_inc_sequences(int n1, int v1[]){
    int quant = 0;
    for (int i = 0; i < n1; i++)
    {

        if (n1 > 1 && (v1[i+1] - v1[i] == 1)){

            if (v1[i+2] - v1[i+1] == 1)

            {
                quant--;
            }
            
            quant++;
            }
        }
        
    return quant;
}

int main(){

    int vet1[] = {1, 2, 5, 1, 13, 14, 15, 16, 40, -9, -8, 14};
    int res = count_inc_sequences(12, vet1);
    printf("%d", res);

    return 0;
}