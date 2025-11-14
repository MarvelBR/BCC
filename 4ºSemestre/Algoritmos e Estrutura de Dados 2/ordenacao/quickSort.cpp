#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

// A função partition é o coração do QuickSort.
// Ela recebe um array (v), o índice de início (p) e o de fim (r).
// O objetivo é escolher um pivô (neste caso, v[r], o último elemento) e
// reorganizar o array para que todos os elementos menores ou iguais ao pivô
// fiquem à sua esquerda, e os maiores à sua direita.
int partition(int* v, int p, int r) {
    // O pivô é escolhido como o último elemento do array/subarray.
    int pivo = v[r];
    
    // 'i' é um índice que marca a fronteira da seção de elementos menores que o pivô.
    // Começa em 'p-1' porque ainda não encontramos nenhum elemento menor.
    int i = p - 1;

    // Percorre o array da posição inicial 'p' até a penúltima 'r-1'.
    // O elemento 'r' não é incluído porque ele é o pivô.
    for (int j = p; j < r; j++) {
        // Se o elemento atual (v[j]) for menor ou igual ao pivô...
        if (v[j] <= pivo) {
            // ...incrementamos 'i' (aumentando a seção de menores)...
            i++;
            // ...e trocamos o elemento v[i] com v[j].
            // Isso move o elemento menor v[j] para a seção de menores.
            std::swap(v[i], v[j]);
        }
    }
    
    // Ao final do loop, todos os elementos de 'p' até 'i' são menores ou iguais ao pivô.
    // A posição 'i+1' é o lugar correto para o pivô.
    // Trocamos o pivô (v[r]) com o elemento em v[i+1].
    std::swap(v[i + 1], v[r]);
    
    // Retornamos o índice onde o pivô foi colocado.
    // Este índice "divide" o array em duas partes.
    return i + 1;
}

// A função principal do QuickSort, que opera recursivamente.
void quickSort(int* v, int p, int r) {
    // A condição de parada da recursão:
    // Se 'p < r', significa que o subarray tem pelo menos 2 elementos e precisa ser ordenado.
    // Se 'p >= r', o subarray tem 0 ou 1 elemento, então já está "ordenado".
    if (p < r) {
        // Chama a função partition para encontrar a posição correta do pivô 'q'.
        int q = partition(v, p, r);
        
        // Agora, o elemento v[q] está em sua posição final.
        // Chamamos o quickSort recursivamente para as duas metades:
        // 1. A sub-lista à esquerda do pivô (elementos menores).
        quickSort(v, p, q - 1);
        // 2. A sub-lista à direita do pivô (elementos maiores).
        quickSort(v, q + 1, r);
    }
}

// Função principal para demonstrar o QuickSort.
int main() {
    // Cria um vetor de inteiros com valores desordenados.
    std::vector<int> vetor = {10, 7, 8, 9, 1, 5, 3, 4, 2, 6};

    std::cout << "Vetor original: ";
    // Usa a função do seu arquivo utils.h para imprimir o vetor.
    // vetor.data() retorna um ponteiro para o array interno do std::vector.
    imprimir_vetor(vetor.data(), vetor.size());

    // Chama o quickSort para ordenar o vetor.
    // Passamos o ponteiro para os dados, o índice inicial (0) e o final (tamanho - 1).
    quickSort(vetor.data(), 0, vetor.size() - 1);

    std::cout << "Vetor ordenado: ";
    imprimir_vetor(vetor.data(), vetor.size());
    
    return 0;
}
