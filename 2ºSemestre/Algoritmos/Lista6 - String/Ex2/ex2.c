#include <stdio.h>
#include <string.h>

void print_string_reversed(char str[]){
    //sem strlen
    int count = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[count]);
        count--;
    }
    printf("\n");
    
    //com strlen
    int count2 = strlen(str);
    count2--;
    for (int i = 0; str[i] != 0; i++)
    {
        printf("%c", str[count2]);
        count2--;
    }
    
}


int main(){
    char texto[] = "Teste";
    print_string_reversed(texto);

    return 0;
}