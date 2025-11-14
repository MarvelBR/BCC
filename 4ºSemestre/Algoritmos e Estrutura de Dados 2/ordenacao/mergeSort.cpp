#include <iostream>
#include <vector> // Usar std::vector para facilitar o gerenciamento de memória
#include <string>
#include "utils.h"

using namespace std;

// Link para referência da lógica: https://www.programiz.com/dsa/merge-sort

/*
================================================================================
EXEMPLO DE FUNCIONAMENTO DO MERGE SORT
================================================================================

O Merge Sort é um algoritmo de ordenação "dividir para conquistar".
A ideia é quebrar o vetor em problemas menores até que eles sejam triviais de resolver,
e depois combinar (mesclar) as soluções para resolver o problema original.

Imagine que queremos ordenar o vetor: [38, 27, 43, 3, 9, 82, 10]

1. DIVISÃO:
   - O vetor é dividido ao meio recursivamente.
   [38, 27, 43, 3] e [9, 82, 10]
   [38, 27] e [43, 3]   |   [9, 82] e [10]
   [38] e [27] | [43] e [3] | [9] e [82] | [10] (vetores de 1 elemento já estão "ordenados")

2. CONQUISTA (MESCLAGEM):
   - Agora, mesclamos os pequenos vetores de volta, ordenando-os no processo.
   [27, 38] e [3, 43]   |   [9, 82] e [10]
   - A mesclagem continua:
   [3, 27, 38, 43] e [9, 10, 82]
   - E finalmente, o vetor completo é mesclado e ordenado:
   [3, 9, 10, 27, 38, 43, 82]

A função `merge` é a responsável por fazer a mesclagem ordenada.
A função `mergeSort` é a que gerencia a divisão recursiva.
================================================================================
*/


// Função para mesclar (merge) dois subarrays ordenados em um único array ordenado.
// Recebe o vetor 'v', e os índices que definem os dois subarrays:
// O primeiro subarray é v[left..mid]
// O segundo subarray é v[mid+1..right]
void merge(int* v, int left, int mid, int right){

    // Calcula o tamanho dos dois subarrays que serão mesclados.
    int n1 = mid - left + 1; // Tamanho do subarray da esquerda (E)
    int n2 = right - mid;    // Tamanho do subarray da direita (D)

    // Cria arrays temporários para armazenar os elementos dos subarrays.
    int* E = new int[n1];
    int* D = new int[n2];
    
    // Copia os dados do vetor original para os arrays temporários.
    for (int i = 0; i < n1; i++) {
        E[i] = v[left + i];
    }
    for (int i = 0; i < n2; i++) {
        D[i] = v[mid + 1 + i];
    }
    
    // Índices para percorrer os subarrays (i para E, j para D) e o vetor principal (k).
    int i = 0; 
    int j = 0; 
    int k = left; // O índice 'k' começa na posição 'left' do vetor original 'v'.

    // Loop principal para mesclar os arrays temporários de volta no vetor 'v'.
    // Compara os elementos de E e D e coloca o menor em 'v'.
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            v[k] = E[i]; 
            i++; // Avança no array da esquerda.
        } else {
            v[k] = D[j];
            j++; // Avança no array da direita.
        }
        k++; // Avança no vetor principal.
    }
    
    // Após o loop principal, um dos arrays temporários pode ainda ter elementos.
    // Copia os elementos restantes do array E, se houver.
    while (i < n1) {
        v[k] = E[i];
        i++;
        k++;
    }
    // Copia os elementos restantes do array D, se houver.
    while (j < n2) {
        v[k] = D[j];
        j++;
        k++;
    }

    // Libera a memória alocada para os arrays temporários para evitar vazamento de memória.
    delete[] E;
    delete[] D;
}

// Função principal do Merge Sort.
// Recebe o vetor 'v' e os índices de início (p) e fim (r) da porção a ser ordenada.
void mergeSort(int* v, int p, int r) {
    // A condição de parada da recursão é quando o subarray tem 1 ou 0 elementos (p >= r).
    if (p < r) {
        // Calcula o ponto médio 'q' para dividir o vetor em dois.
        // Usar p + (r - p) / 2 evita overflow para valores grandes de p e r.
        int q = p + (r - p) / 2;

        // Chamada recursiva para ordenar a primeira metade (de p até q).
        mergeSort(v, p, q);
        
        // Chamada recursiva para ordenar a segunda metade (de q+1 até r).
        mergeSort(v, q + 1, r);
        
        // Após as duas metades estarem ordenadas, mescla elas com a função merge.
        merge(v, p, q, r);
    }
}

int main(int argc, char** argv) {
    // Verifica se o número de argumentos da linha de comando é suficiente.
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <numero_de_elementos>" << endl;
        cout << "Exemplo: ./merge.out 10" << endl;
        return 1; // Retorna um erro se nenhum número for fornecido.
    }

    // Converte o primeiro argumento da linha de comando (string) para um inteiro.
    // argv[0] é o nome do programa, argv[1] é o primeiro argumento.
    int n = stoi(argv[1]);

    // Gera um vetor de 'n' elementos com valores aleatórios.
    // (A função gerar_vetor_aleatorio deve estar definida em "utils.h" e "utils.cpp")
    vector<int> v = gerar_vetor_aleatorio(n, 1, n * 10); // Valores entre 1 e n*10

    cout << "Vetor original:" << endl;
    imprimir_vetor(v.data(), n); // Imprime o vetor antes da ordenação.

    // Chama o mergeSort para ordenar o vetor.
    // v.data() retorna um ponteiro para o array de dados do vector.
    // A ordenação acontece "in-place", ou seja, modifica o vetor original.
    mergeSort(v.data(), 0, n - 1);

    cout << "\nVetor ordenado:" << endl;
    imprimir_vetor(v.data(), n); // Imprime o vetor após a ordenação.
    
    return 0;
}

/*
================================================================================
COMO COMPILAR E EXECUTAR (Exemplo no Linux/macOS ou Windows com g++)
================================================================================

1. Abra o terminal.
2. Navegue até a pasta onde estão os arquivos (mergeSort.cpp, utils.cpp, utils.h).
3. Compile os arquivos juntos usando o g++:
   g++ mergeSort.cpp utils.cpp -o merge.out

   - g++: é o compilador.
   - mergeSort.cpp utils.cpp: são os arquivos de código-fonte.
   - -o merge.out: especifica que o arquivo executável gerado se chamará 'merge.out'.

4. Execute o programa, passando o número de elementos que você quer no vetor:
   ./merge.out 15

   - O programa irá gerar um vetor com 15 números aleatórios, imprimi-lo,
     ordená-lo com o Merge Sort e imprimir o resultado ordenado.
================================================================================
*/
