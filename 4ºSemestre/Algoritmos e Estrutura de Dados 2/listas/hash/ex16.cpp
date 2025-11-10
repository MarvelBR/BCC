#include <unordered_set>
#include <vector>
#include <iostream>

// 16. Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 ou
// em arr2, mas não em ambos. Em outras palavras, sua função deve implementar a operação de diferença
// simétrica de conjuntos.

std::vector<int> diferencaSimetrica(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> dif(arr1.begin(), arr1.end());
    std::vector<int> v_dif;

    for (int num : arr2)
    {
        if (dif.count(num) == 1)
        {
            dif.erase(num);
        }
        else{
            dif.insert(num);
        }
    }
    
    for (const auto &num : dif)
    {
        v_dif.push_back(num);
    }
    return v_dif;
}


int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {4, 5, 6, 7, 8};
    
    std::vector<int> resultado = diferencaSimetrica(arr1, arr2);
    
    std::cout << "Vetor resultante da diferenca simetrica: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}