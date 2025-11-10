#include <unordered_set>
#include <vector>
#include <iostream>

// 13. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 mas
// não estão em arr2. Em outras palavras, sua função deve implementar a operação de diferença de conjuntos.

std::vector<int> diferenca(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> diferenca;
    std::vector<int> v_diferenca;

    for (int num : arr1)
    {
        diferenca.insert(num);
    }
    
    for (int num : arr2)
    {
        if (diferenca.count(num) == 1)
        {
            diferenca.erase(num);
        }
        
    }
    

    for (const auto &num : diferenca)
    {
        v_diferenca.push_back(num);
    }
    
    return v_diferenca;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {4, 5, 6, 7, 8};
    
    std::vector<int> resultado = diferenca(arr1, arr2);
    
    std::cout << "Vetor resultante da diferenca: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
