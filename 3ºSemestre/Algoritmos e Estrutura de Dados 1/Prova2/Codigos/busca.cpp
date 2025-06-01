#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

class Busca
{
private:
    vector<int> dados;
    vector<int> copia;
    int tamanho;

public:
    Busca(vector<int> &_arr)
    {
        this->dados = _arr;
        this->copia = this->dados;
        this->tamanho = this->copia.size();
    }

    int linear_search(int key)
    {
        unsigned long long int comparacoes = 0;
        auto inicio = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < this->tamanho; i++)
        {
            comparacoes++;
            if (this->copia[i] == key)
            {
                auto fim = std::chrono::high_resolution_clock::now();
                chrono::duration<double> duracao = fim - inicio;
                cout << "Tempo de busca (Linear Search):" << duracao.count() << " segundos.\n";
                cout << "Comparações: " << comparacoes << endl;
                return i; // Retorna o índice do elemento encontrado
            }
        }
        auto fim = std::chrono::high_resolution_clock::now();
        chrono::duration<double> duracao = fim - inicio;
        cout << "Tempo de busca (Linear Search):" << duracao.count() << " segundos.\n";
        cout << "Comparações: " << comparacoes << endl;
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    int binary_search(int key)
    {
        unsigned long long int comparacoes = 0;
        auto inicio = std::chrono::high_resolution_clock::now();
        int left = 0, right = this->tamanho - 1;
        while (left <= right)
        {
            comparacoes++;
            int mid = left + (right - left) / 2;
            if (this->copia[mid] == key)
            {
                auto fim = std::chrono::high_resolution_clock::now();
                chrono::duration<double> duracao = fim - inicio;
                cout << "Tempo de busca (Binary Search):" << duracao.count() << " segundos.\n";
                cout << "Comparações: " << comparacoes << endl;
                return mid; // Retorna o índice do elemento encontrado
            }
            else if (this->copia[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        auto fim = std::chrono::high_resolution_clock::now();
        chrono::duration<double> duracao = fim - inicio;
        cout << "Tempo de busca (Binary Search):" << duracao.count() << " segundos.\n";
        cout << "Comparações: " << comparacoes << endl;
        return -1; // Retorna -1 se o elemento não for encontrado
    }
};