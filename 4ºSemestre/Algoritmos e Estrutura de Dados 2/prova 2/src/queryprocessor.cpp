#include "../include/queryprocessor.h"
#include <algorithm>
#include <iterator>
#include <iostream>

QueryProcessor::QueryProcessor(const Index& idx)
    : index(idx)
{
    // Tenta carregar stopwords do local padrão (relativo ao diretório do projeto)
    // Se falhar, a tokenização ainda funciona, só sem remoção de stopwords.
    if (!tp.load_stopwords("./data/stopwords.txt")) {
        // não é fatal — apenas informe
        std::cerr << "Aviso: nao foi possivel carregar stopwords (./data/stopwords.txt).\n";
    }
}

std::vector<std::string> QueryProcessor::search(const std::vector<std::string>& terms) {
    // 1) normalizar os termos da consulta (usando o TextProcessor)
    std::vector<std::string> normalized;
    for (const auto& t : terms) {
        // tokenize retorna 0..N tokens (p.ex. se usuário passou "ação" vira "acao")
        auto toks = tp.tokenize(t);
        for (auto &w : toks) {
            normalized.push_back(w);
        }
    }

    if (normalized.empty()) {
        // nada para procurar (possivelmente todos os termos eram stopwords)
        return {};
    }

    // 2) para cada termo, obter o conjunto de docIDs
    std::vector<std::set<int>> sets;
    sets.reserve(normalized.size());

    for (const auto& term : normalized) {
        auto it = index.inverted.find(term);
        if (it == index.inverted.end()) {
            // termo não existe → interseção será vazia
            return {};
        }
        sets.push_back(it->second);
    }

    // 3) calcular interseção de todos os conjuntos
    // comece com o menor conjunto para otimizar
    std::sort(sets.begin(), sets.end(), [](const std::set<int>& a, const std::set<int>& b){
        return a.size() < b.size();
    });

    std::set<int> result = sets.front();

    for (size_t i = 1; i < sets.size(); ++i) {
        std::set<int> tmp;
        std::set_intersection(result.begin(), result.end(),
                              sets[i].begin(), sets[i].end(),
                              std::inserter(tmp, tmp.begin()));
        result.swap(tmp);

        if (result.empty()) break;
    }

    // 4) transformar docIDs em caminhos (preservando ordem por docID crescente)
    std::vector<std::string> out;
    out.reserve(result.size());
    for (int docID : result) {
        if (docID >= 0 && docID < (int)index.doc_paths.size())
            out.push_back(index.doc_paths[docID]);
    }

    return out;
}
