#include <unordered_set>
#include <vector>
#include <iostream>


// 8. Dado um vetor de inteiros arr, retorne true se existe pelo menos um subvetor de arr cuja soma dos
// elementos é igual a 0, ou false caso contrário.

bool temSubvetorSomaZero(std::vector<int>& arr){
    std::unordered_set<int> somaParcial;
    int somaAtual = 0;

    for (int num : arr) {
        somaAtual += num;

        // Verifica se a soma atual é zero ou se já vimos essa soma antes
        if (somaAtual == 0 || somaParcial.find(somaAtual) != somaParcial.end()) {
            return true; // Subvetor com soma zero encontrado
        }

        somaParcial.insert(somaAtual); // Adiciona a soma atual ao conjunto
    }

    return false; // Nenhum subvetor com soma zero encontrado
}

int main() {
    std::vector<int> arr = {4, 2, -3, 1, 6};
    bool resultado = temSubvetorSomaZero(arr);
    
    if (resultado) {
        std::cout << "Existe um subvetor com soma igual a zero.\n";
    } else {
        std::cout << "Nao existe nenhum subvetor com soma igual a zero.\n";
    }
    
    return 0;
}

/*
  Vamos usar o mesmo exemplo: arr = {4, 2, -3, 1, 6}.


   1. `std::unordered_set<int> somaParcial;`
       * Este set (conjunto) funciona como a nossa "memória". Ele vai guardar todas as somas acumuladas que já encontramos. A vantagem de usar um
         unordered_set é que verificar se um número já existe nele é uma operação extremamente rápida.


   2. `int somaAtual = 0;`
       * Esta variável vai guardar a nossa soma acumulada (soma de prefixo) enquanto percorremos o vetor.

   3. O Loop (`for (int num : arr)`)
       * O código percorre cada número (num) do vetor.


       * `num` é 4:
           * somaAtual += num; -> somaAtual agora é 4.
           * Verificação:
               * somaAtual é 0? Não.
               * O somaParcial (que está vazio) contém o número 4? Não.
           * somaParcial.insert(somaAtual); -> Adicionamos 4 à nossa memória. somaParcial agora é {4}.


       * `num` é 2:
           * somaAtual += num; -> somaAtual é 4 + 2 = 6.
           * Verificação:
               * somaAtual é 0? Não.
               * O somaParcial ({4}) contém o número 6? Não.
           * somaParcial.insert(somaAtual); -> somaParcial agora é {4, 6}.


       * `num` é -3:
           * somaAtual += num; -> somaAtual é 6 + (-3) = 3.
           * Verificação:
               * somaAtual é 0? Não.
               * O somaParcial ({4, 6}) contém o número 3? Não.
           * somaParcial.insert(somaAtual); -> somaParcial agora é {4, 6, 3}.


       * `num` é 1:
           * somaAtual += num; -> somaAtual é 3 + 1 = 4.
           * Verificação:
               * somaAtual é 0? Não.
               * O somaParcial ({4, 6, 3}) contém o número 4? Sim!
           * A condição somaParcial.find(somaAtual) != somaParcial.end() é verdadeira.
           * return true; -> A função para imediatamente e retorna true, pois encontramos um subvetor com soma zero.
*/