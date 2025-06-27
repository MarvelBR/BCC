#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 1) Função que retorna a soma de todos os elementos de um vector de tamanho n que estão em posições pares
int sum(vector<int> &vec, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int somaAtual = 0;
    if ((n - 1) % 2 == 0)
    {
        somaAtual = vec[n - 1];
    }

    return somaAtual + sum(vec, n - 1);
    // Um return ((n - 1) % 2 == 0 ? vec[n - 1] : 0) + sum(vec, n - 1); Funcionario no lugar do int somaAtual até o return de agora!
}

// 2) Função que retorna o produto de todos os elementos de uma list de início em it.
int product(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
    {
        return 1;
    }
    return *it * product(lst, ++it);
}

// 3) Função recursiva que retorna o menor dos elementos de um vector de tamanho n
int minVec(vector<int> &vec, int n)
{
    if (n == 1)
        return vec[0];

    int menorRestante = minVec(vec, n - 1);
    if (vec[n - 1] < menorRestante)
    {
        return vec[n - 1];
    }
    else
    {
        return menorRestante;
    }
}

// 4) Função recursiva que retorna o menor dos elementos de uma lista de início em it
int minList(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
    {
        return *it;
    }

    int menorRestante = minList(lst, ++it);

    if (*it < menorRestante)
    {
        return *it;
    }
    else
    {
        return menorRestante;
    }
}

// 5) Função recursiva que informa se um elemento está em um vector de tamanho n.
bool find(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
    {
        return false;
    }

    if (elem == vec[n - 1])
    {
        return true;
    }

    return find(vec, n - 1, elem);
}

// 6) função recursiva que retorna a quantidade de ocorrência de um elemento em um vector de tamanho n.
int count(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
    {
        return 0;
    }

    int quant = 0;
    if (elem == vec[n - 1])
    {
        quant++;
    }
    return count(vec, n - 1, elem) + quant;
}

// 7) Função recursiva que inverte os elementos em um vector, de início em first e final em last.
void reverseVec(vector<int> &vec, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int temp = vec[first];
    vec[first] = vec[last];
    vec[last] = temp;
    reverseVec(vec, first + 1, last - 1);
}

// 8) Função recursiva que inverte os elementos em uma list, de início em first e final em last.
void reverseList(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    --last;
    if (first == last)
    {
        return;
    }

    int temp = *first;
    *first = *last;
    *last = temp;

    ++first;
    reverseList(lst, first, last);
}

// 9) Função recursiva que verifica se uma string forma um palíndromo.
bool palindromeVec(string &str, int first, int last)
{
    if (first >= last)
    {
        return true;
    }

    if (str[first] != str[last])
    {
        return false;
    }
    return palindromeVec(str, first + 1, last - 1);
}

// 10) Função recursiva que verifica se os elementos de uma list foram um palíndromo.
bool palindromeList(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    --last;
    if (first == last)
    {
        return true;
    }

    if (*first != *last)
    {
        return false;
    }
    ++first;
    return palindromeList(lst, first, last);
}

int main()
{
    vector<int> vec = {10, 20, 30, 4, 50, 20};
    list<int> lst = {1, 2, 3, 4, 5};
    list<int> lst2 = {1, 2, 3, 2, 1};
    string str = "arara";

    cout << "1) Soma posicoes pares (vec): " << sum(vec, vec.size()) << endl;
    cout << "2) Produto dos elementos (lst): " << product(lst, lst.begin()) << endl;
    cout << "3) Menor elemento (vec): " << minVec(vec, vec.size()) << endl;
    cout << "4) Menor elemento (lst): " << minList(lst, lst.begin()) << endl;
    cout << "5) Elemento 30 esta no vector? " << (find(vec, vec.size(), 30) ? "Sim" : "Nao") << endl;
    cout << "6) Ocorrencias de 20 no vector: " << count(vec, vec.size(), 20) << endl;

    // 7) Reversão de vector
    reverseVec(vec, 0, vec.size() - 1);
    cout << "7) Vector invertido: ";
    for (int x : vec)
        cout << x << " ";
    cout << endl;

    // 8) Reversão de list
    reverseList(lst, lst.begin(), lst.end());
    cout << "8) Lista invertida: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;

    // 9) Palíndromo com string
    cout << "9) 'arara' eh palindromo? " << (palindromeVec(str, 0, str.size() - 1) ? "Sim" : "Nao") << endl;

    // 10) Palíndromo com list
    cout << "10) Lista eh palindromo? " << (palindromeList(lst, lst2.begin(), lst2.end()) ? "Sim" : "Nao") << endl;

    return 0;
}