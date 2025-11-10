#include <unordered_set>
#include <vector>
#include <iostream>

// 11. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 ou em
//arr2. Em outras palavras, sua função deve implementar a operação de união de conjuntos.

std::vector<int> uniao(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> uniao;
    std::vector<int> v_uniao;

    for (int num : arr1)
    {
        uniao.insert(num);
    }
    
    for (int num : arr2)
    {
        uniao.insert(num);
    }

    for (const auto &num : uniao)
    {
        v_uniao.push_back(num);
    }
    
    return v_uniao;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {4, 5, 6, 7, 8};
    
    std::vector<int> resultado = uniao(arr1, arr2);
    
    std::cout << "Vetor resultante da uniao: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}