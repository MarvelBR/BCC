#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include "utils.h"

using namespace std;

//Lógica por trás: https://www.programiz.com/dsa/quick-sort

// PARTICIONAMENTO

int partition(int* v, int p, int r) {
    int x = v[r];
    int i = p-1;

    for (int j = p; j < r; j++)
    {
        if(v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    
    return i+1;
}

void quickSort(int* v, int p, int r){
    if (p < r)
    {
        int q = partition(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }
}

int main(int argc, char** argv) {

    int n = stoi(argv[1]);

    vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    quickSort(v.data(), 0, n-1);
    //imprimir_vetor(v.data(), n);
    //imprimir_vetor(v.data(), n);
    
    return 0;
}