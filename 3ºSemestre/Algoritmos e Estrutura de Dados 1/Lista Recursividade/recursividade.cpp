#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 1) Função que imprime 10 vezes a mesma linha de texto
void print_txt(char* text, int num = 10) {
    if (num <= 0) return;
    cout << text << endl;
    print_txt(text, num - 1);
}

// 2) Função que imprime contagem de 0 à 50, num vezes
void count(int num) {
    if (num <= 0) return;
    
    // Função auxiliar para contar de 0 a 50
    static void (*countTo50)(int) = [](int n) {
        if (n > 50) return;
        cout << n << " ";
        countTo50(n + 1);
    };
    
    countTo50(0);
    cout << endl;
    count(num - 1);
}

// 3) Função que imprime contagem de 0 à max, num vezes
void count_max(int num, int max) {
    if (num <= 0) return;
    
    // Função auxiliar para contar de 0 a max
    static void (*countToMax)(int, int) = [](int n, int m) {
        if (n > m) return;
        cout << n << " ";
        countToMax(n + 1, m);
    };
    
    countToMax(0, max);
    cout << endl;
    count_max(num - 1, max);
}

// 4) Função que imprime todos os elementos de um vector
void print_vec(vector<int>& vec, int idx = 0) {
    if (idx >= vec.size()) return;
    cout << vec[idx] << " ";
    print_vec(vec, idx + 1);
}

// 5) Função que imprime elementos pares de um vector em ordem inversa
void print_even(vector<int>& vec, int idx = 0) {
    if (idx >= vec.size()) return;
    print_even(vec, idx + 1);
    if (vec[idx] % 2 == 0) {
        cout << vec[idx] << " ";
    }
}

// 6) Função que imprime todos os elementos de uma list
void print_list(list<int> &lst, list<int>::iterator it) {
    if (it == lst.end()) return;
    cout << *it << " ";
    print_list(lst, ++it);
}

// 7) Função que imprime elementos de uma forward_list em ordem inversa
void print_rev(forward_list<int> &lst, forward_list<int>::iterator it) {
    if (it == lst.end()) return;
    auto next_it = it;
    ++next_it;
    print_rev(lst, next_it);
    cout << *it << " ";
}

// 8) Função que remove todos os elementos de um vector
void remove_all(vector<int> &vec) {
    if (vec.empty()) return;
    vec.pop_back();
    remove_all(vec);
}

// 9) Função que imprime todos os elementos de uma stack
void print_stack(stack<int> &stk) {
    if (stk.empty()) return;
    int top = stk.top();
    cout << top << " ";
    stk.pop();
    print_stack(stk);
    stk.push(top);
}

// 10) Função que transfere elementos de stack1 para stack2 em ordem inversa
void push_to(stack<int> &stk1, stack<int> &stk2) {
    if (stk1.empty()) return;
    int top = stk1.top();
    stk1.pop();
    stk2.push(top);
    push_to(stk1, stk2);
}

// 11) Função que copia conteúdo de vec1 para vec2
void copy(vector<int> &vec1, int idx, vector<int> &vec2) {
    if (idx >= vec1.size()) return;
    vec2.push_back(vec1[idx]);
    copy(vec1, idx + 1, vec2);
}

// 12) Função que copia conteúdo de list1 para list2
void copy(list<int> &list1, list<int>::iterator it, list<int> &list2) {
    if (it == list1.end()) return;
    list2.push_back(*it);
    copy(list1, ++it, list2);
}

int main() {
    // Teste das funções
    
    // 1) Teste print_txt
    cout << "1) print_txt:\n";
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
    vector<int> vec = {1, 2, 3, 4, 5};
    print_vec(vec);
    cout << endl << endl;
    
    // 5) Teste print_even
    cout << "5) print_even:\n";
    vector<int> vec_even = {1, 2, 3, 4, 5, 6, 7, 8};
    print_even(vec_even);
    cout << endl << endl;
    
    // 6) Teste print_list
    cout << "6) print_list:\n";
    list<int> lst = {10, 20, 30, 40, 50};
    auto it = lst.begin();
    print_list(lst, it);
    cout << endl << endl;
    
    // 7) Teste print_rev
    cout << "7) print_rev:\n";
    forward_list<int> flst = {100, 200, 300, 400};
    auto fit = flst.begin();
    print_rev(flst, fit);
    cout << endl << endl;
    
    // 8) Teste remove_all
    cout << "8) remove_all:\n";
    vector<int> vec_to_remove = {1, 2, 3};
    cout << "Antes: Tamanho = " << vec_to_remove.size() << endl;
    remove_all(vec_to_remove);
    cout << "Depois: Tamanho = " << vec_to_remove.size() << endl << endl;
    
    // 9) Teste print_stack
    cout << "9) print_stack:\n";
    stack<int> stk;
    for (int i = 1; i <= 5; i++) stk.push(i);
    print_stack(stk);
    cout << endl << endl;
    
    // 10) Teste push_to
    cout << "10) push_to:\n";
    stack<int> stk1, stk2;
    for (int i = 1; i <= 5; i++) stk1.push(i);
    cout << "Antes: stk1 size = " << stk1.size() << ", stk2 size = " << stk2.size() << endl;
    push_to(stk1, stk2);
    cout << "Depois: stk1 size = " << stk1.size() << ", stk2 size = " << stk2.size() << endl;
    cout << "Conteúdo de stk2: ";
    print_stack(stk2);
    cout << endl << endl;
    
    // 11) Teste copy (vector)
    cout << "11) copy (vector):\n";
    vector<int> vec1 = {5, 10, 15}, vec2;
    copy(vec1, 0, vec2);
    cout << "vec2: ";
    print_vec(vec2);
    cout << endl << endl;
    
    // 12) Teste copy (list)
    cout << "12) copy (list):\n";
    list<int> list1 = {50, 100, 150}, list2;
    auto lit = list1.begin();
    copy(list1, lit, list2);
    cout << "list2: ";
    auto lit2 = list2.begin();
    print_list(list2, lit2);
    cout << endl;
    
    return 0;
}