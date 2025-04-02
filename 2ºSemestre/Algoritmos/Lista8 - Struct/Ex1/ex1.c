#include <stdio.h>

struct point {
    float x;
    float y;
};

typedef struct point Point;

float print_point(Point p){

    printf("X: %.2f, Y: %.2f", p.x, p.y);

    return 0;

}


int main(){
    Point p;
    p.x = 10.9;
    p.y = 2.5;

    print_point(p);

    return 0;
}