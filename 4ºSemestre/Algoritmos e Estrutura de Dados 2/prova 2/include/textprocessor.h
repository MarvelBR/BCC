#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include <vector>
#include <unordered_set>

class TextProcessor {
private:
    std::unordered_set<std::string> stopwords;

    std::string to_lower(const std::string& s);
    std::string remove_punctuation(const std::string& s);
    std::string remove_accents(const std::string& s);

public:
    bool load_stopwords(const std::string& path);

    // Tokeniza texto: lowercase → remove pontuação → split → remove stopwords
    std::vector<std::string> tokenize(const std::string& text);
};

#endif
