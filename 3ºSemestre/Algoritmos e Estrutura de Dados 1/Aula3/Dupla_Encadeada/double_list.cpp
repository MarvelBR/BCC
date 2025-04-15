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

LinkedList2::LinkedList2() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList2::~LinkedList2() {

}  

bool LinkedList2::push_front(int key){
    Node* no = new Node{key, nullptr};

    if (!no)
    {
        return false;
    }

    no->next = this->head; 
    this->head = no; 
    no->next->prev = no;

    if (no->next)
    {
        no->next->prev = no;
    } else{
        this->tail = no;
    }

    return true;
}

bool LinkedList2::push_back(int key) {
    return true;
}

bool LinkedList2::pop_front() {
    if (this->head)
    {
        Node* aux = this->head;
        this->head = aux->next;
        if (!this->head)
        {
            this->tail = nullptr;
        }
        delete aux;
        return true;
    } else{
        return false;
    }
   
}

bool LinkedList2::equals(LinkedList2* other) {
    Node* a1 = this->head;
    Node* a2 = other->head;

    while (a1 && a2)
    {
        if (a1->key == a2->key)
        {
            a1 = a1->next;
            a2 = a2->next;
        } else{
            return false;
        }
    }
    return true;
}

int LinkedList2::get(int pos) {
    Node* aux = this->head;

    if (pos >= this->size())
    {
        return 0;
    }

    for (int i = 0; i <= pos; i++)
    {
        aux = aux->next;
    }

    return aux->key;
}

void LinkedList2::print() {
    Node* no = this->head;

    while (no)
    {
        cout<< "->" << no->key;
        no = no->next;
    }
    
    cout<< endl;
}

int LinkedList2::size() {
    int n = 0;
    Node* aux = this->head;

    while (aux)
    {
        aux = aux->next;
        n++;
    }
    
    return n;
}

Node* LinkedList2::find(int key) {
    Node* aux = this->head;
    
    for (int i = 0; i < this->size(); i++)
    {
        if (aux->key == key)
        {
            break;
        } else{
            aux = aux->next;
        }
    }
    cout<< "Find: " << aux->key;
    cout<< endl;
    return aux;
}

void LinkedList2::insert_after(int key, Node* pos) {
    Node* novo = new Node{key, pos->next};
    pos->next = novo;
}

bool LinkedList2::remove_after(Node* pos) {
    return true;
}

bool LinkedList2::insert(int key, int pos) {
    
    if (pos == 0){
        return this->push_front(key);
    }

    Node* aux = this->head;
    for (int i = 0; i < pos-1 && aux; i++)
    {
        if (!aux)
        {
            return false;
        }
        
        aux = aux->next;
    }
    Node* novo = new Node{key, aux->next};
    aux->next = novo;

    return true;
}

Node* LinkedList2::removePos(int pos) {
    return nullptr;
}

bool LinkedList2::removeKey(int key) {
    return true;
}

bool LinkedList2::pop_back() {
    return true;
}

bool LinkedList2::empty() {
    return true;
}