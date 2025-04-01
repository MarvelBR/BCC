#include <iostream>

using namespace std;

//TAD - Tipos Abstratros de Dados

class ListSeq {
    public:
        int size = 0;   // número de posições ocupadas - controla as ocupações
        int capacity;   // capacidade da lista (tamanho do vetor)
        int* data;      // endereço (aponta) do vetor na heap

        //construtor que cria a instância da lista
        ListSeq (int _capacity);

        //Libera a memória alocada para o vetor
        void destroy();

        // Realoca o vetor
        bool resize();

        //Printa
        void print();

        //Retorna posição do elemento ou -1
        int find(int elem);

        // obtém o elemento na posição passada
        int get(int pos);

        // lista vazia?
        bool isEmpty();

        // 
        bool isFull();

        bool add(int elem);

        void remove();

        void insert(int elem, int pos);

        void removeAt(int pos);

        bool addSorted(int elem);
};
