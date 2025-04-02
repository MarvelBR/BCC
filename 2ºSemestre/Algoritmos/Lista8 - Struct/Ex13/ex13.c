#include <stdio.h>
#include <string.h>

struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;

void string_trim(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (str[start] == ' ') {
        start++;
    }

    while (str[end] == ' ') {
        end--;
    }

    int i;
    int j;

    for (i = start, j = 0; i <= end; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0';
}

void fix_name(char name[]){
    for (int i = 0; name[i] != 0; i++)
    {
        if(name[i] >= 97 && name[i] <= 122){
            if (i == 0){
                name[i] -= 32;
            }
            if (i > 0){
                if(name[i-1] == ' ') name[i] -= 32;
            }
        } else if (name[i] >= 65 && name[i] <= 90){
            if (i > 0){
                if(name[i-1] != ' ') name[i] += 32;
            }
        } else{
            name[i] = ' ';
        }
    }
    string_trim(name);
}

int nome_em_nome(char name[], char target[]){
    int i = 0;
    int j = 0;
    for (i = 0; target[i] != 0; i++)
    {
        for (j = 0; j < name[j]; j++)
        {
            if(name[j] != target[i+j]) break;
        }
        if (name[j] == 0) return 1;
    }
    
    return 0;
}

int find_by_name(int n1, Contact list[n1], int n2, char names[n2][51]){
    int len = 0;
    char name[51];
    int count = 0;
    for (int i = 0; i < n2; i++)
    {
        strcpy(name, names[i]);
        fix_name(name);
        len = strlen(name);

        for (int j = 0; j < n1; j++)
        {
            if (nome_em_nome(name,list[j].name)) count++;
        }
    }
    return count;
}

int main() {
    // Definindo uma lista de contatos
    Contact list[30] = {
        {1, "Joanna Souza", "joanna@example.com", 1},
        {2, "Mike Tyson", "mike@example.com", 2},
        {3, "Leonor Silva", "leonor@example.com", 1},
        {4, "Caroline Duarte", "caroline@example.com", 2},
        {5, "John Doe", "john@example.com", 1}
    };

    // Lista de nomes a buscar
    char names[5][51] = {"joanna", "john", "mike", "leonor", "caroline"};
    
    int count = find_by_name(30, list, 5, names);
    printf("Contatos encontrados: %d\n", count);

    return 0;
}