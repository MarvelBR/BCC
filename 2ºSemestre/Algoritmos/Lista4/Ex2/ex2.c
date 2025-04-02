#include <stdio.h>

int main() {
    printf("DEC  HEX CHR   DEC  HEX CHR   DEC  HEX CHR\n");

    for (int i = 33; i <= 63; i++) {
        printf("%03d  %03X  %c     %03d  %03X  %c   %03d  %03X  %c\n", 
               i, i, (char)i, 
               i + 31, i + 31, (char)(i + 31), 
               i + 62, i + 62, (char)(i + 62));
    }

    return 0;
}
