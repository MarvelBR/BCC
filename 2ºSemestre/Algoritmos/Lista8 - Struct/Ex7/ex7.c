#include <stdio.h>

struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;

void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50]){
    for (int i = 0; i < n2; i++)
    {
        printf("%s \n", types[i]);
        for (int j = 0; j < n1; j++)
        {
            if (list[j].type == i) {
                printf("    %s\n", list[j].name);
            }
        }
        printf("\n");
    }
    
    
    
}

int main(){ 
    char types[][50] = {"Familia","Amigo","Trabalho","Escola","Outros"};
    Contact list[] = {
        {1, "Marcus Fenix", "fenix@gow.com", 2},
        {41,"Blue Mary", "mary@ff3snk.net", 0},
        {17,"Barry Burton", "bburton@re.cap", 0},
        {8, "Charlie Nash", "nash@ssz.com", 2},
        {2, "Ada Wong", "wong@re2.net", 4},
        {5, "Chris Redfield", "crfield@re.cap", 0}
    };
    print_contact_list(6, list, 5, types);

    return 0;
}