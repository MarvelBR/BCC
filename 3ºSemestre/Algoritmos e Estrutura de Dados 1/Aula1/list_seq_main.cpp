#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main(){
    ListSeq ls(5);
    ls.add(12);
    ls.add(2);
    ls.add(30);
    ls.add(4);
    ls.add(5);

    if (ls.isFull())
    {
        ls.resize();
    }
    ls.add(20);

    ls.removeAt(4);

    ls.print();
};

