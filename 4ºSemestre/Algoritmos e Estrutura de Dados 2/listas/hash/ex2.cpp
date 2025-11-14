#include <unordered_map>
#include <iostream>
#include <vector>

// 2. Dado um vetor de inteiros arr, retorne a posição do primeiro elemento do vetor que não tem duplicata.
// Se todos os elementos ocorrerrem pelo menos duas vezes, retorne -1.

int primeiroUnico(std::vector<int>& arr){
    std::unordered_map<int,int> frequencia;
    int freq = 0;
    for (int num : arr)
    {
        frequencia[num]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (frequencia[arr[i]] == 1) // O arr[i] seria a chave da tabela, então aqui ele verifica se o valor da chave é igual a 1
        {
            return i;
        }
    }
    
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 1, 4, 5, 4};
    int index = primeiroUnico(arr);
    if (index != -1) {
        std::cout << "O primeiro elemento unico e " << arr[index] << " e esta na posicao: " << index << "\n";
    } else {
        std::cout << "Todos os elementos possuem duplicatas.\n";
    }
    return 0;
}