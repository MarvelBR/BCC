#include <stdio.h>
#include "linked_list.h"

//! Lista Encadeada !//

//? Acesso Sequencial -- Não permite acesso aleatório -- Bom para inserções/remoções em qualquer parte da lista ?//

//Disponível em C++ pela STL como std::forward_list
//std::List é a Lista Duplamente Encadeada 


//* head -> |3| -> |8| -> |2| -> |5| -> _ _  nullptr (nullpointer)


int main() {
    LinkedList* list1 = new LinkedList();

    list1->push_front(3);
    list1->push_front(8);
    list1->push_front(2);
    list1->push_front(5);

    list1->print();

    list1->pop_front();

    delete list1;
}