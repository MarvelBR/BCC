#include <stdio.h>
#include <string.h>

void string_to_upper_copy(const char str[], char dest[])
{
    int i = 0;
    for (i = 0; str[i] != 0; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            dest[i] = str[i] - 32;
        } else{
            dest[i] = str[i];
        }

    }
    dest[i] = '\0';
}

int strcmp_plus(const char s1[], const char s2[])
{   
    char str1[strlen(s1)+1];
    char str2[strlen(s2)+1];
    string_to_upper_copy(s1, str1);
    string_to_upper_copy(s2, str2);
    
    return strcmp(str1, str2);
}

int main()
{
    int res = strcmp_plus("JOanna", "joanna");

    if (res == 0)
    {
        printf("Strings iguais!");
    } else if(res > 0) {
        printf("str1 vem depois de str2");
    } else{
        printf("str1 vem antes de str2");
    }
    

    return 0;
}