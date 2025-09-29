//Ex 2: Dado um vetor V com n inteiros e um inteiro k,
// retorne um par(a,b) tal que a+b = k

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

pair <int,int> twosum(vector<int> & v, int k){
    
}

int main(int argc, char** argv){
    int n = stoi(argv[1]);

    //vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);

    return 0;
}