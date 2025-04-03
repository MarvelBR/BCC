#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

ListSeq::ListSeq(int _capacity){
    data = new int[_capacity]; //new sempre aloca na heap
    capacity = _capacity;
};

bool ListSeq::add(int elem){

    if (size < capacity)
    {
        data[size++] = elem;
        return true;

    } else{
        return false;
    }
    
};

bool ListSeq::isEmpty(){
    return size == 0;
};

bool ListSeq::isFull(){
    return size == capacity;
};

void ListSeq::print(){

    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    
    cout << endl; // mesma coisa que o \n
};

//realoca vetor
bool ListSeq::resize(){
    int* _data = new int[++capacity];

    for (int i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }
    
    delete[] data; //semelhante ao free(), apaga tudo
    data = _data;

    return true;
};

void ListSeq::destroy(){
    delete[] data;
}

void ListSeq::remove(){
    if (!isEmpty())
    {
        size--;
    }  
};

void ListSeq::removeAt(int pos){
    if(pos < size){
        for (int i = pos; i < size-1; i++)
        {
            data[i] = data[i+1];
        }
        size--;
    }

    else if (pos == size -1)
    {
        remove();
    }
    
    else{
        return;
    }
};