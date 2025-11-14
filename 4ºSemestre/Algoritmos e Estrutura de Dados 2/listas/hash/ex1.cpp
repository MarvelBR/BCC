#include <unordered_map>
#include <iostream>
#include <vector>

// 1. Dado um vetor de inteiros arr, conte a frequência de cada inteiro

/*Retorna: um dicionario com a frequencia de cada inteiro, onde a chave é o inteiro
e o valor é a frequência.*/
std::unordered_map<int,int> contarFrequencia(std::vector<int>& arr){
    std::unordered_map<int,int> frequencia;
    for (int i = 0; i < arr.size(); i++)
    {
        frequencia[arr[i]]++; // o Operador [] insere a chave se ela não existir e atualiza o valor se a chave já existir
    }

    return frequencia;
}



int main() {
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    std::unordered_map<int,int> frequencia = contarFrequencia(arr);
    for (const auto &[chave, valor] : frequencia)
    {
        std::cout << chave << ": " << valor << "\n";
    }
    
    return 0;
}