#include <stdio.h>

int strings_compare(const char str1[], const char str2[]){
    int tamanho1 = 1;
    int tamanho2 = 1;
    int cont = 1;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        tamanho1++;
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        tamanho2++;
    }

    if (tamanho1 != tamanho2)
    {
        return 0;

    } else{
        char letras1[tamanho1];
        char letras2[tamanho2];

        for (int i = 0; str1[i] != '\0'; i++)
        {
            if (str1[i] >= 'a' && str1[i] <= 'z')
            {
                letras1[i] = str1[i] - 32;
                
            } else{
                letras1[i] = str1[i];
            }

            if (str2[i] >= 'a' && str2[i] <= 'z')
            {
                letras2[i] = str2[i]  - 32;
            } else{
                letras2[i] = str2[i];
            }

            if (letras1[i] == letras2[i]){   
                   
                cont++;
            }

        }
        
        if (cont == tamanho1)
            {
                return 1;
            } else{
                return 0;
            }
        
    }

}

int main(){

    char s1[] = "John Doe Clark# !";
    char s2[] = "JOHN doe cLARk# !";
    int res = strings_compare(s1, s2);
    printf("%d ", res);

    return 0;
}