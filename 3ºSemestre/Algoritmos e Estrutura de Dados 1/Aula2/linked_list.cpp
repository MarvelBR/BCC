#include "linked_list.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
    Node *aux = this->head; // Ponteiro auxiliar para percorrer a lista
    while (aux) // Enquanto houver nós na lista
    {
        Node *temp = aux; // Armazena o nó atual
        aux = aux->next;  // Avança para o próximo nó
        delete temp;      // Libera a memória do nó atual
    }
    this->head = nullptr; // Atualiza o ponteiro "head" para nullptr, indicando que a lista está vazia
}

bool LinkedList::push_front(int key)
{ // Adiciona um nó no início da lista
    Node *no = new Node{key, nullptr};

    if (!no) // Verifica se a alocação de memória foi bem-sucedida
    {
        return false;
    }

    no->next = this->head; // O ponteiro "next" do novo nó aponta para o nó atual "head"
    this->head = no;       // O ponteiro "head" agora aponta para o novo nó, tornando-o o primeiro nó da lista
    return true;           // Retorna true indicando que o nó foi adicionado com sucesso
}

bool LinkedList::push_back(int key)
{
    Node *no = new Node{key, nullptr};

    if (!no) // Verifica se a alocação de memória foi bem-sucedida
    {
        return false;
    }

    if (!this->head) // Se a lista estiver vazia, o novo nó se torna o primeiro nó
    {
        this->head = no;
    }
    else
    {
        Node *aux = this->head; // Ponteiro auxiliar para percorrer a lista
        while (aux->next)       // Percorre até o último nó da lista
        {
            aux = aux->next;
        }
        aux->next = no; // O ponteiro "next" do último nó aponta para o novo nó
    }

    return true;
}

void LinkedList::print()
{
    Node *aux = this->head;

    while (aux)
    {
        cout << aux->key << "->";
        aux = aux->next;
    }

    cout << endl;
}

int LinkedList::size()
{
    int n = 0;
    Node *aux = this->head;

    while (aux) // Percorre a lista contando o número de nós
    {
        aux = aux->next;
        n++;
    }

    return n;
}

// O While(aux) percorre todos os nós da lista, ele "passa" pelo último nó e chega ao nullptr.
// Já o While(aux->next) para no último nó da lista, porém não vai até o nullptr.
// Portanto, o primeiro loop conta todos os nós, enquanto o segundo loop conta apenas até o penúltimo nó.


bool LinkedList::empty()
{
    if (this->head == nullptr) // Verifica se o ponteiro "head" é nulo, indicando que a lista está vazia
    {
        return true; // Retorna true se a lista estiver vazia
    }
    
    return false; // Retorna false se a lista não estiver vazia
}

bool LinkedList::pop_front()
{
    if (this->head) // Verifica se a lista não está vazia
    // Se a lista não estiver vazia, remove o primeiro nó
    {
        Node *aux = this->head; // Ponteiro auxiliar para armazenar o nó a ser removido
        this->head = aux->next; // O ponteiro "head" agora aponta para o segundo nó da lista
        delete aux; // Libera a memória do nó removido
        return true;
    }
    else
    {
        return false;
    }
}

bool LinkedList::pop_back()
{
    if (!this->head)
    {
        return false; // Retorna false se a lista estiver vazia
    }
   
    if (!this->head->next) // Caso especial: apenas um nó na lista || um if (this->size() == 1) também funcionaria
    {
        delete this->head;
        this->head = nullptr; // Atualiza o ponteiro "head" para nullptr
        return true;
    }

    Node *aux = this->head;

    while (aux->next->next) // Percorre a lista até o penúltimo nó  || Um while(this.size() - 1) também funcionaria
    {
        aux = aux->next; 
    }
    
    delete aux->next; // Libera a memória do último nó
    aux->next = nullptr; // O ponteiro "next" do penúltimo nó agora aponta para nullptr, removendo o último nó da lista
    return true; // Retorna true indicando que o nó foi removido com sucesso
}

int LinkedList::get(int pos)
{
    Node *aux = this->head;

    if (pos < 0 || pos >= this->size()) // Verifica se a posição é válida
    {
        return 0; // Retorna 0 se a posição for inválida
    }

    for (int i = 0; i < pos; i++) // Percorre a lista até a posição desejada
    {
        aux = aux->next;
    }

    return aux->key; // Retorna a chave do nó na posição desejada
}

Node* LinkedList::find(int key)
{
    Node* aux = this->head;

    while (aux) // Percorre a lista enquanto houver nós
    {
        if (aux->key == key) // Verifica se o nó atual contém a chave
        {
            return aux; // Retorna o nó encontrado
        }
        aux = aux->next; // Avança para o próximo nó
    }

    return nullptr; // Retorna nullptr se a chave não for encontrada
}

void LinkedList::insert_after(int key, Node *pos)
{
    Node *novo = new Node{key, pos->next};
    pos->next = novo;
}

bool LinkedList::remove_after(Node *pos)
{
    return true;
}

bool LinkedList::insert(int key, int pos)
{
    if (pos < 0 || pos > this->size()) // Verifica se a posição é válida
    {
        return false; // Retorna false se a posição for inválida
    }

    if (pos == 0) // Insere no início da lista
    {
        return this->push_front(key);
    }

    Node *aux = this->head;
    for (int i = 0; i < pos - 1 && aux; i++) // Percorre a lista até o nó anterior à posição desejada
    //O loop precisa parar no nó anterior à posição pos para que o novo nó possa ser inserido corretamente.
    //O loop também verifica se aux não é nulo, garantindo que não acesse um ponteiro nulo.
    {
        aux = aux->next;
    }

    Node *novo = new Node{key, aux->next}; // Cria um novo nó com a chave e o ponteiro "next" apontando para o próximo nó
    if (!novo) // Verifica se a alocação de memória foi bem-sucedida
    {
        return false;
    }

    aux->next = novo; // O ponteiro "next" do nó anterior agora aponta para o novo nó
    //O novo nó é inserido na lista, e o ponteiro "next" do nó anterior agora aponta para o novo nó.

    return true;
}

Node *LinkedList::removePos(int pos)
{
    if (pos < 0 || pos >= this->size()) // Verifica se a posição é válida
    {
        return nullptr; // Retorna nullptr se a posição for inválida
    }
    if (pos == 0) // Se a posição for 0, remove o primeiro nó
    {
        pop_front();
        return this->head; // Retorna o novo primeiro nó (ou nullptr se a lista estiver vazia)
    }

    if (pos == this->size() - 1) // Se a posição for o último nó, remove o último nó
    {
        pop_back();
        return nullptr; // Retorna nullptr, pois o último nó foi removido
    } 
    
    Node *aux = this->head;
    for (int i = 0; i < pos - 1 && aux; i++) // Percorre a lista até o nó anterior à posição desejada
    {
        aux = aux->next;
    }
    Node* temp = aux->next; // Armazena o nó a ser removido
    aux->next = aux->next->next; // Atualiza o ponteiro "next" do nó anterior para pular o nó a ser removido
    delete temp; // Libera a memória do nó removido
    return aux->next; // Retorna o próximo nó após o nó removido
}

bool LinkedList::removeKey(int key)
{
    if (!this->head) // Verifica se a lista está vazia
    {
        return false;
    }

    // Caso especial: o nó a ser removido é o primeiro
    if (this->head->key == key)
    {
        Node *temp = this->head; // Armazena o nó a ser removido
        this->head = this->head->next; // Atualiza o ponteiro "head" para o próximo nó
        delete temp; // Libera a memória do nó removido
        return true;
    }

    Node *aux = this->head;

    // Percorre a lista procurando o nó com a chave
    while (aux->next) // Garante que aux->next não seja nullptr
    {
        if (aux->next->key == key) // Verifica se o próximo nó contém a chave
        {
            Node *temp = aux->next; // Armazena o nó a ser removido
            aux->next = aux->next->next; // Atualiza o ponteiro "next" do nó atual para pular o nó a ser removido
            delete temp; // Libera a memória do nó removido
            return true; // Retorna true indicando que o nó foi removido com sucesso
        }
        aux = aux->next; // Avança para o próximo nó
    }

    return false; // Retorna false se a chave não for encontrada
}

bool LinkedList::equals(LinkedList *other)
{
    Node *a1 = this->head;
    Node *a2 = other->head;

    while (a1 && a2)
    {
        if (a1->key == a2->key)
        {
            a1 = a1->next;
            a2 = a2->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void LinkedList::print_last()
{
    Node *aux = this->head;

    while (aux->next) // Percorre a lista até o último nó
    {
        aux = aux->next;
    }

    cout << aux->key << endl; // Imprime o valor (campo key) do último nó da lista
}

bool LinkedList::is_sorted()
{
    Node *aux = this->head;

    while (aux && aux->next) // Percorre a lista enquanto houver nós
    {
        if (aux->key > aux->next->key) // Verifica se a chave do nó atual é maior que a do próximo nó
        {
            return false; // Retorna false se a lista não estiver ordenada
        }
        aux = aux->next; // Avança para o próximo nó
    }

    return true; // Retorna true se a lista estiver ordenada
}

bool LinkedList::push_back_vector(int n, int *vec)
{
    for (int i = 0; i < n; i++)
    {
        this->push_back(vec[i]); // Adiciona cada elemento do vetor ao final da lista
    }
    return true;
}

bool LinkedList::insert_sorted(int key)
{
    if (this->empty() || this->head->key >= key) // Verifica se a lista está vazia ou se o novo nó deve ser inserido no início
    {
        return this->push_front(key); // Insere o novo nó no início da lista
    }

    Node *aux = this->head;
    while (aux->next && aux->next->key < key) // Percorre a lista até encontrar a posição correta para inserir o novo nó
    {
        aux = aux->next;
    }

    Node *novo = new Node{key, aux->next}; // Cria um novo nó com a chave e o ponteiro "next" apontando para o próximo nó
    if (!novo) // Verifica se a alocação de memória foi bem-sucedida
    {
        return false;
    }

    aux->next = novo; // O ponteiro "next" do nó anterior agora aponta para o novo nó

    return true; // Retorna true indicando que o nó foi inserido com sucesso
}

LinkedList* LinkedList::deep_copy()
{
    LinkedList* new_list = new LinkedList(); // Cria uma nova lista encadeada
    Node* aux = this->head; // Ponteiro auxiliar para percorrer a lista original

    while (aux) // Percorre a lista original
    {
        new_list->push_back(aux->key); // Adiciona cada elemento à nova lista
        aux = aux->next; // Avança para o próximo nó
    }

    return new_list; // Retorna a nova lista encadeada
}

LinkedList* LinkedList::concat(LinkedList* list2)
{
    LinkedList* new_list = new LinkedList(); // Cria uma nova lista encadeada
    Node* aux = this->head; // Ponteiro auxiliar para percorrer a lista original

    while (aux) // Percorre a lista original
    {
        new_list->push_back(aux->key); // Adiciona cada elemento à nova lista
        aux = aux->next; // Avança para o próximo nó
    }

    aux = list2->head; // Ponteiro auxiliar para percorrer a segunda lista

    while (aux) // Percorre a segunda lista
    {
        new_list->push_back(aux->key); // Adiciona cada elemento à nova lista
        aux = aux->next; // Avança para o próximo nó
    }

    return new_list; // Retorna a nova lista encadeada concatenada
}

LinkedList* LinkedList::merge(LinkedList* list2)
{
    LinkedList* new_list = new LinkedList(); // Cria uma nova lista encadeada
    Node* aux1 = this->head; // Ponteiro auxiliar para percorrer a primeira lista
    Node* aux2 = list2->head; // Ponteiro auxiliar para percorrer a segunda lista

    while (aux1 && aux2) // Enquanto houver nós em ambas as listas
    {
        if (aux1->key < aux2->key) // Compara as chaves dos nós
        {
            new_list->push_back(aux1->key); // Adiciona o nó da primeira lista à nova lista
            aux1 = aux1->next; // Avança para o próximo nó da primeira lista
        }
        else
        {
            new_list->push_back(aux2->key); // Adiciona o nó da segunda lista à nova lista
            aux2 = aux2->next; // Avança para o próximo nó da segunda lista
        }
    }

    while (aux1) // Adiciona os nós restantes da primeira lista, se houver
    {
        new_list->push_back(aux1->key); // Adiciona o nó da primeira lista à nova lista
        aux1 = aux1->next; // Avança para o próximo nó da primeira lista
    }

    while (aux2) // Adiciona os nós restantes da segunda lista, se houver
    {
        new_list->push_back(aux2->key); // Adiciona o nó da segunda lista à nova lista
        aux2 = aux2->next; // Avança para o próximo nó da segunda lista
    }

    return new_list; // Retorna a nova lista encadeada mesclada
}
// O método merge combina duas listas encadeadas ordenadas em uma nova lista encadeada ordenada.