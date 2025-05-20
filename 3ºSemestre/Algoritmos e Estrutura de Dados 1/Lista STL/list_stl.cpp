#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include "list_stl.hpp"
using namespace std;

// ...existing code...

ListaSTL::ListaSTL() {}

vector<int> ListaSTL::vet_to_vector(int *v, int n) {
    vector<int> vec(v, v + n);
    return vec;
}

list<int> ListaSTL::vet_to_list(int *v, int n) {
    list<int> lst(v, v + n);
    return lst;
}

stack<int> ListaSTL::vet_to_stack(int *v, int n) {
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        stk.push(v[i]);
    }
    return stk;
}

vector<int> ListaSTL::list_concat(list<int> &list1, list<int> &list2) {
    vector<int> result(list1.begin(), list1.end());
    result.insert(result.end(), list2.begin(), list2.end());
    return result;
}

bool ListaSTL::check_brackets(string expression) {
    stack<char> stk;
    for (char c : expression) {
        if (c == '(') stk.push(c);
        else if (c == ')') {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

// ...existing code...

vector<string> ListaSTL::vectorize_expression(string expression) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            continue;
        }
        if (c >= '0' && c <= '9') {
            token += c;
        } else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            string op(1, c);
            tokens.push_back(op);
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}

float ListaSTL::calc_posfix(string expression) {
    stack<float> stk;
    vector<string> tokens = vectorize_expression(expression);
    for (size_t i = 0; i < tokens.size(); ++i) {
        string token = tokens[i];
        if (token[0] >= '0' && token[0] <= '9') {
            stk.push(static_cast<float>(atoi(token.c_str())));
        } else {
            // Checa se há pelo menos dois operandos na pilha
            if (stk.size() < 2) {
                cout << "Expressao posfixa invalida!" << endl;
                return 0;
            }
            float b = stk.top(); stk.pop();
            float a = stk.top(); stk.pop();
            if (token == "+") stk.push(a + b);
            else if (token == "-") stk.push(a - b);
            else if (token == "*") stk.push(a * b);
            else if (token == "/") stk.push(a / b);
        }
    }
    // Checa se sobrou exatamente um resultado na pilha
    if (stk.size() != 1) {
        cout << "Expressao posfixa invalida!" << endl;
        return 0;
    }
    return stk.top();
}

bool ListaSTL::check_posfix(string expression) {
    int count = 0;
    vector<string> tokens = vectorize_expression(expression);
    for (size_t i = 0; i < tokens.size(); ++i) {
        string token = tokens[i];
        if (token[0] >= '0' && token[0] <= '9') count++;
        else count--;
        if (count < 1) return false;
    }
    return count == 1;
}

float ListaSTL::calc_infix(string expression) {
    stack<float> nums;
    stack<char> ops;
    vector<string> tokens = vectorize_expression(expression);
    for (size_t i = 0; i < tokens.size(); ++i) {
        string token = tokens[i];
        if (token[0] >= '0' && token[0] <= '9') {
            nums.push(static_cast<float>(atoi(token.c_str())));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            ops.push(token[0]);
        }
    }
    while (!ops.empty()) {
        float b = nums.top(); nums.pop();
        float a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if (op == '+') nums.push(a + b);
        else if (op == '-') nums.push(a - b);
        else if (op == '*') nums.push(a * b);
        else if (op == '/') nums.push(a / b);
    }
    return nums.top();
}

void ListaSTL::print_vector(const vector<string> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

string ListaSTL::posfix_to_infix(string expression) {
    stack<string> stk;
    vector<string> tokens = vectorize_expression(expression);
    for (size_t i = 0; i < tokens.size(); ++i) {
        string token = tokens[i];
        if (token[0] >= '0' && token[0] <= '9') stk.push(token);
        else {
            string b = stk.top(); stk.pop();
            string a = stk.top(); stk.pop();
            string expr = "(" + a + " " + token + " " + b + ")";
            stk.push(expr);
        }
    }
    return stk.top();
}