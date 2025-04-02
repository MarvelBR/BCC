#include <stdio.h>
#include <string.h>

void string_capitalize(const char str[]){

    char str2[100];

    strcpy(str2, str);

    if (str2[0] >= 97 && str2[0] <= 122)
    {
        str2[0] -= 32;
    }

    for (int i = 0; str2[i] != 0; i++)
    {
        if (str2[i] == 32 && ((str2[i + 1] >= 97 && str2[i + 1] <= 122)))
        {
            str2[i+1] -= 32;
        } else if (((str2[i] >= 65 && str[i] <= 90) || (str2[i] >= 97 && str[i] <= 122)) && (str2[i+1] >= 65 && str2[i + 1] <= 90)) 
        {
            str2[i+1] += 32;
        }
        
    }

    for (int i = 0; str2[i] != 0; i++)
    {
        printf("%c", str2[i]);
    }
    
}


int main(){
    char s[] = "welCOME To COMPUTER programming!!";
    string_capitalize(s);

    return 0;
}