#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy_reverse(const char* str){
    int n = strlen(str);

    char* str2 = malloc(n*sizeof(char));

    if (str2 == NULL)
    {
        return NULL;
    }
    
    for (int i = 0; i < n; i++)
    {   
        str2[i] = str[n-1-i];
    }

    str2[n] = '\0';
    
    return str2;
}

int main(){
    char* str = "Teste";
    char* str2 = copy_reverse(str);

    if (str2 == NULL)
    {
        printf("Erro na Alocacao");

    } else{
        printf("%s", str2);
    }
    
    free(str2);

    return 0;
}