#include <unordered_set>
#include <vector>
#include <iostream>

// 9. Dado um vetor de inteiros arr, retorne true se existe pelo menos um subvetor de arr cuja soma dos
//elementos é igual a um valor k dado, ou false caso contrário.

bool temSubvetorSomaK(std::vector<int>& arr, int k){
    std::unordered_set<int> somaParcial;
    int somaAtual = 0;

    for (int num : arr) {
        somaAtual += num;

        // Verifica se a soma atual é igual a k ou se já vimos uma soma que, somada a k, resulta na soma atual
        if (somaAtual == k || somaParcial.find(somaAtual - k) != somaParcial.end()) {
            return true; // Subvetor com soma k encontrado
        }

        somaParcial.insert(somaAtual); // Adiciona a soma atual ao conjunto
    }

    return false; // Nenhum subvetor com soma k encontrado
}

int main() {
    std::vector<int> arr = {4, 2, -3, 1, 6};
    int k = 6;
    bool resultado = temSubvetorSomaK(arr, k);
    
    if (resultado) {
        std::cout << "Existe um subvetor com soma igual a " << k << ".\n";
    } else {
        std::cout << "Nao existe nenhum subvetor com soma igual a " << k << ".\n";
    }
    
    return 0;
}

/*
 Exemplo prático: arr = {3, 9, -2, 4, 1}, k = 7


   1. num=3: somaAtual=3. Procuramos por 3-7=-4 na memória. Não achamos. Guardamos 3.
       * Memória: {3}
   2. num=9: somaAtual=12. Procuramos por 12-7=5. Não achamos. Guardamos 12.
       * Memória: {3, 12}
   3. num=-2: somaAtual=10. Procuramos por 10-7=3. Achamos o 3 na memória!
       * Isso significa que existe um subvetor terminando aqui (-2) que soma 7.
       * Qual subvetor? O que está entre a ocorrência da soma 3 e a ocorrência da soma 10. É o subvetor {9, -2}. E, de fato, 9 + (-2) = 7.
       * A função retorna true.
*/