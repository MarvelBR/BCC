#include <stdio.h>

int main(){
    
    float n1;
    float n2;
    float n3;

    printf("Digite as 3 notas do aluno: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    float media = (n1 + n2 + n3)/3;

    if (media <= 10 && media >= 8.5){
        printf("O aluno obteve o conceito A");

    } else if (media < 8.5 && media >= 7){
        printf("O aluno obteve o conceito B");

    } else if (media < 7 && media >= 5.5){
        printf("O aluno obteve o conceito C");

    } else if (media < 5.5 && media >= 0){
        printf("O aluno obteve o conceito D");
    }

    return 0;
}