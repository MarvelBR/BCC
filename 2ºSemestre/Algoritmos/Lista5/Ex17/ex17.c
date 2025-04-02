#include <stdio.h>

void min_bills(int value, int n, int bills[])
{
    int count[n];

    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    if (value / 200 >= 1)
    {
        count[7] = (value / 200);
        value = value - 200;
    }

    if (value / 100 >= 1)
    {
        count[6] = (value / 100);
        value = value - 100;
    }

    if (value / 50 >= 1)
    {
        count[5] = (value / 50);
        value = value - 50;
    }

    if (value / 20 >= 1)
    {
        count[4] = (value / 20);
        value = value - 20;
    }

    if (value / 10 >= 1)
    {
        count[3] = (value / 10);
        value = value - 10;
    }

    if (value / 5 >= 1)
    {
        count[2] = (value / 5);
        value = value - 5;
    }

    if (value / 2 >= 1)
    {
        count[1] = (value / 2);
        value = value - 2;
    }

    if (value / 1 == 1)
    {
        count[0] = value / 1;
        value = value - 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d x R$%d,00\n", count[i], bills[i]);
    }
}

int main()
{
    int notes[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int value = 209;

    // printf("%.0f ", );

    min_bills(value, 8, notes);
    return 0;
}