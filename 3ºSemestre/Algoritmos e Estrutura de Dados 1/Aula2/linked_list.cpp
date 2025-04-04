#include "linked_list.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {

}  

bool LinkedList::push_front(int key){
    Node* no = new Node{key, nullptr};

    if (!no)
    {
        return false;
    }

    no->next = this->head; //o next do nó ta apontando para quem o head está apontando
    this->head = no; // head aponta para o primeiro do nó
    return true;
}

bool LinkedList::push_back(int key) {
    return true;
}

bool LinkedList::pop_front() {
    return true;
}

bool LinkedList::equals(LinkedList* other) {
    return false;
}

int LinkedList::get(int pos) {
    return 0;
}

void LinkedList::print() {
    Node* no = this->head;

    while (no)
    {
        cout<< "->" << no->key;
        no = no->next;
    }
    
}

int LinkedList::size() {
    return 0;
}

Node* LinkedList::find(int key) {
    return nullptr;
}

bool LinkedList::insert_after(int key, Node* pos) {
    return true;
}

bool LinkedList::remove_after(Node* pos) {
    return true;
}

bool LinkedList::insert(int pos) {
    return true;
}

bool LinkedList::remove(int pos) {
    return true;
}

bool LinkedList::remove(int key) {
    return true;
}

bool LinkedList::pop_back() {
    return true;
}

bool LinkedList::empty() {
    return true;
}