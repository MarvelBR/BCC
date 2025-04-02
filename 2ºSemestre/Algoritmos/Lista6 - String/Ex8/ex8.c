#include <stdio.h>
#include <string.h>

int string_compare(const char str1[], const char str2[])
{
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    int count = 0;
    if (n1 == n2)
    {
        for (int i = 0; str1[i] != 0; i++)
        {
            if (str1[i] == str2[i])
            {
                count++;
            }
            else if (str1[i] < str2[i])
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        if (count == n1)
        {
            return 0;
        }
    }
    else if (n1 > n2)
    {
        return 1;
    }
    else
    {
        return -1;
    }

    return 0;
}

int main()
{
    printf("%d\n", string_compare("maca", "banana"));  // Deve retornar -1
    printf("%d\n", string_compare("uva", "uva"));      // Deve retornar 0
    printf("%d\n", string_compare("laranja", "maca")); // Deve retornar 1
    return 0;
}