#include <stdio.h>
#include <stdlib.h>

char* copy_string(const char* str){
    int n = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        n++;
    }
    
    char* str2 = malloc(n * sizeof(char));

    if (str2 == NULL)
    {
        return NULL;
    }
    

    for (int i = 0; str[i] != 0; i++)
    {
        str2[i] = str[i];
        
    }

    return str2;
}

int main(){
    char* str = "Teste";
    char* str2 = copy_string(str);

    if (str2 == NULL)
    {   
        printf("Erro na alocacao");
    } else{
        printf("%s", str2);
    }
    
    free(str2);

    return 0;
}