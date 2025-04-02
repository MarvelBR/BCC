#include <stdio.h>

void string_to_upper(char str[])
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
    }

    for (int i = 0; str[i] != 0; i++)
    {
        printf("%c", str[i]);
    }
    
}

int main()
{

    char s[] = "All your BASE are Belong to US!";
    string_to_upper(s);

    return 0;
}