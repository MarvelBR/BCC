#include <stdio.h>

int MDC(int A, int B){

    int divisor_A;
    int divisor_B;
    int divisorAB;

    if (A >= B){
        int i = 0;
        while (i <= A){
            i++;

            if (A % i == 0)
            {
                divisor_A = i;
            }
            if (B % i == 0)
            {
                divisor_B = i;
            }
            if (divisor_A == divisor_B)
            {
                divisorAB = divisor_A;
                
            }
        }

        return divisorAB;

    } else if (B >= A){
        int i = 0;
        while (i <= B){
            i++;

            if (A % i == 0)
            {
                divisor_A = i;
            }
            if (B % i == 0)
            {
                divisor_B = i;
            }


            if (divisor_A == divisor_B)
            {
                divisorAB = divisor_A;
            }

        }

        return divisorAB;

    }
}

int main(){

    int A;
    int B;

    printf("Digite os numeros: ");
    scanf("%d %d", &A, &B);

    int mult = A * B;
    if (mult < 0)
    {
        mult *= -1;
    }
    
    int mmc = mult / MDC(A, B);

    printf("MMC: %d \n", mmc);

    return 0;
}