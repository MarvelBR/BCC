#include <stdio.h>

int string_to_int(const char number_str[])
{
    int result = 0;
    int i = 0;
    int is_negative = 0;

    if (number_str[0] == '-')
    {
        is_negative = 1;
        i = 1;
    }

    for (; number_str[i] != '\0'; i++)
    {
        int digit = number_str[i] - '0';
        result = result * 10 + digit;
    }

    if (is_negative)
    {
        result = -result;
    }

    return result;
}

int main()
{
    const char str1[] = "1024";
    int n1 = string_to_int(str1);
    printf("%d\n", n1); // saída: 1024

    const char str2[] = "-2506";
    int n2 = string_to_int(str2);
    printf("%d\n", n2); // saída: -2506

    return 0;
}