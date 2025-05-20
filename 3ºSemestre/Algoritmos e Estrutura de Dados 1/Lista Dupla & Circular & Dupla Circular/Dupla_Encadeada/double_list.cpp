#include "double_list.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

//? Lista Duplamente Encadeada

//* Cada nó possui dois ponteiros, prev e next, que apontam, respectivamente ao nó anterior e ao próximo, na lista

//* Facilita ainda mais inserções/remoções em qualquer parte da lista

//! Disponível em C++ pela STL como std::List

//? Ponteiro para Cauda -- Sentinela

//! Anotar vantagens e desvatagens dos outros tipos de listas!!!!

DoubleList::DoubleList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleList::~DoubleList()
{
    Node *aux = this->head;
    while (aux)
    {
        Node *temp = aux;
        aux = aux->next;
        delete temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

bool DoubleList::push_front(int key) {
    Node *new_node = new Node{key, nullptr, nullptr};

    if (!new_node){
        return false; // Verifica se a alocação de memória foi bem-sucedida
    }

    if (!this->head) // Lista vazia
    {
        this->head = this->tail = new_node; // O novo nó se torna o primeiro e o último nó da lista
    }
    else
    {
        new_node->next = this->head; // O ponteiro "next" do novo nó aponta para o nó atual "head"
        this->head->prev = new_node; // O ponteiro "prev" do nó atual "head" aponta para o novo nó
        this->head = new_node; // O ponteiro "head" agora aponta para o novo nó, tornando-o o primeiro nó da lista
    }
    return true;
}

bool DoubleList::pop_front() {
    if (!this->head) {// Lista vazia
        return false; // Retorna false se a lista estiver vazia
    } 

    Node *temp = this->head;
    if (this->head == this->tail) // Apenas um nó na lista
    {
        this->head = this->tail = nullptr; // Ambos os ponteiros "head" e "tail" são definidos como nullptr
    }
    else
    {
        this->head = this->head->next; // O ponteiro "head" agora aponta para o segundo nó da lista
        this->head->prev = nullptr; // O ponteiro "prev" do novo primeiro nó é definido como nullptr
    }
    delete temp; // Libera a memória do nó removido
    return true;
}

bool DoubleList::push_back(int key) {
    Node *new_node = new Node{key, nullptr, nullptr};

    if (!new_node){
        return false; // Verifica se a alocação de memória foi bem-sucedida
    }

    if (!this->tail) // Lista vazia
    {
        this->head = this->tail = new_node; // O novo nó se torna o primeiro e o último nó da lista
    }
    else
    {
        new_node->prev = this->tail; // O ponteiro "prev" do novo nó aponta para o nó atual "tail"
        this->tail->next = new_node; // O ponteiro "next" do nó atual "tail" aponta para o novo nó
        this->tail = new_node; // O ponteiro "tail" agora aponta para o novo nó, tornando-o o último nó da lista
    }
    return true;
}

bool DoubleList::pop_back() {
    if (!this->tail){ // Lista vazia
        return false; // Retorna false se a lista estiver vazia
    } 

    Node *temp = this->tail;
    if (this->head == this->tail) // Apenas um nó na lista
    {
        this->head = this->tail = nullptr; // Ambos os ponteiros "head" e "tail" são definidos como nullptr
    }
    else
    {
        this->tail = this->tail->prev; // O ponteiro "tail" agora aponta para o penúltimo nó da lista
        this->tail->next = nullptr; // O ponteiro "next" do novo último nó é definido como nullptr
    }
    delete temp;
    return true;
}

int DoubleList::get(int pos) {
    if (pos < 0 || pos >= this->size()){
        return -1; // Retorna -1 para posição inválida
    }
        
    Node *aux = this->head;
    for (int i = 0; i < pos; i++) 
    {
        aux = aux->next;
    }
    return aux->key;
}

void DoubleList::print() {
    Node *aux = this->head;
    while (aux)
    {
        std::cout << aux->key << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

int DoubleList::size() {
    int count = 0;
    Node *aux = this->head;
    while (aux)
    {
        count++;
        aux = aux->next;
    }
    return count;
}

bool DoubleList::empty() {
    return this->head == nullptr;
}

Node *DoubleList::find(int key)
{
    Node *aux = this->head;
    while (aux)
    {
        if (aux->key == key)
            return aux;
        aux = aux->next;
    }
    return nullptr;
}

bool DoubleList::insert(int key, int pos)
{
    if (pos < 0 || pos > this->size()) // Verifica se a posição é inválida
    {
        return false;
    }

    if (pos == 0) // Inserção no início
    {
        return this->push_front(key);
    }

    if (pos == this->size()) // Inserção no final
    {
        return this->push_back(key);
    }

    Node *aux = this->head;
    for (int i = 0; i < pos - 1; i++) // Percorre até o nó anterior à posição desejada
    {
        aux = aux->next;
    }

    Node *new_node = new Node{key, aux->next, aux}; // Cria o novo nó
    if (!new_node)
    {
        return false;
    }

    aux->next->prev = new_node; // Atualiza o ponteiro "prev" do próximo nó
    aux->next = new_node;       // Atualiza o ponteiro "next" do nó anterior

    return true;
}

Node *DoubleList::removePos(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é inválida
    {
        return nullptr;
    }

    if (pos == 0) // Remoção do primeiro nó
    {
        Node *removed = this->head;
        this->pop_front();
        return removed;
    }

    if (pos == this->size() - 1) // Remoção do último nó
    {
        Node *removed = this->tail;
        this->pop_back();
        return removed;
    }

    Node *aux = this->head;
    for (int i = 0; i < pos; i++) // Percorre até o nó na posição desejada
    {
        aux = aux->next;
    }

    aux->prev->next = aux->next; // Atualiza o ponteiro "next" do nó anterior
    aux->next->prev = aux->prev; // Atualiza o ponteiro "prev" do próximo nó

    aux->next = aux->prev = nullptr; // Desconecta o nó removido
    return aux;                      // Retorna o nó removido
}

bool DoubleList::removeKey(int key)
{
    if (!this->head) // Verifica se a lista está vazia
    {
        return false;
    }

    if (this->head->key == key) // Caso especial: o nó a ser removido é o primeiro
    {
        this->pop_front();
        return true;
    }

    if (this->tail->key == key) // Caso especial: o nó a ser removido é o último
    {
        this->pop_back();
        return true;
    }

    Node *aux = this->head;
    while (aux) // Percorre a lista procurando o nó com a chave
    {
        if (aux->key == key)
        {
            aux->prev->next = aux->next; // Atualiza o ponteiro "next" do nó anterior
            if (aux->next)               // Verifica se não é o último nó
            {
                aux->next->prev = aux->prev; // Atualiza o ponteiro "prev" do próximo nó
            }

            delete aux; // Libera a memória do nó removido
            return true;
        }
        aux = aux->next; // Avança para o próximo nó
    }

    return false; // Retorna false se a chave não for encontrada
}