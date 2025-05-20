#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* list1 = new DoubleList();

    // Testando Push Front
    list1->push_front(10);
    list1->push_front(20);
    list1->push_front(30);
    list1->print(); // Esperado: 30 20 10

    // Testando Push Back
    list1->push_back(40);
    list1->push_back(50);
    list1->print(); // Esperado: 30 20 10 40 50

    // Testando Pop Front
    list1->pop_front();
    list1->print(); // Esperado: 20 10 40 50

    // Testando Pop Back
    list1->pop_back();
    list1->print(); // Esperado: 20 10 40

    // Testando Size
    printf("Tamanho da lista: %d\n", list1->size()); // Esperado: 3

    // Testando Empty
    printf("Lista vazia: %s\n", list1->empty() ? "Sim" : "Não"); // Esperado: Não

    // Testando Get
    printf("Elemento na posição 1: %d\n", list1->get(1)); // Esperado: 10

    // Testando Find
    Node* foundNode = list1->find(10);
    if (foundNode) {
        printf("Elemento encontrado: %d\n", foundNode->key); // Esperado: 10
    } else {
        printf("Elemento não encontrado\n");
    }

    // Testando Insert
    list1->insert(25, 1);
    list1->print(); // Esperado: 20 25 10 40

    // Testando Remove Pos
    Node* removedNode = list1->removePos(2);
    if (removedNode) {
        printf("Elemento removido: %d\n", removedNode->key); // Esperado: 10
        delete removedNode; // Libera a memória do nó removido
    } else {
        printf("Elemento não encontrado para remoção\n");
    }
    list1->print(); // Esperado: 20 25 40

    // Testando Remove Key
    list1->removeKey(25);
    list1->print(); // Esperado: 20 40

    

    delete list1;
}