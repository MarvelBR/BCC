#include <iostream>
#include <vector>

#include "Codigos/ordenacao.cpp"
#include "Codigos/gerador_dados.cpp"
#include "Codigos/busca.cpp"

void gerar_dados()
{
    Gerador pequeno("Dados/pequeno", 13000);
    Gerador medio("Dados/medio", 70000);
    Gerador grande("Dados/grande", 165000);

    pequeno.create_unordered_file();
    medio.create_unordered_file();
    grande.create_unordered_file();

    pequeno.create_ordered_file();
    medio.create_ordered_file();
    grande.create_ordered_file();
}

void buscar(std::vector<int> &dados, int chave)
{
    Busca busca(dados);

    int idx_linear = busca.linear_search(chave);
    if (idx_linear != -1){
        std::cout << "Busca Linear: valor " << chave << " encontrado no índice " << idx_linear << std::endl;
    } else {
        std::cout << "Busca Linear: valor " << chave << " não encontrado." << std::endl;
    }
        
    cout << "\n";

    int idx_binaria = busca.binary_search(chave);
    if (idx_binaria != -1){
        std::cout << "Busca Binária: valor " << chave << " encontrado no índice " << idx_binaria << std::endl;
    } else {
        std::cout << "Busca Binária: valor " << chave << " não encontrado." << std::endl;
    }
}

void ordenar(std::vector<int> &dados)
{
    Ordenacao ordenacao(dados);

    std::cout << "Selection Sort:\n";
    ordenacao.selection_sort();

    std::cout << "\n";

    ordenacao.reset();
    std::cout << "Bubble Sort:\n";
    ordenacao.bubble_sort();

    std::cout << "\n";

    ordenacao.reset();
    std::cout << "Bubble Sort Otimizado:\n";
    ordenacao.optimized_bubble_sort();

    std::cout << "\n";

    ordenacao.reset();
    std::cout << "Insertion Sort:\n";
    ordenacao.insertion_sort();
}

int main()
{
    gerar_dados();

    Utilities util;

    std::cout << "\nARQUIVO PEQUENO DESORDENADO\n";
    std::vector<int> dados = util.read_binary_file("Dados/pequeno_13000_desordenado.bin", 13000);
    //ordenar(dados);

    std::cout << "\nARQUIVO MEDIO DESORDENADO\n";
    std::vector<int> dados2 = util.read_binary_file("Dados/medio_70000_desordenado.bin", 70000);
    //ordenar(dados2);

    std::cout << "\nARQUIVO GRANDE DESORDENADO\n";
    std::vector<int> dados3 = util.read_binary_file("Dados/grande_165000_desordenado.bin", 165000);
    //ordenar(dados3);

    std::cout << "\nARQUIVO PEQUENO ORDENADO\n";
    std::vector<int> dados4 = util.read_binary_file("Dados/pequeno_13000_ordenado.bin", 13000);
    //ordenar(dados4);

    std::cout << "\nARQUIVO MEDIO ORDENADO\n";
    std::vector<int> dados5 = util.read_binary_file("Dados/medio_70000_ordenado.bin", 70000);
    //ordenar(dados5);

    std::cout << "\nARQUIVO GRANDE ORDENADO\n";
    std::vector<int> dados6 = util.read_binary_file("Dados/grande_165000_ordenado.bin", 165000);
    //ordenar(dados6);

    std::cout << "\nBUSCAS NO ARQUIVO PEQUENO ORDENADO\n";
    int chave = 1234; // valor para buscar
    buscar(dados4, chave);

    std::cout << "\nBUSCAS NO ARQUIVO MEDIO ORDENADO\n";
    buscar(dados5, chave);

    std::cout << "\nBUSCAS NO ARQUIVO GRANDE ORDENADO\n";
    buscar(dados6, chave);

    return 0;
}