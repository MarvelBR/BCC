#include <stdio.h>

void print_vector_reverse(int n, const int* v){
    //v += n-1; // posiciona v no endereço do último elemento
    //for (int i = 0; i < n; i++) {
    //printf("%d ", *v);
    //v--;
    //}
    //printf("\n");
    // seria uma outra solução tbm

    
    for (int i = 0; n > i; n--)
    {      
        printf("%d ", *(v+n-1));
    }
    

}

int main(){
    int v[3] = {1, 2, 4};

    print_vector_reverse(3, v);

    return 0;
}