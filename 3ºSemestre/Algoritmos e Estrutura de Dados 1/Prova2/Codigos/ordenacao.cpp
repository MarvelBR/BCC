#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <random>
#include "utilities.cpp"

using namespace std;

class Ordenacao
{
private:
    vector<int> dados;
    vector<int> copia;
    int tamanho = 0;
    Utilities util;

public:
    Ordenacao(vector<int> &_arr)
    {
        this->dados = _arr;
        this->copia = this->dados;
        this->tamanho = this->copia.size();
    }

    void selection_sort()
    {
        unsigned long long int comparacoes = 0, trocas = 0;
        auto inicio = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < this->tamanho; i++)
        {
            int index_minimo = i;

            for (int j = i + 1; j < this->tamanho; j++)
            {
                comparacoes++;
                if (this->copia[j] < this->copia[index_minimo])
                    index_minimo = j;
            }

            if (index_minimo != i)
            {
                this->util.swap(&this->copia[index_minimo], &this->copia[i]);
                trocas++;
            }
        }
        // this->printArray(copia);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;
        std::cout << "Tempo de ordenação (Selection Sort): " << duracao.count() << " segundos.\n";
        std::cout << "Comparações: " << comparacoes << " | Trocas: " << trocas << std::endl;
    }

    void insertion_sort()
    {
        // Utilities util;
        // util.count_duration();
        unsigned long long int comparacoes = 0, trocas = 0;
        auto inicio = std::chrono::high_resolution_clock::now();

        for (int i = 1; i < this->tamanho; i++) // consideramos que o primeiro elemento está ordenado
        {
            int temp = this->copia[i];
            int j = i;
            comparacoes++;

            while (j > 0 && temp < this->copia[j - 1])
            {
                this->copia[j] = this->copia[j - 1];
                trocas++;
                --j;
            }

            if (j > 0)
            {
                comparacoes++;
            }

            this->copia[j] = temp;
            trocas++;
        }

        // this->printArray(copia);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;
        std::cout << "Tempo de ordenação (Insertion Sort): " << duracao.count() << " segundos.\n";
        std::cout << "Comparações: " << comparacoes << " | Trocas: " << trocas << std::endl;
    }

    void bubble_sort()
    {
        // Utilities util;
        // util.count_duration();
        // int *iteracoes = new int(0);
        unsigned long long int comparacoes = 0, trocas = 0;
        auto inicio = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < this->tamanho; i++)
        {
            for (int j = 0; j < this->tamanho - i - 1; j++)
            {
                comparacoes++;
                if (this->copia[j] > this->copia[j + 1])
                {
                    this->util.swap(&this->copia[j], &this->copia[j + 1]);
                    trocas++;
                }
                // util.count_iterations(iteracoes);
            }
        }

        // cout << "Número de iterações: " << *iteracoes << endl;
        // this->printArray(copia);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;
        std::cout << "Tempo de ordenação (Bubble Sort): " << duracao.count() << " segundos.\n";
        std::cout << "Comparações: " << comparacoes << " | Trocas: " << trocas << std::endl;
    }

    void printArray(vector<int> vec)
    {
        for (int elem : vec)
        {
            cout << elem << "";
        }
        cout << endl;
    }

    void optimized_bubble_sort()
    {
        unsigned long long int comparacoes = 0, trocas = 0;
        auto inicio = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < this->tamanho; i++)
        {
            bool trocado = false;
            for (int j = 0; j < this->tamanho - i - 1; j++)
            {
                comparacoes++;
                if (this->copia[j] > this->copia[j + 1])
                {
                    this->util.swap(&this->copia[j], &this->copia[j + 1]);
                    trocas++;
                    trocado = true;
                }
            }
            if (!trocado)
            {
                break;
            }
        }

        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;
        std::cout << "Tempo de ordenação (Bubble Sort Otimizado): " << duracao.count() << " segundos.\n";
        std::cout << "Comparações: " << comparacoes << " | Trocas: " << trocas << std::endl;
    }

    void reset()
    {
        this->copia = this->dados;
    }
};