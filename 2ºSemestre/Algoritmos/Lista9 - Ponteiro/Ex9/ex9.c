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


char* find_most_similar(const char* str, int n, char list[n][50]){
    int menor_dist = 0;
    char* parecido;

    for (int i = 0; i < n; i++)
    {
        int dist = get_hamming_distance(str, list[i]);

        if (i == 0)
        {
            menor_dist = dist;
        } else{
            if (menor_dist > dist)
            {
                menor_dist = dist;
                parecido = list[i];
            }
        }
        
    }
        
    return parecido;
}



int main(){
    char words[][50] = {"cabana", "savana", "bacana", "halana"};

    char* most_similar = find_most_similar("banana", 4, words);

    printf("%s\n", most_similar);  // "bacana"

    return 0;
}