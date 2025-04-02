#include <stdio.h>
#include <string.h>

void remove_palindrome(char str[]) {
    int len = strlen(str);
    int i, j;
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return;
        }
    }
    
    str[(len + 1) / 2] = '\0';
}

int main() {
    char text[] = "texto ok!!ko otxet";
    remove_palindrome(text);
    printf("%s\n", text); // Saída esperada: "texto ok!"
    return 0;
}