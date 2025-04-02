#include <stdio.h>

void make_mirrored(char* str){
    char* original = str; //ponteiro que aponta para o endereço inicial da string

    while (*str != '\0')
    {
        str++; //avança o ponteiro até o final da string
    }

    *str = '|'; //adiciona a barra
    str++;

    char* final = original;  //Ponteiro para o inicio da nova string:  John Doe|

    while (*final != '\0')
    {
        final++; //avança o ponteiro até o final da string
        
    }   

    final-=2; //final está apontando para o "e" de Doe

    //*str ta apontando para o espaço depois da |
    //ou seja está assim até agr: "John Doe|
    while (final >= original)  //Quando final aponta para antes do início da string original, o loop termina.
    {
        *str = *final;
        str++;
        final--;
    }
    
    *str = '\0';
        
}


int main(){

    char name[40] = "John Doe";
    make_mirrored(name);
    printf("%s\n", name); // Saída esperada: "John Doe|eoD nhoJ"

    return 0;
}

      //  for (int i = 0; i < 40; i++)
  //  {
   //     printf("%c", *(str+i));
  //      tamanho++;
//
//
    //    if (*(str+i) == 0)
   //     {
  //          printf("|");
//            //*str = '|';
//            for (int i = 0; tamanho > i; tamanho--)
//            {
//                printf("%c", *(str+tamanho-1));
//                //*str = *(str+tamanho-1);
//            }
//            break;
//        }
//
//        
//    }