#include <stdio.h>
#include <string.h>

void cut_string(char str[], const char word[])
{
    int n_str = strlen(str);
    int n_word = strlen(word);

    for (int i = 0; i <= n_str - n_word; i++)
    {
        int j;
        for (j = 0; j < n_word; j++)
        {
            if (str[i + j] != word[j])
            {
                break;
            }
        }
        if (j == n_word)
        {
            str[i + n_word] = '\0';
            return;
        }
    }
}

int main()
{
    char s[] = "first things first, second things latter";
    cut_string(s, "second");
    printf("%s\n", s); // saída: "first things first, second"

    return 0;
}