#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include "index.h"
#include "textprocessor.h"

class Indexer {
public:
    Index build_index(const std::string& directory);
};

#endif
