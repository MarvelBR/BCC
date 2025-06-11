#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

class Busca
{
private:
    vector<int> dados;
    int tamanho;
    Utilities util;

public:
    Busca(vector<int> &_arr)
    {
        this->dados = _arr;
        this->tamanho = this->dados.size();
    }

    int linear_search(int key)
    {
        this->util.start_timer();
        unsigned long long int comparacoes = 0;
        vector<int> copia = this->dados;

        for (int i = 0; i < this->tamanho; i++)
        {
            this->util.count_iterations(&comparacoes);

            if (copia[i] == key)
            {
                this->util.end_timer();

                cout << "Comparações: " << comparacoes << endl;
                return i; // Retorna o índice do elemento encontrado
            }
        }
        this->util.end_timer();
        cout << "Comparações: " << comparacoes << endl;
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    int binary_search(int key)
    {
        this->util.start_timer();
        unsigned long long int comparacoes = 0;
        vector<int> copia = this->dados;

        int left = 0, right = this->tamanho - 1;
        while (left <= right)
        {
            this->util.count_iterations(&comparacoes);
            int mid = left + (right - left) / 2;

            if (copia[mid] == key)
            {
                this->util.end_timer();
                cout << "Comparações: " << comparacoes << endl;
                return mid; // Retorna o índice do elemento encontrado
            }
            else if (copia[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        this->util.end_timer();
        cout << "Comparações: " << comparacoes << endl;
        return -1; // Retorna -1 se o elemento não for encontrado
    }

    void buscar(vector<int> &dados, int chave)
    {
        Busca busca(dados);

        cout << "Busca Linear" << endl;
        int idx_linear = busca.linear_search(chave);
        if (idx_linear != -1)
        {
            cout << "Busca Linear: valor " << chave << " encontrado no índice " << idx_linear << endl;
        }
        else
        {
            cout << "Busca Linear: valor " << chave << " não encontrado." << endl;
        }

        cout << "\n";

        cout << "Busca Binária" << std::endl;
        int idx_binaria = busca.binary_search(chave);
        if (idx_binaria != -1)
        {
            cout << "Busca Binária: valor " << chave << " encontrado no índice " << idx_binaria << endl;
        }
        else
        {
            cout << "Busca Binária: valor " << chave << " não encontrado." << endl;
        }
    }
};