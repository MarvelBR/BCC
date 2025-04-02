#include <stdio.h>

void  print_min_max(int rows, int cols, int m[rows][cols]){
    int maior;
    int menor;
    maior = m[0][0];
    menor = m[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maior < m[i][j])
            {
                maior = m[i][j];
            }
            else if (menor > m[i][j])
            {
                menor = m[i][j];
            }
            else{
                menor = maior;
            }
        
        }
        
    }

    printf("O maior valor da matriz e: %d \n", maior);
    printf("O menor valor da matriz e: %d \n", menor);

}


int main(){

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

     print_min_max(3, 3, mat);


    return 0;
}