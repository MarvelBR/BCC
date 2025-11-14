#include <unordered_set>
#include <vector>
#include <iostream>

// 15. Dado um par de vetores arr1 e arr2, retorne true se arr1 e arr2 são disjuntos, ou false caso contrário.
// Considere que os vetores não contém elementos duplicados. Por definição arr1 e arr2 são disjuntos se não
// existe nenhum elemento em comum entre eles.

bool saoDisjuntos(std::vector<int>& arr1, std::vector<int>& arr2){
    std::unordered_set<int> disjuntos(arr1.begin(), arr1.end());

    for (int num : arr2)
    {
        if (disjuntos.count(num) > 0)
        {
            return false;
        }
        
    }
    return true;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 1};
    
    if (saoDisjuntos(arr1, arr2)) {
        std::cout << "arr1 e arr2 sao disjuntos." << std::endl;
    } else {
        std::cout << "arr1 e arr2 nao sao disjuntos." << std::endl;
    }
    
    return 0;
}