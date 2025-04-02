#include <stdio.h>
#include <string.h>

int find_substring(const char str[], const char sub[])
{
    int n_str = strlen(str);
    int n_sub = strlen(sub);

    for (int i = 0; i <= n_str - n_sub; i++)
    {
        int j;
        for (j = 0; j < n_sub; j++)
        {
            if (str[i + j] != sub[j])
            {
                break;
            }
        }
        if (j == n_sub)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char s[] = "first things first, second things latter";
    int check = find_substring(s, "latter");
    printf("%d\n", check); // saída: 1

    return 0;
}