#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.programiz.com/dsa/merge-sort (A lógica é explicada aqui)

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

int main(){
    int v[] = {1, 7, 9, 0, 5, 8};
    int p = 0, q = 2, r = 5;
    merge(v, p, q , r);
    for (int i = 0; i < 6; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "\n";
    
    return 0;
}