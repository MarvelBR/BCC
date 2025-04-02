#include <stdio.h>
#include <math.h>

struct point{
    float x;
    float y;
};

typedef struct point Point;

float distance_vector(int n, Point v[]){
    float raiz;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= n)
        {
            break;
        }
        
        raiz = sqrtf((v[i+1].x - v[i].x)*(v[i+1].x - v[i].x) + (v[i+1].y - v[i].y)*(v[i+1].y - v[i].y));
        printf("A distancia entre o Ponto %d e o Ponto %d e de: %.2f \n", i, i+1, raiz);
    }
    
    return raiz;
}

int main(){

    Point v[3] = {
        {1, 10},
        {5, 3},
        {9, 2}
    };

    distance_vector(3, v);

    return 0;
}