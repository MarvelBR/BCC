#include <stdio.h>
#include <math.h>

struct point{

    float x;
    float y;

};

typedef struct point Point;

float distance2D(Point p1, Point p2){
    float raiz = sqrtf((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return raiz;
}

int main(){

    Point p1 = {-2.0f, 7.5f};
    Point p2 = {5.0f, 12.4f};
    float dist = distance2D(p1, p2);
    printf("A distancia dos 2 pontos e de: %.2f \n", dist);

    return 0;
}