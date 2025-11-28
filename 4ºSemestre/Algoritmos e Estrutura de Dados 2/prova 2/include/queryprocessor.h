#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <string>
#include <vector>
#include <set>
#include "../include/index.h"
#include "../include/textprocessor.h"

class QueryProcessor {
private:
    Index index;
    TextProcessor tp; // para normalizar termos de busca

public:
    QueryProcessor(const Index& idx);

    // termos *brutos* (argv). O método normaliza e retorna caminhos dos arquivos que contêm todos os termos (AND).
    std::vector<std::string> search(const std::vector<std::string>& terms);
};

#endif
