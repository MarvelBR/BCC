#include <stdio.h>

void print_vector2D(int rows, int cols, const int* v){
    //funcionaria se fosse só 1 for com i < rows*cols, daria certo tbm

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (*v < 10 && *v >= 0)
            {
                printf("0%d ", *v);
            } else{
                printf("%d ", *v);
            }
            
            v++;
        }
        printf("\n");
    }
    

}

int main(){
    int v[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12}
    };

    print_vector2D(3, 4, (int*)v);

    return 0;
}