#include <stdio.h>
#include <string.h>

void print_strings_minmax(int n, int len, char list[n][len])
{
    int mais_letra = 0;
    int menos_letra = len;
    int letras = 0;
    for (int i = 0; i < n; i++)
    {
        letras = 0;
        for (int j = 0; j < len; j++)
        {
            if (list[i][j] != 0)
            {
                letras++;
            }
            
        }

        if (mais_letra < letras)
        {
            mais_letra = letras;
        }
        else if (menos_letra > letras)
        {
            menos_letra = letras;
        }
    }

    printf("Menor:");
    for (int i = 0; i < n; i++)
    {   
        if ((int) strlen(list[i]) == menos_letra)
        {
            printf(" %s,", list[i]);
        }

    }
    printf("\b \n"); // \b pra remover a ultima virgula

    printf("Maior:");
    for (int i = 0; i < n; i++) {
        if ((int) strlen(list[i]) == mais_letra) {
            printf(" %s,", list[i]);
        }
    }
    printf("\b \n");

    //printf("Maior: %d\n", mais_letra);
    //printf("Menor: %d", menos_letra);
}

int main()
{
    char v[6][20] = {"Joh", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
    print_strings_minmax(6, 20, v);
    // A função imprimirá:
    // Menor: Joh, Jak, Ada
    // Maior: Michelangelo

    return 0;
}