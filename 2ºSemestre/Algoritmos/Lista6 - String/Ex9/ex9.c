#include <stdio.h>
#include <string.h>

void string_count(const char str[])
{
    int count[26] = {0};
    int totalLetras = 0;

    // Contar as ocorrências de cada letra
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        // Converter maiúsculas para minúsculas
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
        }
        // Contar apenas letras
        if (ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
            totalLetras++;
        }
    }

    // Imprimir as ocorrências e percentuais
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c x%d (%.0f%%)\n", 'A' + i, count[i], (count[i] / (float)totalLetras) * 100);
        }
    }
}

int main()
{
    char s[] = "Hello World of Software Development";
    string_count(s);
    /* Saída:
    D x2 (6%)
    E x5 (16%)
    F x2 (6%)
    H x1 (3%)
    L x4 (13%)
    O x5 (16%)
    R x2 (6%)
    S x1 (3%)
    T x2 (6%)
    W x2 (6%)
    */

    return 0;
}