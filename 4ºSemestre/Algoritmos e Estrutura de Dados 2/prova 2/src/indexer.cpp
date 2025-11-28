#include "../include/indexer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

Index Indexer::build_index(const std::string& directory) {
    Index idx;
    idx.base_directory = directory;

    TextProcessor tp;
    tp.load_stopwords("../data/stopwords.txt");

    int docID = 0;

    // Percorre recursivamente todos os arquivos .txt
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (!entry.is_regular_file()) continue;

        // verifica extensão .txt
        if (entry.path().extension() != ".txt") continue;

        std::string path = entry.path().string();
        idx.doc_paths.push_back(path);

        // Ler o arquivo inteiro
        std::ifstream file(path);
        if (!file) {
            std::cerr << "Erro ao abrir arquivo: " << path << "\n";
            continue;
        }

        std::string line;
        std::string fullText;

        while (std::getline(file, line)) {
            fullText += line + " ";
        }

        // Tokenizar
        auto tokens = tp.tokenize(fullText);

        // Preencher índice invertido
        for (const auto& word : tokens) {
            idx.inverted[word].insert(docID);
        }

        docID++;
    }

    std::cout << "Indexacao completa. Documentos processados: " << docID << "\n";
    return idx;
}
