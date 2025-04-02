#include <stdio.h>

struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;


void print_contact(Contact c, int n, char type_names[n][50]){
    for (int i = 0; i < n; i++)
    {   
        if (i == c.type)
        {
             printf("{%d, %s, %s, %s}", c.id, c.name, c.email, type_names[i]);
        }
        
    }
   
}


int main(){

    char types[5][50] = {"Família","Amigos","Trabalho","Escola","Outros"};
    Contact c = {1, "John Doe", "john.doe@email.com", 2};
    print_contact(c, 5, types);
    // saída: {1, John Doe, john.doe@email.com, Trabalho}

    return 0;
}