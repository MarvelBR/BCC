#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    int id;
    char name[51];
    char email[101];
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


void create_mail(char name[]){
    for (int i = 0; name[i] != 0; i++)
    {
        if (name[i] >= 65 && name[i] <= 90) name[i] += 32;
        if (name[i] == ' ') name[i] = '.';
    }
    strcat(name,"@mail.com");
}

Contact create_contact(int id, char name[], int type) {
    Contact c;
    char mail[51];
    strcpy(mail, name);
    create_mail(mail);
    c.id = id;
    strcpy(c.name, name);  // Copia o nome corrigido
    strcpy(c.email, mail);  // Copia o e-mail gerado
    c.type = type;

    return c;
}

// Função auxiliar para verificar se o nome contém "Doe"
int checar_sobrenome_doe(char name[]) {
    char sobrenome[] = "doe";
    int j = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if ((name[i] | 32) == sobrenome[j]) {  // Converte para minúsculo se necessário
            j++;
            if (sobrenome[j] == '\0') {
                return 1;  // Encontrou "Doe"
            }
        } else {
            j = 0;  // Reinicia a busca
        }
    }
    return 0;  // Não encontrou "Doe"
}

void fill_contact_list(int n, Contact list[]){
    char names[15][51] = {
        " john doe ", " Alice Smith ", " Bob Johnson ", " Charlie Brown ",
        " David White ", " Eva Green ", " Frank Black ", " Grace Blue ",
        " Henry Gold ", " Isabella Red ", " Jack Pink ", " Kate Grey ",
        " Liam Purple ", " Monica Silver ", " Nathan Doe "
    };

    for (int i = 0; i < n; i++) {
        int type = 0;
        fix_name(names[i]);
        if (checar_sobrenome_doe(names[i])) {
            type = 1;  // "Doe" recebe o tipo "Amigo" (tipo 1)
        } else {
            type = rand() % 5 + 1; 
        }
        list[i] = create_contact(i + 1, names[i], type);
    } 
}

int main() {
    Contact list[15];

    fill_contact_list(15, list);

    for (int i = 0; i < 15; i++) {
        printf("ID: %d\n", list[i].id);
        printf("Name: %s\n", list[i].name);
        printf("Email: %s\n", list[i].email);
        printf("Type: %d\n\n", list[i].type);
    }

    return 0;
}