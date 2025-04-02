#include <stdio.h>
#include <string.h>

void string_trim(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (str[start] == ' ') {
        start++;
    }

    while (str[end] == ' ') {
        end--;
    }

    int i;
    int j;

    printf("%d %d\n", start, end);

    for (i = start, j = 0; i <= end; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0';
}

int main()
{
    char s[] = "   hello world   ";
    string_trim(s);
    printf("%s\n", s); // saída: "hello world"

    return 0;
}