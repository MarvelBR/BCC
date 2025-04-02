#include <stdio.h>

struct point
{
    int x, y;
    char symbol;
};
typedef struct point Point;

struct rect
{
    int x, y, width, height;
};
typedef struct rect Rect;

void print_board3(Point *points, Rect *board)
{
    int num_points = 3; // Número fixo de pontos
    
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < board->y + board->height; i++)
    {
        for (int j = 0; j < board->x + board->width; j++)
        {
            char to_print = ' ';

            // Verifica se a posição atual contém um ponto
            for (int k = 0; k < num_points; k++)
            {
                if (points[k].x >= 0 && points[k].x < board->width &&
                    points[k].y >= 0 && points[k].y < board->height &&
                    i == points[k].y + board->y && j == points[k].x + board->x)
                {
                    to_print = points[k].symbol;
                    break;
                }
            }

            // Desenha as bordas ou os símbolos
            if (j >= board->x && j < board->x + board->width &&
                i >= board->y && i < board->y + board->height)
            {
                printf("%c", to_print == ' ' ? '*' : to_print);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    Rect rect = {5, 5, 10, 10};
    Point points[] = {{0, 0, 'A'}, {2, 7, 'B'}, {9, 9, 'C'}};
    
    print_board3(points, &rect);
    return 0;
}