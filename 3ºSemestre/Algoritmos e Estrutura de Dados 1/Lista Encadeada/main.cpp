#include <stdio.h>
#include "linked_list.h"
#include <iostream>

using namespace std;

//! Lista Encadeada !//

//? Acesso Sequencial -- Não permite acesso aleatório -- Bom para inserções/remoções em qualquer parte da lista ?//

//Disponível em C++ pela STL como std::forward_list
//std::List é a Lista Duplamente Encadeada 


//* head -> |3| -> |8| -> |2| -> |5| -> _ _  nullptr (nullpointer)


int main() {
    LinkedList* list1 = new LinkedList();

    // Testando push_front
    list1->push_front(3); // Adiciona o elemento 3 no início da lista
    list1->push_front(8); // Adiciona o elemento 8 no início da lista
    list1->push_front(2); // Adiciona o elemento 2 no início da lista
    list1->push_front(5); // Adiciona o elemento 5 no início da lista
    // 5 -> 2 -> 8 -> 3 -> _ _  nullptr (nullpointer)

    // Testando push_back
    list1->push_back(10); // Adiciona o elemento 10 no final da lista
    list1->push_back(20); // Adiciona o elemento 20 no final da lista
    // 5 -> 2 -> 8 -> 3 -> 10 -> 20 -> _ _  nullptr (nullpointer)

    // Testando print
    list1->print(); // Imprime os elementos da lista

    // Testando size
    cout << "Tamanho da lista: " << list1->size() << endl; // Imprime o tamanho da lista

    // Testando empty
    cout << "Lista vazia? " << (list1->empty() ? "Sim" : "Nao") << endl; // Verifica se a lista está vazia

    // Testando Pop_front
    list1->pop_front();
    cout << "Depois de pop_front: ";
    list1->print();
    // Removeu o 5 que era onde o head apontava, mas agora aponta para o 2

    //Testando Pop_Back
    list1->pop_back();
    cout << "Depois de pop_back: ";
    list1->print(); 

    // Testando get
    cout << "Elemento na posicao 2: " << list1->get(2) << endl; // Imprime o elemento na posição 2 da lista

    // Testando find
    Node* foundNode = list1->find(8); // Busca o nó que contém a chave 8
    if (foundNode) {
        cout << "Elemento encontrado: " << foundNode->key << endl; // Imprime o elemento encontrado
    } else {
        cout << "Elemento não encontrado." << endl; // Imprime mensagem se o elemento não for encontrado
    }

    // Testando Insert
    list1->insert(15, 2); // Insere o elemento 15 na posição 2 da lista
    cout << "Depois de inserir 15 na posicao 2: ";
    list1->print(); // Imprime os elementos da lista

    // Testando removePos
    list1->removePos(2); // Remove o nó na posição 2 da lista
    cout << "Depois de remover a posicao 2: ";
    list1->print(); // Imprime os elementos da lista

    // Testando removeKey
    list1->removeKey(8); // Remove o nó que contém a chave 8
    cout << "Depois de remover o elemento 8: ";
    list1->print(); // Imprime os elementos da lista

    delete list1;
}