#include <stdio.h>
#include <string.h>

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

int main() {
    char name[] = " JoHN DOE# 23! ";
    fix_name(name);
    Contact c1 = create_contact(4, name, 1);

    printf("ID: %d\n", c1.id);
    printf("Name: '%s'\n", c1.name);
    printf("Email: '%s'\n", c1.email);
    printf("Type: %d\n", c1.type);

    return 0;
}