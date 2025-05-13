#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main()
{
    ListSeq ls(5);

    // Testando add
    ls.add(10);
    ls.add(20);
    ls.add(30);
    ls.add(40);
    ls.add(50);

    // Testando isFull
    cout << "Lista cheia? " << (ls.isFull() ? "Sim" : "Nao") << endl;

    // Testando print
    cout << "Elementos da lista: ";
    ls.print();

    // Testando remove
    ls.remove();
    cout << "Apos remover o ultimo elemento: ";
    ls.print();

    // Testando removeAt
    ls.removeAt(1);
    cout << "Apos remover o elemento na posicao 1: ";
    ls.print();

    // Testando find
    int pos = ls.find(30);
    cout << "Posicao do elemento 30: " << pos << endl;

    // Testando get
    int elem = ls.get(2);
    cout << "Elemento na posicao 2: " << elem << endl;

    // Testando resize
    ls.resize();
    cout << "Apos redimensionar a lista: ";
    ls.print();

    // Testando isEmpty
    cout << "Lista vazia? " << (ls.isEmpty() ? "Sim" : "Nao") << endl;

    // Testando Insert
    ls.insert(100, 0);
    cout << "Apos inserir 100 na posicao 0: ";
    ls.print();

    // Testando AddSorted
    ls.addSorted(25);
    cout << "Apos adicionar 25 ordenadamente: ";
    ls.print();

    // Testando list_remove_last
    ls.list_remove_last(2);
    cout << "Apos remover os ultimos 2 elementos: ";
    ls.print();

    // Testando ListGetAvailable
    int rest = ls.list_get_available();
    cout << "Tem " << rest << " espacos restantes!" << endl;

    // Testando Print Reverse
    cout << "Print Reverso: ";
    ls.list_print_reverse();

    // Testando list_is_sorted
    int sorted = ls.list_is_sorted();
    if (sorted == 1)
    {
        cout << "A lista esta ordenada!" << endl;
    }
    else if (sorted == 0)
    {
        cout << "A lista nao esta ordenada!" << endl;
    }
    else
    {
        cout << "A lista esta vazia!" << endl;
    }

    //Testando list_reverse
    ls.list_reverse();
    cout << "Apos inverter a lista: ";
    ls.print();
    
    // Testando list_add
    int vet[] = { 60, 70, 80 };
    int n = sizeof(vet) / sizeof(vet[0]);
    ls.list_add(n, vet);
    cout << "Apos adicionar elementos em lote: ";
    ls.print();

    // Testando list_equal
    ListSeq ls2(5);
    ls2.add(10);
    ls2.add(20);
    ls2.add(30);
    ls2.add(40);
    ls2.add(50);
    int equal = ls.list_equal(&ls2);
    if (equal == 1)
    {
        cout << "As listas sao iguais!" << endl;
    }
    else if (equal == 0)
    {
        cout << "As listas sao diferentes!" << endl;
    }
    else
    {
        cout << "Ambas as listas estao vazias!" << endl;
    }

    // Testando list_from_vector
    int vet2[] = { 90, 100, 110 };
    ListSeq* ls3 = ls.list_from_vector(3, vet2);
    cout << "Lista criada a partir do vetor: ";
    ls3->print();

    // Testando list_copy
    ListSeq* ls4 = ls.list_copy();
    cout << "Copia da lista: ";
    ls4->print();

    // Testando list_concat
    ListSeq ls5(5);
    ls5.add(200);
    ls5.add(300);
    ls5.add(400);
    int concatCount = ls.list_concat(&ls5);
    cout << "Elementos concatenados: " << concatCount << endl;

    // Testando list_clear
    ls.list_clear();
    cout << "Apos limpar a lista: ";
    ls.print();

    // Testando destroy
    ls.destroy();
    cout << "Lista destruida." << endl;

    return 0;
};
