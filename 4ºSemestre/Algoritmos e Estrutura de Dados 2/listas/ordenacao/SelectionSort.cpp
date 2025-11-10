#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//Função Selection Sort pegando os menores valores
void selectionSortMin(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // Seleciona o menor elemento em cada loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // coloca o menor na posição correta
    swap(array[min_idx], array[step]);
  }
}

//Função Selection Sort pegando os maiores valores
void selectionSortMax(int array[], int size) {
  for (int step = size-1; step > 0; step--) {
    int max_idx = step;
    for (int i = 0; i < step; i++) {

      // Seleciona o maior elemento em cada loop.
      if (array[i] > array[max_idx])
        max_idx = i;
    }

    // coloca o maior na posição correta
    swap(array[max_idx], array[step]);
  }
}

// Função auxiliar para encontrar o índice do menor elemento no subarray
int findMinIndex(int array[], int start, int size) {
    int min_idx = start;
    for (int i = start + 1; i < size; i++) {
        if (array[i] < array[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

// Implementação recursiva do Selection Sort
void recursiveSelectionSort(int array[], int start, int size) {
    // Caso base: se o subarray tiver tamanho 0 ou 1, já está ordenado
    if (start >= size - 1) {
        return;
    }

    // Encontra o índice do menor elemento no subarray
    int min_idx = findMinIndex(array, start, size);

    // Coloca o menor elemento na posição correta
    swap(array[start], array[min_idx]);

    // Chama recursivamente para o restante do array
    recursiveSelectionSort(array, start + 1, size);
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSortMin(array, size);

    cout << "Array ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}