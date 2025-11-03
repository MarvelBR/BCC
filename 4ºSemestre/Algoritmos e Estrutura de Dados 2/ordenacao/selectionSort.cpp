#include <iostream>
#include <algorithm>
#include "utils.cpp"
#include <vector>

using namespace std;

int pos_maior(int *v, int ini, int fim){
    int maior = ini;
    for (int i = ini+1; i <= fim; i++)
    {
        if (v[i] > v[maior])
        {
            maior = i;
        }
        
    }
    return maior;
}

void SelectionSort(int *v, int n){
    for (int i = n-1; i > 0; i--)
    {
        int maior = pos_maior(v, 0, i);
        trocar(v, maior, i);
    }
    
}

int main(){
    int v[] = {4, 0, 6, 3, 2, 5, 1};
    int x = pos_maior(v, 0, 6);
    cout << "pos = " << x << endl;
    SelectionSort(v, 7);
    for (int i = 0; i < 6; i++)
    {
        cout << v[i];
    }
    cout << endl;
    return 0;
}