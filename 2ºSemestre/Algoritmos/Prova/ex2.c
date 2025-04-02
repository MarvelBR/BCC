#include <stdio.h>

void insert_spaces(char str[]){
    int tamanho = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        tamanho++;
    }
    char str2[tamanho];

    for (int i = 0; str[i] != '\0'; i++)
    {   
        str2[i] = str[i];
    }

    int j = 0;
    for (int i = 0; i < tamanho*2; i+=2)
    {
        str[i] = str2[j];
        str[i+1] = ' ';
        j++;

    }
    
}

int main(){

    char s[30] = "C-code-rules!";
    insert_spaces(s);
    printf("string: %s\n", s); 

    return 0;
}