#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
#include "index.h"

class Serializer {
public:
    bool save(const std::string& filename, const Index& idx);
    bool load(const std::string& filename, Index& idx);
};

#endif
