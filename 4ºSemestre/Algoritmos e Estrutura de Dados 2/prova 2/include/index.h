#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

class Index {
public:
    // palavra -> conjunto de IDs de documentos
    std::unordered_map<std::string, std::set<int>> inverted;

    // id -> caminho do arquivo
    std::vector<std::string> doc_paths;

    // diretório base indexado (requisito do trabalho)
    std::string base_directory;
};

#endif
