#include <stdio.h>

void print_strings(int n, int len, char list[n][len]){
    for (int i = 0; i < n; i++)
    {
        printf("%s ", list[i]);
    }
    

}

int main(){
    char v[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
    print_strings(6, 20, v);

    return 0;
}