#include <unordered_set>
#include <vector>
#include <iostream>

// 14. Dado um par de vetores arr1 e arr2, retorne true se arr1 é um subconjunto de arr2, ou false caso
// contrário. Considere que os vetores não contém elementos duplicados. Por definição arr1 é subconjunto de
// arr2 se todos os elementos de arr1 estão em arr2.

bool ehSubconjunto(std::vector<int>& arr1, std::vector<int>& arr2){
    
    std::unordered_set<int> subconjunto(arr2.begin(), arr2.end());
    int count = 0;

    for (int num : arr1)
    {
        if (subconjunto.count(num) == 0)
        {
            return false;
        }
        
    }

    return true; 
}

int main() {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    
    if (ehSubconjunto(arr1, arr2)) {
        std::cout << "arr1 e subconjunto de arr2." << std::endl;
    } else {
        std::cout << "arr1 nao e subconjunto de arr2." << std::endl;
    }
    
    return 0;
}