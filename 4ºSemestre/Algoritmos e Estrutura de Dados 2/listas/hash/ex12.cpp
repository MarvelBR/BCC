#include <unordered_set>
#include <vector>
#include <iostream>

// Dado um par de vetores arr1 e arr2, retorne um vetor contendo os elementos que estão em arr1 e em
// arr2. Em outras palavras, sua função deve implementar a operação de interseção de conjuntos.

std::vector<int> intersecao(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> intersecao;
    std::vector<int> v_intersecao;

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j] && intersecao.find(arr1[i]) == intersecao.end())
            {
                intersecao.insert(arr1[i]);
            }
            
        }
        
    }

    for (const auto &num : intersecao)
    {
        v_intersecao.push_back(num);
    }
    
    return v_intersecao;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {4, 5, 6, 7, 8};
    
    std::vector<int> resultado = intersecao(arr1, arr2);
    
    std::cout << "Vetor resultante da intersecao: ";
    for (int num : resultado) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}