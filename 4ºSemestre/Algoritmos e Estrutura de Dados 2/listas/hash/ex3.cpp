#include <unordered_set>
#include <iostream>
#include <vector>
#include <utility>

//3. Dado um vetor de inteiros arr, retorne um par de inteiros que somados resultam em um valor k dado.

std::pair<int, int> twosum(std::vector<int>& arr, int k){
    std::unordered_set<int> soma;
    for (int num : arr)
    {
        int complemento = k - num;
        if (soma.find(complemento) != soma.end()) // Verifica se o complemento já foi visto
        {
            return std::make_pair(complemento, num); // Retorna o par encontrado
        }
        soma.insert(num); // Adiciona o número atual ao conjunto
    }
    return std::make_pair(-1, -1); // Retorna um par inválido se nenhum par for encontrado
}

int main() {
    std::vector<int> arr = {8, 7, 2, 5, 3, 1};
    int k = 10;
    std::pair<int, int> result_pair;
    
    result_pair = twosum(arr, k);
    if (result_pair.first != -1 && result_pair.second != -1) {
        std::cout << "Par encontrado: (" << result_pair.first << ", " << result_pair.second << ")\n";
    } else {
        std::cout << "Nenhum par encontrado que soma " << k << ".\n";
    }
    
    return 0;
}
/*
 O algoritmo percorre o vetor, número por número.

   1. `std::unordered_set<int> seen;`
        seen é o nosso conjunto de "números já vistos". A grande vantagem de um unordered_set (uma tabela hash) é que verificar se um número
         existe dentro dele é uma operação extremamente rápida.

   2. O Loop (`for (int val : arr)`)
        O código começa a olhar cada elemento (val) do vetor.


   3. Primeiro número: `val` é 8.
        complement = k - val; -> complement = 10 - 8; -> complement é 2.
        Agora a pergunta é: "Eu já vi o número 2 antes?".
        if (seen.count(complement)) faz exatamente isso. Ele verifica se o número 2 existe no conjunto seen.
        Neste momento, seen está vazio. A verificação falha.
        seen.insert(val); -> O código então insere o número atual (8) no conjunto seen. Agora seen contém {8}.


   4. Segundo número: `val` é 7.
        complement = 10 - 7; -> complement é 3.
        "Eu já vi o número 3 antes?"
        if (seen.count(3)) -> O seen só tem {8}. A verificação falha.
        seen.insert(7); -> Agora seen contém {8, 7}.


   5. Terceiro número: `val` é 2.
        complement = 10 - 2; -> complement é 8.
        "Eu já vi o número 8 antes?"
        if (seen.count(8)) -> O código olha no conjunto seen ({8, 7}). Sim, o 8 está lá!
        A condição do if é verdadeira! Encontramos o par. O número atual é 2 e o complemento que já tínhamos visto é 8.
        return {complement, val}; -> A função retorna o par {8, 2} e termina. */