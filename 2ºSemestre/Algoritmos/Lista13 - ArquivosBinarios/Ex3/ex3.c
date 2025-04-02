#include <stdio.h>

struct Movie
{
    int id;
    char nome[100];
};

typedef struct Movie Movie; //lembrando que o último Movie é o "apelido" e o primeiro é o nome do struct

void write_all_movies(const char* filepath, const Movie* list, int n){

    FILE* file = fopen(filepath, "wb");

    if (file == NULL)
    {
        printf("ERRO!\n");
    }
    
    fwrite(list, sizeof(Movie), n, file);

    fclose(file);
}

int main(){

    Movie list[] = {
        {6, "They Live"},
        {11,"Big Trouble in Little China"},
        {10,"The Thing"},
        {1, "In the Mouth of Madness"},
        {8, "Ghosts of Mars"},
        {23,"Halloween"},
        {7, "Village of the Damned"}
        };

    // cria arquivo 'dados.bin' com conteúdo de 'list'
    write_all_movies("C:\\Users\\erick\\Documents\\Algoritmos\\Lista13 - ArquivosBinarios\\Ex3\\movies.bin", list, 7);
        

    return 0;
}