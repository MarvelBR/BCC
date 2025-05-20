#include <iostream>
#include <fstream>
#include <filesystem>  // C++17 ou superior

int main() {
    std::ofstream arquivo("../Dados/dados.bin", std::ios::binary);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return 1;
    }

    int numero = 42;
    arquivo.write(reinterpret_cast<char*>(&numero), sizeof(numero));
    arquivo.close();

    std::cout << "Arquivo escrito com sucesso!\n";
    return 0;
}