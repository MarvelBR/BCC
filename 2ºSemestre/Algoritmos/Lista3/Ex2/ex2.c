#include <stdio.h>

int main(){

    int i = 33;
    printf("DEC OCT HEX CHR\n");

    while (i <= 126){
        printf("%03d %03o %03X %2c\n", i, i, i, i);
        i++;
    }
    

    return 0;
}