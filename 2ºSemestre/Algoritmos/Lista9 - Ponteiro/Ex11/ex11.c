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

void print_board_with_coordinates(Rect *board, Point *point)
{
    if (point->x > board->width || point->x < 0)
    {
        return;
    }
    if (point->y > board->height || point->y < 0)
    {
        return;
    }

    for (int i = 0; i < board->y; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < board->y; i++)
        for (int j = 0; j < (board->x + board->width); j++)
        {
            if (i == point->y && (j - board->x) - 1 == point->x)
            {
                printf("%c", point->symbol);
            }
            else if (j > board->x)
            {
                printf("*");
                if (j == (board->x + board->width) - 1)
                {
                    printf("\n");
                }
            }
            else
            {
                printf(" ");
            }
        }
    printf("\n");
    {
    }
}

int main()
{
    Rect rect = {5, 5, 10, 10};
    Point point = {0, 0, 'A'};

    print_board_with_coordinates(&rect, &point);
    return 0;
}