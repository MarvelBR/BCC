#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Timer
{
public:
    Timer()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        stop();
    }

    void stop()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Duração: " << duration.count() << " segundos\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

class Utilities
{
public:
    Utilities() {}

    void count_duration()
    {
        Timer timer;
    }

    void count_iterations(int *iterations)
    {
        (*iterations)++;
    }

    void swap(int *elem_A, int *elem_B)
    {
        int temp = *elem_A;
        *elem_A = *elem_B;
        *elem_B = temp;
    }

    vector<int> read_binary_file(string path, int size)
    {
        vector<int> dados(size);
        ifstream file(path, std::ios::binary | std::ios::in);

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