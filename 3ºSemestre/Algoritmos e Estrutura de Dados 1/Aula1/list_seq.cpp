#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

ListSeq::ListSeq(int _capacity)
{
    data = new int[_capacity]; // new sempre aloca na heap
    capacity = _capacity;
};

bool ListSeq::add(int elem)
{

    if (size < capacity) // Verifica se há espaço disponível na lista
    {
        data[size++] = elem; // Adiciona o elemento na posição atual de 'size' e incrementa 'size'
        return true;         // Retorna true indicando que o elemento foi adicionado com sucesso
    }
    else
    {
        return false; // Retorna false se a lista estiver cheia
    }
};

bool ListSeq::isEmpty()
{
    return size == 0;
};

bool ListSeq::isFull()
{
    return size == capacity;
};

void ListSeq::print()
{

    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl; // mesma coisa que o \n
};

// realoca vetor
bool ListSeq::resize()
{
    int *_data = new int[++capacity]; // Um novo array dinâmico _data é criado com tamanho capacity + 1.
    // O operador ++capacity incrementa o valor de capacity antes de usá-lo, aumentando a capacidade da lista em 1.
    // Isso significa que a lista terá espaço para armazenar mais um elemento.

    for (int i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }

    // O loop for copia os elementos existentes da lista original (data) para o novo array (_data).
    // Isso garante que os elementos já armazenados na lista sejam mantidos após o redimensionamento.

    delete[] data; // semelhante ao free(), apaga tudo
    data = _data;

    return true;
};

void ListSeq::destroy()
{
    delete[] data;
}

void ListSeq::remove()
{
    if (!isEmpty()) // Verifica se a lista não está vazia
    {
        size--; // Decrementa o tamanho da lista, "removendo" o último elemento
    }
};

void ListSeq::removeAt(int pos)
{
    if (pos < size) // Caso 1: Posição válida dentro do intervalo
    {
        for (int i = pos; i < size - 1; i++)
        // O loop for começa na posição pos e continua até o penúltimo elemento (size - 1).
        // Ele copia o próximo elemento (i + 1) para a posição atual (i), efetivamente "removendo" o elemento na posição pos.
        {
            data[i] = data[i + 1]; // Copia o próximo elemento para a posição atual
        }
        size--; // Decrementa o tamanho da lista
    }

    else if (pos == size - 1) // Caso 2: Posição é o último elemento
    {
        remove(); // Reutiliza o método remove() para remover o último elemento
    }

    else // Caso 3: Posição inválida (fora do intervalo)
    {
        return;
    }
};

int ListSeq::find(int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (elem == data[i])
        {
            return i;
        }
    }
    return -1;
}

int ListSeq::get(int pos)
{
    if (pos >= size)
    {
        return -1;
    }

    return data[pos];
}

void ListSeq::insert(int elem, int pos)
{
    if (pos < size) // Verifica se a posição é válida
    {
        for (int i = size; i > pos; i--)
        {
            data[i] = data[i - 1]; // Move os elementos para a direita
        }
        data[pos] = elem; // Insere o novo elemento na posição desejada
        size++;           // Incrementa o tamanho da lista
    }
    else if (pos == size) // Se a posição for igual ao tamanho atual da lista
    {
        add(elem); // Adiciona o elemento ao final da lista
    }
    else // Caso 3: Posição inválida (fora do intervalo)
    {
        return;
    }
}

bool ListSeq::addSorted(int elem)
// Adiciona um elemento à lista de forma ordenada
{
    if (isFull()) // Verifica se a lista está cheia
    {
        return false; // Retorna false se a lista estiver cheia
    }

    // Ordena a lista antes de inserir o elemento
    std::sort(data, data + size);

    // A função std::sort ordena os elementos no intervalo [begin, end) em ordem crescente.
    // O intervalo é definido por dois iteradores: begin (início) e end (fim).
    // data é o ponteiro para o início do array que contém os elementos da lista.
    // data + size é o ponteiro para a posição logo após o último elemento da lista.

    // Encontra a posição correta para inserir o elemento
    int i = 0;
    while (i < size && data[i] < elem)
    {
        i++;
    }

    // Insere o elemento na posição encontrada
    insert(elem, i);

    return true; // Retorna true indicando que o elemento foi adicionado com sucesso
}

int ListSeq::list_get_available()
{

    int dif = capacity - size;

    return dif;
}

void ListSeq::list_clear()
{
    while (!isEmpty()) // Enquanto a lista não estiver vazia
    {
        remove(); // Remove o último elemento
    }
}

void ListSeq::list_remove_last(int n)
{
    if (n <= 0)
    {
        return;
    }
    else if (n >= size)
    {
        list_clear(); // Remove todos os elementos
    }
    else
    {
        int dif = size - n;
        int size2 = size;
        for (int i = dif; i < size2; i++)
        {
            remove();
        }
    }
}

void ListSeq::list_print_reverse()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[size - i - 1] << " ";
    }

    cout << endl;
}

void ListSeq::list_add(int n, int* vet){
    for (int i = 0; i < n; i++)
    {
        if (isFull())
        {
            break;
        }
        add(vet[i]);
    }
}

int ListSeq::list_is_sorted(){
    if (isEmpty())
    {
        return -1; // Lista vazia
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] > data[i + 1])
        {
            return 0; // Lista não ordenada
        }
    }

    return 1; // Lista ordenada
}

void ListSeq::list_reverse(){

    ListSeq ls2(size); //variável local, que será "destruída" ao final do escopo

    for (int i = 0; i < size; i++)
    {
        ls2.add(data[i]);
    }

    for (int i = 0; i < size; i++)
    {
        data[size-i-1] = ls2.data[i];
    }
}

int ListSeq::list_equal(ListSeq* outra){
    if (isEmpty() && outra->isEmpty())
    {
        return -1; // Ambas as listas estão vazias
    }

    if (size != outra->size)
    {
        return 0; // As listas têm tamanhos diferentes
    }

    for (int i = 0; i < size; i++)
    {
        if (data[i] != outra->data[i])
        {
            return 0; // As listas não são iguais
        }
    }

    return 1; // As listas são iguais
}

ListSeq* ListSeq::list_from_vector(int n, int* vet){
    ListSeq* ls2 = new ListSeq(n * 2); // Cria uma nova lista com o dobro do tamanho do vetor
    // Aloca a ls2 na heap usando 'new' e retorna o ponteiro.
    for (int i = 0; i < n; i++)
    {
        ls2->add(vet[i]); // Adiciona os elementos do vetor à nova lista
    }

    return ls2; // Retorna o endereço da nova lista

    //aqui o ls2 não é destruído, pois o retorno é um ponteiro para a lista alocada na heap.
    // Se eu fizesse igual no list_reverse(), o ls2 seria destruído ao final do escopo e o retorno seria inválido.
}

ListSeq* ListSeq::list_copy(){

    ListSeq* ls2 = new ListSeq(size); // Cria uma nova lista com o mesmo tamanho da original
    // Aloca a ls2 na heap usando 'new' e retorna o ponteiro.
    for (int i = 0; i < size; i++)
    {
        ls2->add(data[i]); // Adiciona os elementos da lista original à nova lista
    }

    return ls2; // Retorna o endereço da nova lista
}

int ListSeq::list_concat(ListSeq* list2){
    if (isFull() || list2->isEmpty())
    {
        return 0; // Retorna 0 se a lista estiver cheia ou se a lista a ser concatenada estiver vazia
    }

    int count = 0; // Contador de elementos adicionados

    for (int i = 0; i < list2->size; i++)
    {
        if (add(list2->data[i])) // Adiciona os elementos da lista a serem concatenados
        {
            count++; // Incrementa o contador se o elemento foi adicionado com sucesso
        }
    }

    // Se a lista original estiver cheia antes de adicionar todos os elementos, o loop para
    // e o contador 'count' terá o número de elementos que foram realmente adicionados.

    return count; // Retorna a quantidade de elementos adicionados
}