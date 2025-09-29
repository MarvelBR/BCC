// Ex1: Seja V um vetor com n elementos.
//Retorne um vetor contendo apenas os elementos únicos de V, em qualquer ordem.

//conjuntos implementado com hashing
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

vector<int> dedup(const vector<int>& v){
    //cria um dicionario (conjunto) vazio
    unordered_set<int> d;

    //inserir todo elemento de v em d
    for(int x: v){
        d.insert(x); //o insert aqui não permite repetir os elementos!
    }

    vector<int> saida;

    //passar todos os elementos do conjunto e copiá-los na saída
    for(int x: d){
        saida.push_back(x);
    }

    return saida;
}

int main(int argc, char** argv){
    int n = stoi(argv[1]); //argv é oq faz a gente escrever algo depois do nome do arquivo no terminal

    vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);

    // for (int i : v)
    // {
    //     cout << i << ", ";
    // }
    // cout << "\n";

    vector<int> s = dedup(v);

    // for (int i : v)
    // {
    //     cout << i << ", ";
    // }
    // cout << "\n";

    cout << s.size() << " elementos únicos." << endl;

    return 0;
}