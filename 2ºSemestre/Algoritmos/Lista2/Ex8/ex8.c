#include <stdio.h>

int main(){

    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    int mil = num/1000;
    int centena = num/100;
    int dezena = num/10;
    int unidade = num % 10;

    if (num < 0){
        printf("menos ");
        mil = mil*-1;
        centena = centena*-1;
        dezena = dezena*-1;
        unidade = unidade*-1;

        if (mil == 0 && centena == 0){

        } else if (mil == 1) {
            printf("mil ");

        } else if (mil == 2) {
            printf("dois mil ");

        } else if (mil == 3) {
            printf("tres mil ");

        } else if (mil == 4) {
            printf("quatro mil ");

        }  else if (mil == 5) {
            printf("dois mil ");

        } else if (mil == 6) {
            printf("seis mil ");

        } else if (mil == 7) {
            printf("sete mil ");

        } else if (mil == 8) {
            printf("oito mil ");

        } else if (mil == 9) {
            printf("nove mil ");
        }

        if (centena - (mil*10) == 0){
    
        } else if (centena - (mil*10) == 1 && dezena == 0 && unidade == 0){
            printf("cem");

        } else if (centena - (mil*10) == 1){
            printf("cento ");

        } else if (centena - (mil*10) == 2){
            printf("duzentos ");

        } else if (centena - (mil*10)== 3){
            printf("trezentos ");

        } else if (centena - (mil*10) == 4){
            printf("quatrocentos ");
                
        } else if (centena - (mil*10) == 5){
            printf("quinhentos ");

        } else if (centena - (mil*10) == 6){
            printf("seiscentos ");

        } else if (centena - (mil*10) == 7){
            printf("setecentos ");
                
        } else if (centena - (mil*10) == 8){
            printf("oitocentos ");

        } else if (centena - (mil*10) == 9){
            printf("novecentos ");
                
        }

        if (dezena - (centena*10) == 0){
            if (unidade == 0){

            }

            if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 1){

            if (mil != 0 || centena != 0){
                printf("e ");
            }

            else{
                    
            }
                
            if(unidade == 0) {
                printf("dez");
            }

            else if (unidade == 1) {
                printf("onze");

            } else if (unidade == 2) {
                printf("doze");

            } else if (unidade == 3) {
                printf("treze");

            } else if (unidade == 4) {
                printf("quatorze");

            } else if (unidade == 5) {
                printf("quinze");

            } else if (unidade == 6) {
                printf("dezesesis");

            } else if (unidade == 7) {
                printf("dezesete");
                    
            } else if (unidade == 8) {
                printf("dezoito");

            } else if (unidade == 9) {
                printf("dezenove");
            }

        } else if (dezena - (centena*10) == 2){
            printf("e vinte ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }


        } else if (dezena - (centena*10) == 3){
            printf("e trinta ");

            if(unidade == 0) {
                
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 4){
            printf("e quarenta ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 5){
            printf("e cinquenta ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 6){
            printf("e sessenta ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 7){
            printf("e setenta ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 8){
            printf("e oitenta ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }

        } else if (dezena - (centena*10) == 9){
            printf("e noventa ");

            if(unidade == 0) {
                    
            }

            else if(unidade == 1) {
                printf("e um");
            }

            else if(unidade == 2) {
                printf("e dois");
            }
                
            else if(unidade == 3) {
                printf("e tres");
            }
                
            else if(unidade == 4) {
                printf("e quatro");
            }
                
            else if(unidade == 5) {
                printf("e cinco");
            }
                
            else if(unidade == 6) {
                printf("e seis");
            }
                
            else if(unidade == 7) {
                printf("e sete");
            }
                
            else if(unidade == 8) {
                printf("e oito");
            }

            else if(unidade == 9) {
                printf("e nove");
            }
        }
    } else {
        if (mil == 0 && centena == 0){

    } else if (mil == 1) {
        printf("mil ");

    } else if (mil == 2) {
        printf("dois mil ");

    } else if (mil == 3) {
        printf("tres mil ");

    } else if (mil == 4) {
        printf("quatro mil ");

    }  else if (mil == 5) {
        printf("dois mil ");

    } else if (mil == 6) {
        printf("seis mil ");

    } else if (mil == 7) {
        printf("sete mil ");

    } else if (mil == 8) {
        printf("oito mil ");

    } else if (mil == 9) {
        printf("nove mil ");
    }

    if (centena - (mil*10) == 0){

            
    } else if (centena - (mil*10) == 1 && dezena == 0 && unidade == 0){
        printf("cem");

    } else if (centena - (mil*10) == 1){
        printf("cento ");

    } else if (centena - (mil*10) == 2){
        printf("duzentos ");

    } else if (centena - (mil*10)== 3){
        printf("trezentos ");

    } else if (centena - (mil*10) == 4){
        printf("quatrocentos ");
            
    } else if (centena - (mil*10) == 5){
        printf("quinhentos ");

    } else if (centena - (mil*10) == 6){
        printf("seiscentos ");

    } else if (centena - (mil*10) == 7){
        printf("setecentos ");
            
    } else if (centena - (mil*10) == 8){
        printf("oitocentos ");

    } else if (centena - (mil*10) == 9){
        printf("novecentos ");
            
    }

    if (dezena - (centena*10) == 0){
        if (unidade == 0){

        }

        if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 1){

        if (mil != 0 || centena != 0){
            printf("e ");
        }

        else{
                
        }
            
        if(unidade == 0) {
            printf("dez");
        }

        else if (unidade == 1) {
            printf("onze");

        } else if (unidade == 2) {
            printf("doze");

        } else if (unidade == 3) {
            printf("treze");

        } else if (unidade == 4) {
            printf("quatorze");

        } else if (unidade == 5) {
            printf("quinze");

        } else if (unidade == 6) {
            printf("dezesesis");

        } else if (unidade == 7) {
            printf("dezesete");
                
        } else if (unidade == 8) {
            printf("dezoito");

        } else if (unidade == 9) {
            printf("dezenove");
        }

    } else if (dezena - (centena*10) == 2){
        printf("e vinte ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }


    } else if (dezena - (centena*10) == 3){
        printf("e trinta ");

        if(unidade == 0) {
               
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
         }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 4){
        printf("e quarenta ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 5){
        printf("e cinquenta ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 6){
        printf("e sessenta ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
             printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 7){
        printf("e setenta ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
             printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 8){
        printf("e oitenta ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }

    } else if (dezena - (centena*10) == 9){
        printf("e noventa ");

        if(unidade == 0) {
                
        }

        else if(unidade == 1) {
            printf("e um");
        }

        else if(unidade == 2) {
            printf("e dois");
        }
            
        else if(unidade == 3) {
            printf("e tres");
        }
            
        else if(unidade == 4) {
            printf("e quatro");
        }
            
        else if(unidade == 5) {
            printf("e cinco");
        }
            
        else if(unidade == 6) {
            printf("e seis");
        }
            
        else if(unidade == 7) {
            printf("e sete");
        }
            
        else if(unidade == 8) {
            printf("e oito");
        }

        else if(unidade == 9) {
            printf("e nove");
        }
    }
}

    


    return 0;
}