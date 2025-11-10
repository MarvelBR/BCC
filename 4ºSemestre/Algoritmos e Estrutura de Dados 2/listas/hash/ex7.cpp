#include <unordered_set>
#include <vector>
#include <iostream>

// 7. Dado um vetor arr não-ordenado de inteiros, retorne o comprimento da maior sequência de inteiros
//consecutivos em arr. Por exemplo, se arr = {1, 9, 3, 10, 4, 20, 2}, então a saída deve ser 4, pois
//a maior sequência de inteiros consecutivos é {1, 3, 4, 2}. Note que os elementos desta sequência não
//precisam estar um ao lado do outro no vetor arr.

int maiorSequenciaConsecutivos(std::vector<int>& arr){
    std::unordered_set<int> conjunto;
    int maiorComprimento = 0;

    // Adiciona todos os elementos ao conjunto para acesso O(1)
    for (int num : arr) {
        conjunto.insert(num);
    }

    // Verifica cada número no vetor
    for (int num : arr) {
        // Verifica se é o início de uma sequência
        if (conjunto.find(num - 1) == conjunto.end()) {
            int comprimentoAtual = 1;
            int atual = num;

            // Conta a sequência consecutiva
            while (conjunto.find(atual + 1) != conjunto.end()) {
                atual++;
                comprimentoAtual++;
            }

            // Atualiza o maior comprimento encontrado
            maiorComprimento = std::max(maiorComprimento, comprimentoAtual);
        }
    }

    return maiorComprimento;
}


int main() {
    std::vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
    int resultado = maiorSequenciaConsecutivos(arr);
    
    std::cout << "O comprimento da maior sequencia de inteiros consecutivos e: " << resultado << "\n";
    
    return 0;
}

/*
  Vamos seguir o exemplo arr = {1, 9, 3, 10, 4, 20, 2}.


   1. `std::unordered_set<int> conjunto;`
       * Primeiro, o código cria um conjunto para ter acesso quase instantâneo a todos os números que existem no vetor.
       * O primeiro for loop simplesmente copia todos os elementos de arr para dentro do conjunto.
       * Ao final, conjunto será {1, 9, 3, 10, 4, 20, 2}.


   2. O Loop Principal (`for (int num : arr)`)
       * Agora o código percorre o vetor arr original novamente, número por número, para encontrar os inícios de sequência.


       * `num` é 1:
           * A verificação principal: if (conjunto.find(num - 1) == conjunto.end())
           * Isso se traduz em: "O número 1 - 1 (ou seja, 0) existe no conjunto?". A resposta é não.
           * Isso significa que 1 é o início de uma sequência!
           * O código entra no if e começa a contar a partir do 1:
               * O 2 existe no conjunto? Sim. Comprimento atual = 2.
               * O 3 existe? Sim. Comprimento atual = 3.
               * O 4 existe? Sim. Comprimento atual = 4.
               * O 5 existe? Não. A sequência para aqui.
           * O maiorComprimento encontrado até agora é 4.


       * `num` é 9:
           * A verificação: "O número 9 - 1 (ou seja, 8) existe no conjunto?". A resposta é não.
           * Isso significa que 9 também é o início de uma sequência!
           * Começa a contar a partir do 9:
               * O 10 existe? Sim. Comprimento atual = 2.
               * O 11 existe? Não. A sequência para.
           * O comprimento desta sequência é 2. Como 4 (o maiorComprimento) é maior que 2, o maiorComprimento continua sendo 4.


       * `num` é 3:
           * A verificação: "O número 3 - 1 (ou seja, 2) existe no conjunto?". A resposta é sim.
           * Como o 2 existe, o 3 não é o início de uma sequência. O código ignora o 3 e não faz nada. Isso é a grande otimização, pois evita
             recontar a sequência {1, 2, 3, 4} a partir do 3.


       * `num` é 10:
           * A verificação: "O número 10 - 1 (ou seja, 9) existe no conjunto?". Sim.
           * O 10 não é um início de sequência. O código o ignora.


       * O mesmo acontece para 4 e 2. O código os ignora porque 3 e 1 existem no conjunto, respectivamente.

   3. Retorno
       * Após o loop terminar, a variável maiorComprimento terá o valor 4, que é retornado.
*/