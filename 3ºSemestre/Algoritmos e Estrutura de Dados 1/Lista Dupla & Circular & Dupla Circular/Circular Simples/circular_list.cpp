#include "circular_list.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

//? Lista Circular Simples (dificilmente utilizada)

//*Possui a vantagem de não tratar um ponteiro NULL (excteo se estiver vazia)

//! Anotar vantagens e desvatagens dos outros tipos de listas!!!!

CircularList::CircularList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

CircularList::~CircularList()
{
    if (!this->head) // Lista vazia
        return;

    Node *aux = this->head;
    while (aux != this->tail) // Percorre até o último nó
    {
        Node *temp = aux;
        aux = aux->next;
        delete temp;
    }

    delete aux; // Libera o último nó
    this->head = nullptr;
    this->tail = nullptr;
}

bool CircularList::push_front(int key)
{
    Node *new_node = new Node{key, nullptr};
    if (!new_node){
        return false; // Verifica se a alocação de memória foi bem-sucedida
    }

    if (!this->head) // Lista vazia
    {
        this->head = this->tail = new_node; // O novo nó se torna o head e o tail
        new_node->next = new_node; // Nó aponta para si mesmo
    }
    else
    {
        new_node->next = this->head; // O novo nó aponta para o antigo head
        this->head = new_node; // O head agora é o novo nó
        this->tail->next = this->head; // Atualiza o tail para apontar para o novo head
    }
    return true;
}

bool CircularList::pop_front()
{
    if (!this->head) // Lista vazia
        return false;

    Node *temp = this->head;
    if (this->head == this->tail) // Apenas um nó na lista
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        this->head = this->head->next;
        this->tail->next = this->head; // Atualiza o tail para apontar para o novo head
    }
    delete temp;
    return true;
}

int CircularList::get(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é inválida
        return -1; // Retorna -1 para indicar erro

    Node *aux = this->head;
    for (int i = 0; i < pos; i++) // Corrige o loop para avançar apenas até a posição desejada
    {
        aux = aux->next;
    }

    return aux->key;
}

void CircularList::print()
{
    if (!this->head) // Lista vazia
    {
        std::cout << "Lista vazia" << std::endl;
        return;
    }

    Node *aux = this->head;
    while (true)
    {
        std::cout << aux->key << " ";
        aux = aux->next;
        if (aux == this->head) // Verifica se voltou ao início
            break;
    }

    std::cout << std::endl;
}

int CircularList::size()
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

bool CircularList::empty()
{
    return this->head == nullptr;
}

bool CircularList::push_back(int key)
{
    Node *new_node = new Node{key, nullptr};
    if (!new_node)
        return false;

    if (!this->head) // Lista vazia
    {
        this->head = this->tail = new_node; // O novo nó se torna o head e o tail
        new_node->next = new_node; // Nó aponta para si mesmo
    }
    else
    {
        new_node->next = this->head; // O novo nó aponta para o head
        this->tail->next = new_node; // O antigo tail aponta para o novo nó
        this->tail = new_node; // Atualiza o tail
    }
    return true;
}

bool CircularList::pop_back()
{
    if (!this->head) // Lista vazia
        return false;

    Node *temp = this->tail;
    if (this->head == this->tail) // Apenas um nó na lista
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        Node *aux = this->head;
        while (aux->next != this->tail) // Percorre até o penúltimo nó
        {
            aux = aux->next;
        }
        aux->next = this->head; // Atualiza o próximo do penúltimo nó para o head
        this->tail = aux;       // Atualiza o tail
    }
    delete temp;
    return true;
}

Node *CircularList::find(int key)
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

bool CircularList::insert(int key, int pos)
{

    if (pos < 0 || pos > this->size()) // Verifica se a posição é inválida
        return false;

    if (pos == 0) // Inserção no início
        return this->push_front(key);

    if (pos == this->size()) // Inserção no final
        return this->push_back(key);

    Node *aux = this->head;
    for (int i = 0; i < pos - 1; i++) // Percorre até o nó anterior à posição desejada
    {
        aux = aux->next;
    }

    Node *new_node = new Node{key, aux->next};
    if (!new_node)
        return false;

    aux->next = new_node;
    return true;
}

Node *CircularList::removePos(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é inválida
        return nullptr;

    if (pos == 0) // Remoção do primeiro nó
    {
        Node *removed = this->head;
        this->pop_front(); // O pop_front já libera a memória do nó
        return removed;
    }

    Node *aux = this->head;
    for (int i = 0; i < pos - 1; i++) // Percorre até o nó anterior à posição desejada
    {
        aux = aux->next;
    }

    Node *removed = aux->next;
    aux->next = aux->next->next;

    if (removed == this->tail) // Atualiza o tail se o nó removido for o último
        this->tail = aux;

    delete removed; // Libera a memória do nó removido
    return nullptr; // Retorna nullptr, pois o nó foi deletado
}

bool CircularList::removeKey(int key)
{
    if (!this->head) // Lista vazia
        return false;

    if (this->head->key == key) // Caso especial: o nó a ser removido é o primeiro
    {
        this->pop_front();
        return true;
    }

    Node *aux = this->head;
    while (aux->next != this->head) // Percorre até voltar ao início
    {
        if (aux->next->key == key) // Verifica se o próximo nó contém a chave
        {
            Node *temp = aux->next;
            aux->next = aux->next->next;

            if (temp == this->tail) // Atualiza o tail se o nó removido for o último
                this->tail = aux;

            delete temp;
            return true;
        }
        aux = aux->next;
    }

    return false; // Chave não encontrada
}