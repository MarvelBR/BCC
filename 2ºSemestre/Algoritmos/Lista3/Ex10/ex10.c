#include <stdio.h>

int main(){

    int num;
    printf("Digite um numero entre -999 e 999: ");
    scanf("%d", &num);

    int centena = num/100;
    int dezena = num/10;
    int unidade = num % 10;

    if (num < -999 || num > 999)
    {
        printf("ERRO!");
    } else{
        if (num >= 0){
            if (centena == 9){
                printf("novecentos");
            } else if (centena == 8){
                printf("oitocentos");
            } else if (centena == 7){
                printf("setecentos");
            } else if (centena == 6){
                printf("seiscentos");
            } else if (centena == 5){
                printf("quinhentos");
            } else if (centena == 4){
                printf("quatrocentos");
            }else if (centena == 3){
                printf("trezentos");
            } else if (centena == 2){
                printf("duzentos");
            } else if (centena == 1){
                printf("cento");
            } else if (centena == 1 && dezena == 0 && unidade == 0){
                printf("cem");
            }

            if (dezena - (centena*10) == 9 && centena != 0){
                printf(" e noventa");
            } else if (dezena - (centena*10) == 9 && centena == 0){
                printf("noventa");
            } else if (dezena - (centena*10) == 8 && centena != 0){
                printf(" e oitenta");
            } else if (dezena - (centena*10) == 8 && centena == 0){
                printf("oitenta");
            } else if (dezena - (centena*10) == 7 && centena != 0){
                printf(" e setenta");
            } else if (dezena - (centena*10) == 6 && centena == 0){
                printf("sessenta");
            } else if (dezena - (centena*10) == 6 && centena != 0){
                printf(" e sessenta");
            } else if (dezena - (centena*10) == 5 && centena == 0){
                printf("cinquenta");
            } else if (dezena - (centena*10) == 5 && centena != 0){
                printf(" e cinquenta");
            } else if (dezena - (centena*10) == 4 && centena == 0){
                printf("quarenta");
            } else if (dezena - (centena*10) == 4 && centena != 0){
                printf(" e quarenta");
            } else if (dezena - (centena*10) == 3 && centena == 0){
                printf("trinta");
            } else if (dezena - (centena*10) == 3 && centena != 0){
                printf(" e trinta");
            } else if (dezena - (centena*10) == 2 && centena == 0 && unidade == 0){
                printf("vinte");
            } else if (dezena - (centena*10) == 2 && centena != 0 && unidade == 0){
                printf(" e vinte");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 0){
                printf("dez");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 0){
                printf(" e dez");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 1){
                printf("onze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 1){
                printf(" e onze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 2){
                printf("doze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 2){
                printf(" e doze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 3){
                printf("treze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 3){
                printf(" e treze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 4){
                printf("quatorze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 4){
                printf(" e quatorze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 5){
                printf("quinze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 5){
                printf(" e quinze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 6){
                printf("dezeseis");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 6){
                printf(" e dezeseis");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 7){
                printf("dezesete");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 7){
                printf(" e dezesete");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 8){
                printf(" e dezoito");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 8){
                printf("dezoito");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 9){
                printf(" e dezenove");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 9){
                printf("dezenove");
            } 

            if (unidade == 1 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e um");
            } else if (dezena - (centena*10) == 0 && unidade == 1 && centena == 0){
                printf("um");
            } else if (unidade == 2 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e dois");
            } else if (dezena - (centena*10) == 0 && unidade == 2 && centena == 0){
                printf("dois");
            } else if (unidade == 3 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e tres");
            } else if (dezena - (centena*10) == 0  && unidade == 3 && centena == 0){
                printf("tres");
            } else if (unidade == 4 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e quatro");
            } else if (dezena - (centena*10) == 0 && unidade == 4 && centena == 0){
                printf("quatro");
            } else if (unidade == 5 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e cinco");
            } else if (dezena - (centena*10) == 0  && unidade == 5 && centena == 0){
                printf("cinco");
            } else if (unidade == 6 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e seis");
            } else if (dezena - (centena*10) == 0 && unidade == 6 && centena == 0){
                printf("seis");
            } else if (unidade == 7 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e sete");
            } else if (dezena - (centena*10) == 0  && unidade == 7 && centena == 0){
                printf("sete");
            } else if (unidade == 8 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e oito");
            } else if (dezena - (centena*10) == 0  && unidade == 8 && centena == 0){
                printf("quatro");
            } else if (unidade == 9 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e nove");
            } else if (dezena - (centena*10) == 0 && unidade == 9 && centena == 0){
                printf("nove");
            }
            


        } else{
            centena = centena*-1;
            dezena = dezena*-1;
            unidade = unidade*-1;
            printf("menos "); 

            if (centena == 9){
                printf("novecentos");
            } else if (centena == 8){
                printf("oitocentos");
            } else if (centena == 7){
                printf("setecentos");
            } else if (centena == 6){
                printf("seiscentos");
            } else if (centena == 5){
                printf("quinhentos");
            } else if (centena == 4){
                printf("quatrocentos");
            }else if (centena == 3){
                printf("trezentos");
            } else if (centena == 2){
                printf("duzentos");
            } else if (centena == 1){
                printf("cento");
            } else if (centena == 1 && dezena == 0 && unidade == 0){
                printf("cem");
            }

            if (dezena - (centena*10) == 9 && centena != 0){
                printf(" e noventa");
            } else if (dezena - (centena*10) == 9 && centena == 0){
                printf("noventa");
            } else if (dezena - (centena*10) == 8 && centena != 0){
                printf(" e oitenta");
            } else if (dezena - (centena*10) == 8 && centena == 0){
                printf("oitenta");
            } else if (dezena - (centena*10) == 7 && centena != 0){
                printf(" e setenta");
            } else if (dezena - (centena*10) == 6 && centena == 0){
                printf("sessenta");
            } else if (dezena - (centena*10) == 6 && centena != 0){
                printf(" e sessenta");
            } else if (dezena - (centena*10) == 5 && centena == 0){
                printf("cinquenta");
            } else if (dezena - (centena*10) == 5 && centena != 0){
                printf(" e cinquenta");
            } else if (dezena - (centena*10) == 4 && centena == 0){
                printf("quarenta");
            } else if (dezena - (centena*10) == 4 && centena != 0){
                printf(" e quarenta");
            } else if (dezena - (centena*10) == 3 && centena == 0){
                printf("trinta");
            } else if (dezena - (centena*10) == 3 && centena != 0){
                printf(" e trinta");
            } else if (dezena - (centena*10) == 2 && centena == 0 && unidade == 0){
                printf("vinte");
            } else if (dezena - (centena*10) == 2 && centena != 0 && unidade == 0){
                printf(" e vinte");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 0){
                printf("dez");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 0){
                printf(" e dez");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 1){
                printf("onze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 1){
                printf(" e onze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 2){
                printf("doze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 2){
                printf(" e doze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 3){
                printf("treze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 3){
                printf(" e treze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 4){
                printf("quatorze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 4){
                printf(" e quatorze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 5){
                printf("quinze");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 5){
                printf(" e quinze");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 6){
                printf("dezeseis");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 6){
                printf(" e dezeseis");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 7){
                printf("dezesete");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 7){
                printf(" e dezesete");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 8){
                printf(" e dezoito");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 8){
                printf("dezoito");
            } else if (dezena - (centena*10) == 1 && centena != 0 && unidade == 9){
                printf(" e dezenove");
            } else if (dezena - (centena*10) == 1 && centena == 0 && unidade == 9){
                printf("dezenove");
            } 

            if (unidade == 1 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e um");
            } else if (dezena - (centena*10) == 0 && unidade == 1 && centena == 0){
                printf("um");
            } else if (unidade == 2 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e dois");
            } else if (dezena - (centena*10) == 0 && unidade == 2 && centena == 0){
                printf("dois");
            } else if (unidade == 3 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e tres");
            } else if (dezena - (centena*10) == 0  && unidade == 3 && centena == 0){
                printf("tres");
            } else if (unidade == 4 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e quatro");
            } else if (dezena - (centena*10) == 0 && unidade == 4 && centena == 0){
                printf("quatro");
            } else if (unidade == 5 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e cinco");
            } else if (dezena - (centena*10) == 0  && unidade == 5 && centena == 0){
                printf("cinco");
            } else if (unidade == 6 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e seis");
            } else if (dezena - (centena*10) == 0 && unidade == 6 && centena == 0){
                printf("seis");
            } else if (unidade == 7 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e sete");
            } else if (dezena - (centena*10) == 0  && unidade == 7 && centena == 0){
                printf("sete");
            } else if (unidade == 8 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e oito");
            } else if (dezena - (centena*10) == 0  && unidade == 8 && centena == 0){
                printf("quatro");
            } else if (unidade == 9 && centena != 0 && dezena - (centena*10) != 0 && dezena - (centena*10) != 1){
                printf(" e nove");
            } else if (dezena - (centena*10) == 0 && unidade == 9 && centena == 0){
                printf("nove");
            }

        }
        
    }
    

    return 0;
}