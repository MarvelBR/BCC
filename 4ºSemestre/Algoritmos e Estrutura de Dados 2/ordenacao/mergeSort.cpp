#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include "utils.h"

using namespace std;

// https://www.programiz.com/dsa/merge-sort (A lógica é explicada aqui)

// Pra rodar lembra de escrever no terminal: g++ merge-sort.cpp utils.cpp -o merge.out
// Ai depois ./merge.out 10 (numero que quiser)

void merge(int* v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* E = new int[n1];
    int* D = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        E[i] = v[left+i];
    }
    for (int i = 0; i < n2; i++)
    {
        D[i] = v[mid + 1 + i];
    }
    
    int k = left;
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (E[i] <= D[j])
        {
            v[k] = E[i];
            i++;
        }
        else{
            v[k] = D[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        v[k] = E[i];
        i++, k++;
    }
    
    while (j < n2)
    {
        v[k] = D[j];
        j++, k++;
    }
    
    delete[] E;
    delete[] D;
}

void mergeSort(int* v, int p, int r) {
    if(r > p) {
        int q = p + (r - p) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q+1, r);
        merge(v, p, q, r);
    }
}

int main(int argc, char** argv) {

    int n = stoi(argv[1]);

    vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    imprimir_vetor(v.data(), n);
    mergeSort(v.data(), 0, n-1);
    imprimir_vetor(v.data(), n);
    
    return 0;
}