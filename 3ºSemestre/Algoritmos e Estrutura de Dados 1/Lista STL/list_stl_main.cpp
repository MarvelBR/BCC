#include <iostream>
#include "list_stl.hpp"
using namespace std;

int main() {
    ListaSTL lista;

    // Teste vet_to_vector
    int v[5] = {1, 2, 3, 4, 5};
    vector<int> vec = lista.vet_to_vector(v, 5);
    cout << "vet_to_vector: ";
    for (int n : vec) cout << n << " ";
    cout << endl;

    // Teste vet_to_list
    list<int> lst = lista.vet_to_list(v, 5);
    cout << "vet_to_list: ";
    for (int n : lst) cout << n << " ";
    cout << endl;

    // Teste vet_to_stack
    stack<int> stk = lista.vet_to_stack(v, 5);
    cout << "vet_to_stack (top to bottom): ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    // Teste list_concat
    list<int> l1 = lista.vet_to_list(v, 3); // 1 2 3
    list<int> l2 = lista.vet_to_list(v+3, 2); // 4 5
    vector<int> concat = lista.list_concat(l1, l2);
    cout << "list_concat: ";
    for (int n : concat) cout << n << " ";
    cout << endl;

    // Teste check_brackets
    string expr1 = "(1+2)*(3+4)";
    string expr2 = "(1+2*(3+4)";
    cout << "check_brackets (expr1): " << lista.check_brackets(expr1) << endl;
    cout << "check_brackets (expr2): " << lista.check_brackets(expr2) << endl;

    // Teste vectorize_expression
    string expr3 = "12+34*5";
    vector<string> tokens = lista.vectorize_expression(expr3);
    cout << "vectorize_expression: ";
    for (auto &s : tokens) cout << s << " ";
    cout << endl;

    // Teste calc_posfix
    string posfix = "2 3 + 4 *"; // (2+3)*4 = 20
    cout << "calc_posfix: " << lista.calc_posfix(posfix) << endl;

    // Teste check_posfix
    cout << "check_posfix (valido): " << lista.check_posfix("2 3 + 4 *") << endl;
    cout << "check_posfix (invalido): " << lista.check_posfix("2 + 3") << endl;

    // Teste calc_infix (simples, sem precedência)
    cout << "calc_infix (1+2*3): " << lista.calc_infix("1+2*3") << endl;

    // Teste print_vector
    cout << "print_vector: ";
    lista.print_vector(tokens);

    // Teste posfix_to_infix
    string posfix2 = "2 3 4 * +"; // 2 + (3*4)
    cout << "posfix_to_infix: " << lista.posfix_to_infix(posfix2) << endl;

    return 0;
}