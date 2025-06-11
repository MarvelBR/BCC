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
    int tamanho = 0;
    Utilities util;

public:
    Ordenacao(vector<int> &_arr)
    {
        this->dados = _arr;
        this->tamanho = this->dados.size();
    }

    void selection_sort()
    {
        this->util.start_timer();

        unsigned long long int comparacoes = 0, trocas = 0;
        vector<int> copia = this->dados;

        for (int i = 0; i < this->tamanho; i++)
        {
            int index_minimo = i;

            for (int j = i + 1; j < this->tamanho; j++)
            {
                comparacoes++;
                if (copia[j] < copia[index_minimo])
                    index_minimo = j;
            }

            if (index_minimo != i)
            {
                this->util.swap(&copia[index_minimo], &copia[i]);
                this->util.count_iterations(&trocas);
            }
        }

        this->util.end_timer();

        this->util.print_result(comparacoes, trocas);
    }

    void insertion_sort()
    {
        this->util.start_timer();
        vector<int> copia = this->dados;
        unsigned long long int comparacoes = 0, trocas = 0;

        for (int i = 1; i < this->tamanho; i++) // consideramos que o primeiro elemento está ordenado
        {
            int temp = copia[i];
            int j = i;
            this->util.count_iterations(&comparacoes);

            while (j > 0 && temp < copia[j - 1])
            {
                copia[j] = copia[j - 1];
                this->util.count_iterations(&trocas);
                --j;
            }

            if (j > 0)
            {
                this->util.count_iterations(&comparacoes);
            }

            copia[j] = temp;
            this->util.count_iterations(&trocas);
        }
        this->util.end_timer();

        this->util.print_result(comparacoes, trocas);
    }

    void bubble_sort()
    {
        this->util.start_timer();
        vector<int> copia = this->dados;

        unsigned long long int comparacoes = 0, trocas = 0;

        for (int i = 0; i < this->tamanho; i++)
        {
            for (int j = 0; j < this->tamanho - i - 1; j++)
            {
                this->util.count_iterations(&comparacoes);

                if (copia[j] > copia[j + 1])
                {
                    this->util.swap(&copia[j], &copia[j + 1]);
                }
                this->util.count_iterations(&trocas);
            }
        }

        this->util.end_timer();
        this->util.print_result(comparacoes, trocas);
    }

    void optimized_selection_sort()
    {
        this->util.start_timer();

        unsigned long long int comparacoes = 0, trocas = 0;
        vector<int> copia = this->dados;

        for (int i = 0; i < this->tamanho - 1; i++)
        {
            int index_minimo = i;
            bool houve_troca = false;

            for (int j = i + 1; j < this->tamanho; j++)
            {
                comparacoes++;
                if (copia[j] < copia[index_minimo])
                {
                    index_minimo = j;
                    houve_troca = true; // haverá troca se index_minimo mudar
                }
            }

            if (houve_troca)
            {
                this->util.swap(&copia[i], &copia[index_minimo]);
                this->util.count_iterations(&trocas);
            }
            else
            {
                // Nenhuma troca foi feita, o restante já está ordenado
                break;
            }
        }

        this->util.end_timer();
        this->util.print_result(comparacoes, trocas);
    }

    void optimized_bubble_sort()
    {
        unsigned long long int comparacoes = 0, trocas = 0;
        this->util.start_timer();
        vector<int> copia = this->dados;

        for (int i = 0; i < this->tamanho; i++)
        {
            bool trocado = false;
            for (int j = 0; j < this->tamanho - i - 1; j++)
            {
                this->util.count_iterations(&comparacoes);
                if (copia[j] > copia[j + 1])
                {
                    this->util.swap(&copia[j], &copia[j + 1]);
                    this->util.count_iterations(&trocas);
                    trocado = true;
                }
            }
            if (!trocado)
            {
                break;
            }
        }

        this->util.end_timer();
        this->util.print_result(comparacoes, trocas);
    }
};