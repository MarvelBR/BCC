#include <stdio.h>

int main(){

    int A;
    int B;
    int divisor_A;
    int divisor_B;
    int divisorAB;

    printf("Digite os numeros: ");
    scanf("%d %d", &A, &B);

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

        printf("MDC: %d\n", divisorAB);

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

        printf("MDC: %d", divisorAB);

    }
    
    

    return 0;
}