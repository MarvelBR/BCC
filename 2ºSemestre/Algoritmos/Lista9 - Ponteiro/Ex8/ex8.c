#include <stdio.h>

int get_hamming_distance(const char* str1, const char* str2){
    int dist = 0;
    for (int i = 0; *str1 != '\0' && *str2 != '\0'; i++)
    {

        if (*str1 != *str2)
        {
            dist++;
        }

        str1++;
        str2++;
    }
     return dist;
}

int main(){

    int dist = get_hamming_distance("banana", "cabana"); // dist = 2
    printf("A distancia de Hamming e de: %d ", dist);
    /*
    banana << distância de Hamming é 2
    cabana
    */

    return 0;
}