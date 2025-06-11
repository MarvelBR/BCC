#include <chrono>
#include <iostream>

using namespace std;

class Utilities
{
private:
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

public:
    Utilities() {}

    void count_iterations(unsigned long long int *iterations)
    {
        (*iterations)++;
    }

    void start_timer()
    {
        this->start = chrono::high_resolution_clock::now();
    }

    void end_timer()
    {
        this->end = chrono::high_resolution_clock::now();

        this->end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = this->end - this->start;
        cout << "Tempo de duracao: " << duration.count() << " segundos" << endl;
    }

    void print_result(unsigned long long int comparacoes, unsigned long long int trocas)
    {
        cout << "Comparações: " << comparacoes << " | Trocas: " << trocas << endl;
    };

    void swap(int *elem_A, int *elem_B)
    {
        int temp = *elem_A;
        *elem_A = *elem_B;
        *elem_B = temp;
    }

    vector<int> read_binary_file(string path, int size)
    {
        vector<int> dados(size);
        ifstream file(path, ios::binary | ios::in);

        if (!file.is_open())
        {
            cout << "Erro ao abrir o arquivo binário para leitura." << endl;
            return {};
        }

        file.read(reinterpret_cast<char *>(dados.data()), sizeof(int) * size);
        file.close();

        return dados;
    }
};