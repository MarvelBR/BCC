#include <iostream>

using namespace std;

// TAD - Tipos Abstratros de Dados

class ListSeq
{
public:
    int size = 0; // número de posições ocupadas - controla as ocupações
    int capacity; // capacidade da lista (tamanho do vetor)
    int *data;    // endereço (aponta) do vetor na heap

    // construtor que cria a instância da lista
    ListSeq(int _capacity);

    // Libera a memória alocada para o vetor
    void destroy();

    // Realoca o vetor
    bool resize();

    // Printa
    void print();

    // Retorna posição do elemento ou -1
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

    int list_get_available(); // retorna a quantidade de posições livres restantes.

    void list_clear(); // remove todos os elementos da lista

    void list_remove_last(int n); //remover os últimos N elementos da lista ou o mais próximo disso

    void list_print_reverse(); // imprime a lista na ordem inversa

    void list_add(int n, int* vet); //adicionar elementos em lote: recebe um vetor de inteiros, assim como seu tamanho, e os adiciona ao final da lista, enquanto houver espaço.

    int list_is_sorted(); //verifica se a lista está ordenada, retornando 1 se estiver, 0 se não estiver e -1 se a lista estiver vazia.

    void list_reverse(); //inverte a lista, alterando a ordem dos elementos.

    int list_equal(ListSeq* outra); //compara duas listas, retornando 1 se forem iguais, 0 se não forem e -1 se a lista estiver vazia.

    ListSeq* list_from_vector(int n, int* vet); //  cria e devolve uma Lista Sequencial a partir do conteúdo de um array, informado como parâmetro. 
    //A Lista Sequencial deve ser criada com um tamanho 2 vezes maior que o do vetor.

    ListSeq* list_copy(); //cria e devolve uma cópia da lista passada. A cópia deve conter os mesmos valores da original.

    int list_concat(ListSeq* list2); //concatena o conteúdo de list2 ao final, obedecendo a capacidade original. O
    //Método deve retornar a quantidade de elementos adicionados
};
