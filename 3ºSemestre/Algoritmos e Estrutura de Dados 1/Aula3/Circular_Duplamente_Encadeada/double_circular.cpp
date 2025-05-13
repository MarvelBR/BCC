#include "double_circular.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

//? Lista Circular Duplamente Encadeada

//*Inserir no fim, basta inserir no anterior do primeiro, eliminando a necessidade de um ponteiro para cauda.

//! Anotar vantagens e desvatagens dos outros tipos de listas!!!!

DoubleCircularList::DoubleCircularList()
{
    this->head = nullptr;
}

DoubleCircularList::~DoubleCircularList()
{
    if (!this->head) // Lista vazia
        return;

    Node *aux = this->head;
    while (aux->next != this->head) // Percorre até o último nó
    {
        Node *temp = aux;
        aux = aux->next;
        delete temp;
    }

    delete aux; // Libera o último nó
    this->head = nullptr;
}

bool DoubleCircularList::push_front(int key)
{
    Node *new_node = new Node{key, nullptr, nullptr};
    if (!new_node)
        return false;

    if (!this->head) // Lista vazia
    {
        new_node->next = new_node->prev = new_node; // Nó aponta para si mesmo
        this->head = this->tail = new_node; // O head agora é o novo nó
    }
    else
    {
        new_node->next = this->head;               // O novo nó aponta para o head atual
        new_node->prev = this->tail;         // O novo nó aponta para o último nó (head->prev)
        this->head->prev->next = new_node;         // O último nó aponta para o novo nó
        this->head->prev = new_node;               // O head atual aponta para o novo nó
        this->head = new_node; 
    }
    return true;
}

bool DoubleCircularList::push_back(int key)
{
    Node *new_node = new Node{key, nullptr, nullptr};
    if (!new_node)
        return false;

    if (!this->head) // Lista vazia
    {
        new_node->next = new_node->prev = new_node; // Nó aponta para si mesmo
        this->head = this->tail = new_node; // O head agora é o novo nó
    }
    else
    {
        Node *tail = this->head->prev; // Último nó
        new_node->next = this->head;
        new_node->prev = tail;
        tail->next = new_node;
        this->head->prev = new_node;
    }
    return true;
}

bool DoubleCircularList::pop_front()
{
    if (!this->head) // Lista vazia
        return false;

    Node *temp = this->head;
    if (this->head->next == this->head) // Apenas um nó na lista
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        Node *tail = this->head->prev; // Último nó
        this->head = this->head->next;
        this->head->prev = tail;
        tail->next = this->head;
    }
    delete temp;
    return true;
}

bool DoubleCircularList::pop_back()
{
    if (!this->head) // Lista vazia
        return false;

    Node *tail = this->head->prev;
    if (this->head->next == this->head) // Apenas um nó na lista
    {
        this->head = nullptr;
    }
    else
    {
        Node *new_tail = tail->prev;
        new_tail->next = this->head;
        this->head->prev = new_tail;
    }
    delete tail;
    return true;
}

int DoubleCircularList::get(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é inválida
        return -1;

    Node *aux = this->head;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->next;
    }

    return aux->key;
}

int DoubleCircularList::size()
{
    if (!this->head) // Lista vazia
        return 0;

    int count = 0;
    Node *aux = this->head;
    while (true)
    {
        count++;
        aux = aux->next;
        if (aux == this->head) // Verifica se voltou ao início
            break;
    }

    return count;
}

bool DoubleCircularList::empty()
{
    return this->head == nullptr;
}

Node *DoubleCircularList::find(int key)
{
    if (!this->head) // Lista vazia
        return nullptr;

    Node *aux = this->head;
    while (true)
    {
        if (aux->key == key)
            return aux;
        aux = aux->next;
        if (aux == this->head) // Verifica se voltou ao início
            break;
    }

    return nullptr; // Chave não encontrada
}

bool DoubleCircularList::insert(int key, int pos)
{
    if (pos < 0 || pos > this->size()) // Verifica se a posição é inválida
        return false;

    if (pos == 0) // Inserção no início
        return this->push_front(key);

    if (pos == this->size()) // Inserção no final
        return this->push_back(key);

    Node *aux = this->head;
    for (int i = 0; i < pos - 1; i++)
    {
        aux = aux->next;
    }

    Node *new_node = new Node{key, aux->next, aux};
    if (!new_node)
        return false;

    aux->next->prev = new_node;
    aux->next = new_node;

    return true;
}

Node *DoubleCircularList::removePos(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é inválida
        return nullptr;

    if (pos == 0) // Remoção do primeiro nó
    {
        Node *removed = this->head;
        this->pop_front();
        return removed;
    }

    Node *aux = this->head;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->next;
    }

    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

    return aux;
}

bool DoubleCircularList::removeKey(int key)
{
    if (!this->head) // Lista vazia
        return false;

    if (this->head->key == key) // Caso especial: o nó a ser removido é o primeiro
    {
        this->pop_front();
        return true;
    }

    Node *aux = this->head;
    while (true)
    {
        if (aux->key == key)
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            delete aux;
            return true;
        }
        aux = aux->next;
        if (aux == this->head) // Verifica se voltou ao início
            break;
    }

    return false; // Chave não encontrada
}

void DoubleCircularList::print()
{
    if (!this->head) // Lista vazia
    {
        std::cout << "Lista vazia" << std::endl;
        return;
    }

    Node *aux = this->head;
    while (true)
    {
        std::cout << aux->key << " "; // Imprime o valor do nó atual
        aux = aux->next;              // Avança para o próximo nó
        if (aux == this->head)        // Verifica se voltou ao início
            break;
    }

    std::cout << std::endl; // Quebra de linha após imprimir todos os elementos
}