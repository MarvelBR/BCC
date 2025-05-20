#include <stdio.h>
#include "double_circular.h"

int main() {
    CircularList2* list1 = new CircularList2();

    list1->push_front(3);
    list1->push_front(8);
    list1->push_front(2);
    list1->push_front(5);

    //list1->print();

    //list1->pop_front();

    //list1->print();

    list1->size(); //fazer o print depois 

    list1->find(2);

    list1->print();

    //testar o

    delete list1;
}