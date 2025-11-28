#include <iostream>
#include <vector>
#include <string>
#include "../include/indexer.h"
#include "../include/serializer.h"
#include "../include/queryprocessor.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Uso: indice construir <dir>  OR  indice buscar <termo1> [termo2 ...]\n";
        return 1;
    }

    std::string cmd = argv[1];
    if (cmd == "construir") {
        if (argc < 3) {
            std::cerr << "Uso: indice construir <caminho_do_diretorio>\n";
            return 1;
        }
        std::string dir = argv[2];
        Indexer indexer;
        auto idx = indexer.build_index(dir); // retorna um Index
        Serializer ser;
        if (!ser.save("index.dat", idx)) {
            std::cerr << "Erro ao salvar index.dat\n";
            return 1;
        }
        std::cout << "Indexacao concluida. index.dat salvo.\n";
    } else if (cmd == "buscar") {
        if (argc < 3) {
            std::cerr << "Uso: indice buscar <termo1> [termo2 ...]\n";
            return 1;
        }
        std::vector<std::string> termos;
        for (int i = 2; i < argc; ++i) termos.emplace_back(argv[i]);
        Serializer ser;
        Index idx;
        if (!ser.load("index.dat", idx)) {
            std::cerr << "index.dat nao encontrado. Execute construir primeiro.\n";
            return 1;
        }
        QueryProcessor qp(idx);
        auto results = qp.search(termos);
        if (results.empty()) {
            std::cout << "Nenhum documento encontrado.\n";
        } else {
            for (const auto& path : results) std::cout << path << "\n";
        }
    } else {
        std::cerr << "Comando desconhecido: " << cmd << "\n";
        return 1;
    }
    return 0;
}
