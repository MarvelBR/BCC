#pragma once

class Node {
public:
    int key;
    Node* next;
};


class CircularList {
private:
    Node* head;
    Node* tail;

public:
    CircularList(); //método construtor
    ~CircularList(); // ~ - método destrutor 
    
    bool push_front(int key);
    bool pop_front();
    
    void print();
    int size();
    bool empty();
    
    bool push_back(int key);
    bool pop_back();
    
    int get(int pos);

    Node* find(int key);
    
    void insert_after(int key, Node* pos);
    bool remove_after(Node* pos);
    
    bool insert(int key, int pos);
    Node* removePos(int pos);
    bool removeKey(int key);
    
    bool insert_sorted(int key);

    bool equals(CircularList* other);
};