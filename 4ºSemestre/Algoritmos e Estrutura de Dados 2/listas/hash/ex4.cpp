#include <unordered_set>
#include <vector>
#include <iostream>

// 4. Dado um vetor de inteiros arr, retorne true se arr contém algum elemento repetido, e false caso
//contrário.

bool temDuplicatas(std::vector<int>& arr){
    std::unordered_set<int> duplicata;
    for (int num : arr) {
        if (duplicata.find(num) != duplicata.end()) {
            return true; // Elemento repetido encontrado
        }
        duplicata.insert(num); // Adiciona o número atual ao conjunto
    }
    return false; // Nenhum elemento repetido encontrado
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 3};
    
    if (temDuplicatas(arr)) {
        std::cout << "O vetor contem elementos repetidos.\n";
    } else {
        std::cout << "O vetor não contém elementos repetidos.\n";
    }
    
    return 0;
}