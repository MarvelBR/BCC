#include <stdio.h>

void remove_spaces(char str[]){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}

int main(){

    char s[] = " C Programming  Rules ! !  !  ";
    remove_spaces(s);
    printf("string:%s\n", s); 

    return 0;
}