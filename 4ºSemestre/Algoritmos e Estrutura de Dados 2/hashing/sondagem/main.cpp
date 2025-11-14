#include <iostream>
#include "thea.h"
#include <cstdlib>
#include <string>
#include "thea.cpp"
#include "sondagem.h"

FSondagem* build_FSondagem (std::string nome, int m){
    if (nome == "linear")
    {
        
    }
    
    return NULL;
}

void test(int argc, char** argv){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    float limiar = atof(argv[3]);

    FSondagem* sondagemLinear = new SondagemLinear();
    FSondagem* sondagemQuadratica = new SondagemQuadratica();
    FSondagem* sondagemHashDuplo = new SondagemHashDuplo(m-1);

    
    TabHashEndAberto tab(m, limiar, sondagemLinear);
    srand(1);
    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir_info();

    // for(int i = 0; i < n; i++){
    //     tab.buscar(rand() % (n*100));
    // }

    //tab.imprimir();

}


int main(int argc, char** argv){
    
    test(argc, argv);

    return 0;
}