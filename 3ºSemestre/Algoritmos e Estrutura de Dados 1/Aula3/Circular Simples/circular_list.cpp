#include "circular_list.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

//? Lista Circular Simples (dificilmente utilizada)

//*Possui a vantagem de não tratar um ponteiro NULL (excteo se estiver vazia)

//! Anotar vantagens e desvatagens dos outros tipos de listas!!!!


CircularList::CircularList() {
    this->head = nullptr;
    this->tail = this->head;
}

CircularList::~CircularList() {

}  

bool CircularList::push_front(int key){
    Node* no = new Node{key, nullptr};

    if (!no)
    {
        return false;
    }

    no->next = this->head; //o next do nó ta apontando para quem o head está apontando
    this->head = no; // head aponta para o primeiro do nó
    return true;
}

bool CircularList::push_back(int key) {
    return true;
}

bool CircularList::pop_front() {
    if (this->head)
    {
        Node* aux = this->head;
        this->head = aux->next;
        delete aux;
        return true;
    } else{
        return false;
    }
   
}

bool CircularList::equals(CircularList* other) {
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

int CircularList::get(int pos) {
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

void CircularList::print() {
    Node* no = this->head;

    while (no)
    {
        cout<< "->" << no->key;
        no = no->next;
    }
    
    cout<< endl;
}

int CircularList::size() {
    int n = 0;
    Node* aux = this->head;

    while (aux)
    {
        aux = aux->next;
        n++;
    }
    
    return n;
}

Node* CircularList::find(int key) {
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

void CircularList::insert_after(int key, Node* pos) {
    Node* novo = new Node{key, pos->next};
    pos->next = novo;
}

bool CircularList::remove_after(Node* pos) {
    return true;
}

bool CircularList::insert(int key, int pos) {
    
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

Node* CircularList::removePos(int pos) {
    return nullptr;
}

bool CircularList::removeKey(int key) {
    return true;
}

bool CircularList::pop_back() {
    return true;
}

bool CircularList::empty() {
    return true;
}