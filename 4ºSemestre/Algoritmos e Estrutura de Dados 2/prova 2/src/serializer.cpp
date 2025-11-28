#include "../include/serializer.h"
#include <fstream>
#include <iostream>

// Função auxiliar: salva string: [int tamanho][bytes]
static void write_string(std::ofstream& out, const std::string& s) {
    int len = (int)s.size();
    out.write((char*)&len, sizeof(len));
    out.write(s.data(), len);
}

// Função auxiliar: lê string
static std::string read_string(std::ifstream& in) {
    int len = 0;
    in.read((char*)&len, sizeof(len));
    std::string s(len, '\0');
    in.read(&s[0], len);
    return s;
}

// Salvar índice completo em binário
bool Serializer::save(const std::string& filename, const Index& idx) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) return false;

    // 1) Salvar diretório base
    write_string(out, idx.base_directory);

    // 2) Salvar doc_paths
    int n_docs = (int)idx.doc_paths.size();
    out.write((char*)&n_docs, sizeof(n_docs));

    for (const auto& path : idx.doc_paths) {
        write_string(out, path);
    }

    // 3) Salvar índice invertido
    int n_words = (int)idx.inverted.size();
    out.write((char*)&n_words, sizeof(n_words));

    for (const auto& [word, docSet] : idx.inverted) {
        write_string(out, word);

        int qtd = (int)docSet.size();
        out.write((char*)&qtd, sizeof(qtd));

        for (int docID : docSet) {
            out.write((char*)&docID, sizeof(docID));
        }
    }

    return true;
}

// Carregar índice completo do binário
bool Serializer::load(const std::string& filename, Index& idx) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return false;

    // 1) Ler diretório base
    idx.base_directory = read_string(in);

    // 2) Ler doc_paths
    int n_docs = 0;
    in.read((char*)&n_docs, sizeof(n_docs));
    idx.doc_paths.resize(n_docs);

    for (int i = 0; i < n_docs; i++) {
        idx.doc_paths[i] = read_string(in);
    }

    // 3) Ler índice invertido
    idx.inverted.clear();
    int n_words = 0;
    in.read((char*)&n_words, sizeof(n_words));

    for (int i = 0; i < n_words; i++) {
        std::string word = read_string(in);

        int qtd = 0;
        in.read((char*)&qtd, sizeof(qtd));

        std::set<int> docSet;
        for (int j = 0; j < qtd; j++) {
            int docID = 0;
            in.read((char*)&docID, sizeof(docID));
            docSet.insert(docID);
        }

        idx.inverted[word] = std::move(docSet);
    }

    return true;
}
