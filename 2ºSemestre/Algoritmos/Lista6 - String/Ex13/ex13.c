#include <stdio.h>
#include <string.h>

void int_to_string(int number, char converted[]) {
    int i = 0;
    int is_negative = 0;
    
    if (number == 0) {
        converted[i++] = '0';
        converted[i] = '\0';
        return;
    }
    
    if (number < 0) {
        is_negative = 1;
        number = -number;
    }
    
    while (number > 0) {
        converted[i++] = (number % 10) + '0';
        number /= 10;
    }
    
    if (is_negative) {
        converted[i++] = '-';
    }
    
    converted[i] = '\0';
    
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = converted[start];
        converted[start] = converted[end];
        converted[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char num[11]; 
    int_to_string(512, num);
    printf("%s\n", num); // saída: "512"
    return 0;
}
