#include <unordered_set>
#include <vector>
#include <iostream>

// 5. Dado um vetor de inteiros arr, retorne um vetor com os elementos de arr, mas sem elementos repetidos.
// Os elementos no vetor de saída precisam estar na mesma ordem que os elementos do vetor de entrada.

std::vector<int> semDuplicatas(std::vector<int>& arr){
    std::unordered_set<int> vistos;
    std::vector<int> semduplicatas;
    for (int num : arr)
    {
        if (vistos.find(num) == vistos.end())
        {
            vistos.insert(num);
            semduplicatas.push_back(num);
        }
        
    }
    return semduplicatas;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 4, 5, 3, 6};
    std::vector<int> resultado = semDuplicatas(arr);
    
    std::cout << "Vetor sem duplicatas: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}