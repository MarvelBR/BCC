#include <stdio.h>

void print_inc_seq (int n, const int v[]){
    for (int i = 0; i < n; i++)
    {
        if (n > 1 && (v[i+1] - v[i] == 1))
        {
            printf("%d ", v[i]);

            if ((v[i+1] - v[i] == 1 && v[i+2] - v[i+1] != 1))
            {
                printf("%d ", v[i+1]);
            }
        } 
        
        
    }
}

int main(){

    int vet1[12] = {1, 7, 5, 1, 13, 14, 15, 16, 40, -9, -8, 14};
    print_inc_seq(12, vet1);

    return 0;
}