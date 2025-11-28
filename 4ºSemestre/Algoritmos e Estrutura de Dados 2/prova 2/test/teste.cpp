#include "../include/textprocessor.h"
#include <iostream>

int main() {
    TextProcessor tp;
    tp.load_stopwords("data/stopwords.txt");

    auto t = tp.tokenize("Olá, mundo!!! Hoje é um belo dia para programar em C++.");

    for (auto& w : t) std::cout << w << "\n";

    return 0;
}