#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <filesystem>

// BubbleSort padrão (O(n²))
void bubbleSort(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j + 1 < v.size() - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

// Função para gerar vetor aleatório, salvar em arquivo binário e medir tempo de ordenação
void gerar_e_testar(int tamanho, const std::string& nome_arquivo) {
    std::vector<int> dados(tamanho);

    srand(time(0)); // Semente

    for (int& x : dados){
        x = rand() % 1000000;
    }

    // Escreve os dados originais (desordenados) no arquivo
    std::ofstream arquivo("../Dados/" + nome_arquivo, std::ios::binary);
    if (!arquivo) {
        std::cerr << "Erro ao criar arquivo dados/" << nome_arquivo << "\n";
        return;
    }

    arquivo.write(reinterpret_cast<char*>(dados.data()), sizeof(int) * dados.size());
    arquivo.close();

    std::cout << "Arquivo \"dados/" << nome_arquivo << "\" criado com " << tamanho << " elementos.\n";

    // Faz uma cópia do vetor para não alterar os dados salvos
    std::vector<int> copia = dados;

    // Mede o tempo de ordenação com BubbleSort
    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(copia);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de ordenação com BubbleSort: " << duracao.count() << " segundos.\n\n";
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
