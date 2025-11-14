#include <unordered_set>
#include <vector>
#include <iostream>

// Dado um par de vetores, arr1 e arr2, retorne true se arr1 e arr2 contém os mesmos elementos, ou
//false caso contrário. Considere que os vetores não contém elementos duplicados e que não necessariamente
//os elementos estão na mesma ordem.

bool saoIguais(std::vector<int>& arr1, std::vector<int>& arr2){
    if (arr1.size() != arr2.size()) {
        return false;
    }
    
    std::unordered_set<int> elementos;
    //std::unordered_set<int> elementos(arr1.begin(), arr1.end()); // Insere todos os elementos de arr1 no conjunto
    // Aqui funcionaria também! Colocando um iterador do começo ao fim do vetor.

    for (int num : arr1)
    {
        elementos.insert(num);
    }
    
    
    for (int num : arr2) {
        if (elementos.find(num) == elementos.end()) { // Verifica se cada elemento de arr2 está no conjunto
            return false;
        }
    }
    
    return true;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {5, 4, 3, 2, 1};
    
    if (saoIguais(arr1, arr2)) {
        std::cout << "Os vetores sao iguais." << std::endl;
    } else {
        std::cout << "Os vetores sao diferentes." << std::endl;
    }
    
    return 0;
}
