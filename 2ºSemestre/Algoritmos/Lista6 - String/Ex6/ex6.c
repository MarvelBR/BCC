#include <stdio.h>

int count_words_plus(const char str[])
{

    int count = 0;

    if ((str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122))
    {
        count++;
    }

    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == 32 && ((str[i + 1] >= 65 && str[i + 1] <= 90) || (str[i + 1] >= 97 && str[i + 1] <= 122)))
        {
            count++;
        }
    }

    return count;
}

int main()
{

    char s[] = " first things first, second things latter ";
    printf("%d", count_words_plus(s)); // saída: 6
    return 0;
}