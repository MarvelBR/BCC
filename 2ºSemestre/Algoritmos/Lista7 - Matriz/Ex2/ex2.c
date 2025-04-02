#include <stdio.h>

void print_reversed(int rows, int cols, int m[rows][cols]){
    for (int i = 1; i < rows+1; i++)
    {
        for (int j = 1; j < cols+1; j++)
        {
            printf("%d \n", m[rows-i][cols-j]);
            
        }
        
    }

}


int main(){

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    print_reversed(3, 3, mat);


    return 0;
}