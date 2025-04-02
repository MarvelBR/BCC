#include <stdio.h>

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    int igual = 0;
    if (r1 == r2 && c1 == c2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                if (m1[i][j] == m2[i][j])
                {
                    igual += 1;
                }
                
            }
            
        }

        if (igual == r1*c1)
        {
            printf("Sao iguais");
            return 1;
        }
        else{
            printf("Nao sao iguais");
            return 0;
        }
        
    }
    else{
        printf("Nao sao iguais");
        return 0;
    }
    

}

int main(){

    int mat[5][5] = {
    { 1, 2, 3, 4, 5},
    { 2, 4, 6, 8,10}, 
    { 1, 2, 3, 4, 7},
    { 2, 0, 6, 1,10}, 
    { 7, 3, 4, 0, 0} 
    };

    int mat2[5][5] = {
        { 1, 2, 3, 4, 5},
        { 2, 4, 6, 8,10}, 
        { 1, 2, 3, 4, 7},
        { 2, 0, 6, 1,10}, 
        { 7, 3, 4, 0, 0} 
    };

    matrix_equals(5, 5, mat, 5, 5, mat2);


    return 0;
}