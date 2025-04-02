#include <stdio.h>
#include <stdlib.h>

struct point{
    float x;
    float y;

};

typedef struct point Point;

void random_points(int n, Point v[]){
    //intervalo [-50, 50]
    // de -50 a 50 temos 101 numeros ent *100
    for (int i = 0; i < n; i++)
    {
        Point p;

        float random = rand() % (50 - (-50) + 1) -50;
        float random2 = rand() % (50 - (-50) + 1) -50;

        p.x = random;
        p.y = random2;
        v[i] = p;

        printf("{%.2f, %.2f}", v[i].x, v[i].y);

    }
    

}

int main(){

    Point v[10];

    random_points(10, v);

    return 0;
}