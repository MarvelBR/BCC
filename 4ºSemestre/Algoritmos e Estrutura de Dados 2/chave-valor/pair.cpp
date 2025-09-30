//Ex 2: Dado um vetor V com n inteiros e um inteiro k,
// retorne um par(a,b) tal que a+b = k

#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>

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
    unordered_set<int> d;
    for(int x: v){
        d.insert(x);
    }
    for (int x: v)
    {
        if (d.count(k-x) == 1)
        {
            return make_pair(x, k-x);
        }
        
    }
    return make_pair(-1,-1);
}

int main(int argc, char** argv){
    int n = stoi(argv[1]);

    //vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);

    return 0;
}