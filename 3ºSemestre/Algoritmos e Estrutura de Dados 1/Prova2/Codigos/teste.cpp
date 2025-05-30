#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <filesystem>

using namespace std;

/* BubbleSort padrão (O(n²))
void bubbleSort(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j + 1 < v.size() - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}
*/
void gerar_e_testar(int tamanho, const std::string& nome_arquivo) {
    std::vector<int> dados(tamanho);

    srand(time(0)); // sequência diferente a cada execução


    for (int& x : dados){
        x = rand() % 1000000; // Gera números aleatórios entre 0 e 999999
    }

    std::ofstream arquivo;
    std::string caminho = "../Dados/" + nome_arquivo;

    arquivo.open(caminho, std::ios::binary);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir " << caminho << "\n";
        return;
    }

    if (!arquivo) {
        std::cerr << "Erro ao criar arquivo dados/" << nome_arquivo << "\n";
        return;
    }

    arquivo.write(reinterpret_cast<char*>(dados.data()), sizeof(int) * dados.size()); 

    /*
    Essa linha grava os dados no arquivo binário. Vamos por partes:
    dados:
    Provavelmente é um std::vector<int> contendo os dados que você quer salvar.

    dados.data():
    Retorna um ponteiro para o primeiro elemento do vetor (tipo int*).

    reinterpret_cast<char*>(...):
    Converte o ponteiro int* para char*.
    Isso é necessário porque std::ofstream::write exige um ponteiro para char (bytes crus).
    O reinterpret_cast permite conversões de ponteiros entre tipos não relacionados — é uma forma "perigosa", mas válida nesse contexto.

    sizeof(int) * dados.size():
    Calcula o número total de bytes a serem escritos (número de elementos × tamanho de cada int).
    */

    arquivo.close();

    std::cout << "Arquivo \"Dados/" << nome_arquivo << "\" criado com " << tamanho << " elementos.\n";

    /* Não vai ficar aqui!
     Faz uma cópia do vetor para não alterar os dados salvos
    std::vector<int> copia = dados;

    Mede o tempo de ordenação com BubbleSort
    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(copia);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de ordenação com BubbleSort: " << duracao.count() << " segundos.\n\n";
    */
}

int main() {
    // Estime os tamanhos com base em testes anteriores
    int pequeno = 10000;     // Alvo: ~1 segundo
    int medio   = 50000;     // Alvo: ~30 segundos
    int grande  = 120000;     // Alvo: ~180 segundos

    gerar_e_testar(pequeno, "pequeno.bin");
    gerar_e_testar(medio,   "medio.bin");
    gerar_e_testar(grande,  "grande.bin");

    return 0;
}
