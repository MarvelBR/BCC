#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

typedef struct point Point;


void nearest_points(int n, Point v[]){
    float menor = 0;
    float menor_x1 = 0;
    float menor_x2 = 0;
    float menor_y1 = 0;
    float menor_y2 = 0;
    float raiz = 0;

    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= n)
        {
            break;
        }

        raiz = sqrtf((v[i+1].x - v[i].x)*(v[i+1].x - v[i].x) + (v[i+1].y - v[i].y)*(v[i+1].y - v[i].y));

        if (i == 0)
        {
            menor = raiz;
        }
        else{
            if (menor > raiz){
                menor = raiz;
                menor_x1 = v[i].x;
                menor_x2 = v[i+1].x;
                menor_y1 = v[i].y;
                menor_y2 = v[i+1].y;
            }
        }

        
        
    }

    printf("Os dois pontos mais proximos sao: (%.2f, %.2f) e (%.2f, %.2f) \n", menor_x1, menor_y1, menor_x2, menor_y2);
    printf("E a distancia entre eles e de: %.2f", menor);
}

int main(){

    Point v[3] = {
        {1, 10},
        {5, 3},
        {9, 2}
    };


    nearest_points(3, v);

    return 0;
}