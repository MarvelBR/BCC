#include <stdio.h>

void string_report(char str[]){
    int countLetras = 0;
    int countNumeros = 0;
    int countSimbolos = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            countLetras++;
        } 
        else if (str[i] >= 48 && str[i] <= 57)
        {
            countNumeros++;
        } else{
            countSimbolos++;
        }
        
        
    }
    printf("A String tem: %d Letras\n", countLetras);
    printf("A String tem: %d Numeros\n", countNumeros);
    printf("A String tem: %d Simbolos\n", countSimbolos);
    
}

int main(){

    char texto[] = "Hello, World! 1234";
    string_report(texto);

    return 0;
}