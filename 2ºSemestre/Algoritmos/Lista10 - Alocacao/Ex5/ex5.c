#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_string(const char* str1, const char* str2){
    
    int n = strlen(str1);
    int n2 = strlen(str2);
    
    char* str3 = malloc((n+n2)*sizeof(char));

    for (int i = 0; i < n+n2; i++)
    {   
        if (i < n)
        {
            str3[i] = str1[i];
        }
        else if (i >= n && i < n+n2)
        {
            str3[i] = str2[i-n];
        }
    }

    str3[n+n2] = '\0';
    
    return str3;
}

int main(){
    char* str = "Teste";
    char* str2 = "Algoritmos";
    char* str3 = concat_string(str, str2);

    if (str3 == NULL)
    {
        printf("Erro na Alocacao");

    } else{
        printf("%s", str3);
    }
    
    free(str3);

    return 0;
}