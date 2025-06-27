#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 1) Função que imprime 10 vezes a mesma linha de texto
void print_txt(char *text, int num = 10)
{
    if (num <= 0)
    {
        return;
    }
    cout << text << endl;
    print_txt(text, num - 1);
}

// Função auxiliar da 2 da 3
void countAux(int x, int num)
{
    if (num <= 0)
    {
        return;
    }
    cout << x << " ";
    x++;
    countAux(x, num - 1);
};

// 2) Função que imprime uma contagem de 0 à 50, num vezes
void count(int num)
{
    if (num <= 0)
    {
        return;
    }
    countAux(0, 51);
    count(num - 1);
}

// 3) Função que imprime uma contagem de 0 à max, num vezes
void count_max(int num, int max)
{
    if (num <= 0)
        return;
    countAux(0, max + 1);
    count_max(num - 1, max);
}

// 4) Função que imprime todos os elementos de uma Lista Sequencial (vector)
void print_vec(vector<int> &vec, int idx = 0)
{
    if (idx < 0 || idx > vec.size() - 1)
    {
        return;
    }
    cout << vec[idx] << " ";
    print_vec(vec, idx + 1);
}

// 5) Função que imprime todos os elementos pares de uma Lista Sequencial (vector), em ordem inversa
void print_even(vector<int> &vec, int idx)
{
    if (idx < 0 || idx > vec.size())
    {
        return;
    }
    if (vec[idx] % 2 == 0)
    {
        cout << vec[idx] << " ";
    }
    print_even(vec, idx - 1);
}

// 6) Função que imprime todos os elementos de uma Lista Duplamente Encadeada (list)
void print_list(list<int> &lst, list<int>::iterator &it)
{
    if (it == lst.end())
    {
        return;
    }
    cout << *it << " ";
    // it++;  (É um pós-incremento, após a expressão incrementa)
    print_list(lst, ++it); //++it é um pré-incremento, antes da expressão incrementa!
}

// 7) Função que imprime todos os elementos de uma Lista Simplesmente Encadeada (forward_list), em ordem inversa
void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it)
{
    if (it == lst.end())
    {
        return;
    }
    auto current = it;
    
    print_rev(lst, ++it);
    
    cout << *current << " ";
}

// 8) Função recursiva que remove todos os elementos, um a um de um vetor
void remove_all(vector<int> &vec)
{
    if (vec.empty())
    {
        return;
    }
    vec.pop_back();
    remove_all(vec);
}

// 9) Função recursiva que imprime todos os elementos de uma Pilha (stack)
void print_stack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int topElem = stk.top();
    stk.pop();
    cout << topElem << " ";

    print_stack(stk);

}

// 10) Função que desempilha todos os elementos do stack1 e os empilha, em ordem inversa, na stack2
void push_to(stack<int> &stk, stack<int> &stk2)
{
    if (stk.empty())
    {
        return;
    }
    int topElem = stk.top();
    stk.pop();

    stk2.push(topElem);

    push_to(stk, stk2);
}

// 11) Função que copia o conteúdo de vec1 para vec2
void copyVec(vector<int> &vec1, int idx, vector<int> &vec2)
{
    if (idx < 0 || idx > vec1.size() - 1) return;
    vec2.push_back(vec1[idx]);
    copyVec(vec1, idx + 1, vec2);
}

// 12) função recursiva que copia o conteúdo de list1 para list2
void copyList(list<int> &list1, list<int>::iterator &it, list<int> &list2){
    if (it == list1.end())
    {
        return;
    }
    list2.push_back(*it);
    copyList(list1, ++it, list2);
}

int main()
{

    cout << "Ex 1:" << endl;
    char text[] = "Hello, Recursion!";
    print_txt(text);
    cout << endl;

    // 2) Teste count
    cout << "2) count:\n";
    count(3);
    cout << endl;

    // 3) Teste count_max
    cout << "3) count_max:\n";
    count_max(2, 5);
    cout << endl;

    // 4) Teste print_vec
    cout << "4) print_vec:\n";
    vector<int> vec = {1, 2, 3, 4};
    print_vec(vec);
    cout << endl;

    // 5) Teste print_even
    cout << "5) print_even:\n";
    print_even(vec, vec.size() - 1);
    cout << endl;

    // 6) Teste print_list
    cout << "6) print_list:\n";
    list<int> list1 = {5, 6, 7, 8};
    auto it = list1.begin();
    print_list(list1, it);
    cout << endl;

    // 7) Teste print_rev
    cout << "7) print_rev:\n";
    forward_list<int> flist1 = {5, 6, 7, 8};
    auto fit = flist1.begin();
    print_rev(flist1, fit);
    cout << endl;

    // 8) Teste remove_all
    cout << "8) remove_all:\n";
    vector<int> vec2 = {1, 2, 3, 4};
    remove_all(vec2);
    cout << "Tamanho final do vetor: " << vec2.size() << endl;

    // 9) Teste print_stack
    cout << "9) print_stack:\n";
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    print_stack(s);
    cout << endl;

    // 10) Teste push_to
    cout << "10) push_to:\n";
    stack<int> s1, s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    push_to(s1, s2);
    print_stack(s2);
    cout << endl;
    
    // 11) Teste copyVec
    cout << "11) copyVec:\n";
    vector <int> vec3 = {10, 11, 12};
    vector <int> vec4;
    copyVec(vec3, 0 ,vec4);
    print_vec(vec4);
    cout << endl;

    // 12) Teste copyList
    cout << "12) copyList:\n";
    list <int> list3 = {10, 11, 12};
    list <int> list4;
    auto it3 = list3.begin();
    copyList(list3, it3 ,list4);
    auto it4 = list4.begin();
    print_list(list4, it4);
    cout << endl;
}