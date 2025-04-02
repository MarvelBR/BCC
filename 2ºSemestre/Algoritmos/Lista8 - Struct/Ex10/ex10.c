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

    for (i = start, j = 0; i <= end; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0';
}

void fix_name(char name[]){
    for (int i = 0; name[i] != 0; i++)
    {
        if(name[i] >= 97 && name[i] <= 122){
            if (i == 0){
                name[i] -= 32;
            }
            if (i > 0){
                if(name[i-1] == ' ') name[i] -= 32;
            }
        } else if (name[i] >= 65 && name[i] <= 90){
            if (i > 0){
                if(name[i-1] != ' ') name[i] += 32;
            }
        } else{
            name[i] = ' ';
        }
    }
    string_trim(name);
}

int main() {
    char name[] = " JoHN DOE# 23! ";
    fix_name(name);
    printf("Nome corrigido: \"%s\"\n", name); // Esperado: "John Doe"
    return 0;
}