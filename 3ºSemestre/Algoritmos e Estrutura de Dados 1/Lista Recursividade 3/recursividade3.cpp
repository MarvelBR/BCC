#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 1. Exponenciação (Potência)
double potencia(double base, int expoente)
{
    if (expoente == 0)
        return 1;
    if (expoente < 0)
        return 1 / potencia(base, -expoente);
    if (expoente % 2 == 0)
    {
        double temp = potencia(base, expoente / 2);
        return temp * temp;
    }
    else
    {
        return base * potencia(base, expoente - 1);
    }
}

// 2. Máximo Divisor Comum (MDC - Algoritmo de Euclides)
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

// 3. Permutações de uma String
void permute(string& s, int n){
    if (n == 0) return;
    cout << s << endl;
    char temp = s[n - 1];
    s[n - 1] = s[0];
    s[0] = temp;
    return permute(s, n - 1);
}

void string_permutation(string str, int n){
    if (n >= str.size()) 
    {
        return;
    }
    permute(str, str.size() - 1);
    return string_permutation(str, n + 1);
}

// 4. Subconjuntos (Backtracking)
void subconjuntos(const vector<int> &conjunto, vector<int> &subset, int index)
{
    if (index == conjunto.size())
    {
        cout << "{ ";
        for (int num : subset)
            cout << num << " ";
        cout << "}" << endl;
        return;
    }

    // Não inclui o elemento atual
    subconjuntos(conjunto, subset, index + 1);

    // Inclui o elemento atual
    subset.push_back(conjunto[index]);
    subconjuntos(conjunto, subset, index + 1);
    subset.pop_back();
}

// 5. Busca Binária
int buscaBinaria(const vector<int> &arr, int target, int left, int right)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return buscaBinaria(arr, target, left, mid - 1);
    return buscaBinaria(arr, target, mid + 1, right);
}

// 6. Problema das N-Rainhas
bool isSafe(const vector<string> &board, int row, int col, int n)
{
    // Verifica a coluna (recursivamente)
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Verifica diagonal superior esquerda (recursivamente)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Verifica diagonal superior direita (recursivamente)
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solveNQueens(vector<string> &board, int row, int n)
{
    if (row == n)
    {
        for (const string &line : board)
        {
            cout << line << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            // Atribuição direta sem swap
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

// 7. Soma dos Dígitos de um Número
int somaDigitos(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + somaDigitos(n / 10);
}

// 8. Inversão de uma String
void inverteString(string& str, int left, int right) {
    if (left >= right) return;
    
    // Troca manual dos caracteres
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    
    inverteString(str, left + 1, right - 1);
}


// 9. Combinações (n escolhe k)
int combinacoes(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return combinacoes(n - 1, k) + combinacoes(n - 1, k - 1);
}

// 10. Palíndromo
bool ehPalindromo(const string &str, int left, int right)
{
    if (left >= right)
        return true;
    if (str[left] != str[right])
        return false;
    return ehPalindromo(str, left + 1, right - 1);
}

int main()
{
    cout << "1. Exponenciacao (2^5): " << potencia(2, 5) << endl;
    cout << "2. MDC de 48 e 18: " << mdc(48, 18) << endl;

    cout << "3. Permutacoes de 'abc':" << endl;
    string str = "abc";
    string_permutation(str, 0);

    cout << "4. Subconjuntos de {1, 2, 3}:" << endl;
    vector<int> conjunto = {1, 2, 3};
    vector<int> subset;
    subconjuntos(conjunto, subset, 0);

    vector<int> arr = {1, 3, 5, 7, 9};
    cout << "5. Busca binaria por 7: indice " << buscaBinaria(arr, 7, 0, arr.size() - 1) << endl;

    cout << "6. Solucoes para 4-Rainhas:" << endl;
    int n = 4;
    vector<string> board(n, string(n, '.'));
    solveNQueens(board, 0, n);

    cout << "7. Soma dos digitos de 12345: " << somaDigitos(12345) << endl;

    string texto = "recursao";
    inverteString(texto, 0, texto.size() - 1);
    cout << "8. Inversao de 'recursao': " << texto << endl;

    cout << "9. Combinacoes C(5, 2): " << combinacoes(5, 2) << endl;

    string palindromo = "arara";
    cout << "10. 'arara' eh palindromo? " << (ehPalindromo(palindromo, 0, palindromo.size() - 1) ? "Sim" : "Nao") << endl;

    return 0;
}