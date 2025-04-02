#include <stdio.h>

void print_string(char str[]){

    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        printf(" ");
    }
    
}


int main(){
    char texto[] = "Teste";
    print_string(texto);

    return 0;
}