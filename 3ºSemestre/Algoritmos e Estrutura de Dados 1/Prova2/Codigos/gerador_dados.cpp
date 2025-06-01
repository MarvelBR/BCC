#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

class Gerador
{
private:
    int size = 0;
    string path;

public:
    Gerador(string _path, int file_size)
    {
        this->size = file_size;
        this->path = _path;
    }

    void create_ordered_file()
    {
        fstream file;
        file.open(this->path + "_" + to_string(this->size) + "_ordenado.bin", ios::binary | ios::out);

        for (int i = 0; i < this->size; i++)
        {
            file.write(reinterpret_cast<char *>(&i), sizeof(int));
        }

        file.close();
    }

    void create_unordered_file()
    {
        vector<int> dados(this->size);
        fstream file;

        srand(time(0));

        for (int &dado : dados)
        {
            dado = rand() % 1000000;
        }

        file.open(this->path + "_" + to_string(this->size) + "_desordenado.bin", ios::binary | ios::out);
        file.write(reinterpret_cast<char *>(dados.data()), sizeof(int) * dados.size());
        file.close();
    }
};

