#include <stdio.h>

struct rect
{
    int x, y, width, height;
};
typedef struct rect Rect;

void print_board(Rect *board)
{
    for (int i = 0; i < board->y; i++)
    {
        printf("\n");
    }
    for (int i = 0; i < board->y; i++)
        for (int j = 0; j < (board->x + board->width); j++)
        {
            if (j > board->x)
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

    print_board(&rect);
    return 0;
}