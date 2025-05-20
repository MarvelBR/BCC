#pragma once

// Definicao do TAD Lista Encadeada

class Node {
public:
    int key;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList(); //método construtor
    ~LinkedList(); // ~ - método destrutor 
    
    bool push_front(int key); // Adiciona um elemento no início da lista
    bool push_back(int key); // Adiciona um elemento no final da lista
    
    void print(); // Imprime os elementos da lista
    int size(); // Retorna o tamanho da lista
    bool empty(); // Verifica se a lista está vazia
    
    bool pop_front(); // Remove o primeiro elemento da lista
    bool pop_back(); // Remove o último elemento da lista
    
    int get(int pos); // Retorna o elemento na posição "pos" da lista

    Node* find(int key); // Retorna o nó que contém a chave "key"
    
    void insert_after(int key, Node* pos); // Insere um novo nó após o nó "pos"
    bool remove_after(Node* pos); // Remove o nó após o nó "pos"
    
    bool insert(int key, int pos); // Insere um novo nó na posição "pos" da lista
    Node* removePos(int pos); // Remove o nó na posição "pos" da lista
    bool removeKey(int key); // Remove o nó que contém a chave "key"

    bool equals(LinkedList* other); // Verifica se duas listas são iguais
    
    void print_last(); // Impre o valor (campo key) do último nó da lista
    bool is_sorted(); // Verifica se a lista está ordenada
    bool push_back_vector(int n, int* vec); //: recebe um array de inteiros (e seu tamanho) e adiciona seus elementos ao final da lista
    // Note que é necessário criar um Node para cada novo elemento.
    bool insert_sorted(int key); // Insere um novo nó na lista de forma ordenada
    LinkedList* deep_copy(); // Cria uma cópia profunda da lista
    LinkedList* concat(LinkedList* list2); // Concatena duas listas encadeadas em uma nova lista
    LinkedList* merge(LinkedList* list2); // Mescla duas listas encadeadas em uma nova lista
    
};