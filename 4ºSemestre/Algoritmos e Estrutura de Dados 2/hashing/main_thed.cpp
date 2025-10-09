#include <iostream>
#include "thed.h"
#include "print_pair.h"
#include <cstdlib>

//Para rodar aqui: g++ main_thed.cpp -o main_thed
//Depois ./main_thed 3 6 2 (são 3 números que precisa)

void test3(int argc, char** argv){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int limiar = atoi(argv[3]);

    TabHashEncadeamento tab(m, limiar);

    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir_info();
    tab.imprimir();

}


int main(int argc, char** argv){
    
    //test1();
    //test2();
    test3(argc, argv);

    return 0;
}
