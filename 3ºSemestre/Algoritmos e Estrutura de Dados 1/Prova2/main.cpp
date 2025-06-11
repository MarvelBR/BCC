#include <iostream>
#include <vector>

#include "Codigos/ordenacao.cpp"
#include "Codigos/gerador_dados.cpp"
#include "Codigos/busca.cpp"

using namespace std;

void buscar(vector<int> &dados, int chave)
{
    Busca busca(dados);

    cout << "Busca Linear: " << endl;
    int idx_linear = busca.linear_search(chave);
    if (idx_linear != -1)
    {
        cout << "Busca Linear: valor " << chave << " encontrado no índice " << idx_linear << endl;
    }
    else
    {
        std::cout << "Busca Linear: valor " << chave << " não encontrado." << endl;
    }

    cout << "\n";

    cout << "Busca Binária: " << endl;
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

void ordenar(vector<int> &dados)
{
    Ordenacao ordenacao(dados);

    cout << "Selection Sort:\n";
    ordenacao.selection_sort();

    cout << "\n";

    cout << "Selection Sort Otimizado:\n";
    ordenacao.optimized_selection_sort();

    cout << "\n";

    cout << "Bubble Sort:\n";
    ordenacao.bubble_sort();

    cout << "\n";

    cout << "Bubble Sort Otimizado:\n";
    ordenacao.optimized_bubble_sort();

    cout << "\n";

    cout << "Insertion Sort:\n";
    ordenacao.insertion_sort();
}

int main()
{
    Gerador gerador("./Dados/");
    Utilities util;
    gerador.gerar_dados();

    cout << "\nARQUIVO PEQUENO DESORDENADO\n";
    vector<int> dados = util.read_binary_file("dados/pequeno_13000_desordenado.bin", 13000);
    ordenar(dados);

    cout << "\nARQUIVO MEDIO DESORDENADO\n";
    vector<int> dados2 = util.read_binary_file("dados/medio_70000_desordenado.bin", 70000);
    ordenar(dados2);

    cout << "\nARQUIVO GRANDE DESORDENADO\n";
    vector<int> dados3 = util.read_binary_file("dados/grande_165000_desordenado.bin", 165000);
    ordenar(dados3);

    cout << "\nARQUIVO PEQUENO ORDENADO\n";
    vector<int> dados4 = util.read_binary_file("dados/pequeno_13000_ordenado.bin", 13000);
    ordenar(dados4);

    cout << "\nARQUIVO MEDIO ORDENADO\n";
    vector<int> dados5 = util.read_binary_file("dados/medio_70000_ordenado.bin", 70000);
    ordenar(dados5);

    cout << "\nARQUIVO GRANDE ORDENADO\n";
    vector<int> dados6 = util.read_binary_file("dados/grande_165000_ordenado.bin", 165000);
    ordenar(dados6);

    cout << "\nBUSCAS NO ARQUIVO PEQUENO ORDENADO\n";
    int chave = 12999;
    buscar(dados4, chave);

    cout << "\nBUSCAS NO ARQUIVO MEDIO ORDENADO\n";
    int chave2 = 69999;
    buscar(dados5, chave2);

    cout << "\nBUSCAS NO ARQUIVO GRANDE ORDENADO\n";
    int chave3 = 164999;
    buscar(dados6, chave3);
    return 0;
}