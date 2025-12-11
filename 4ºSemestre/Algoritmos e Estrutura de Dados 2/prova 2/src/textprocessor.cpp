#include "../include/textprocessor.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

// Converte string para minúsculo
std::string TextProcessor::to_lower(const std::string &s)
{
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return out;
}

// Remove pontuação (mantém apenas letras, números e espaço)
std::string TextProcessor::remove_punctuation(const std::string &s)
{
    std::string clean;
    for (unsigned char c : s)
    {
        if (std::isalnum(c) || std::isspace(c))
            clean.push_back(c);
        else
            clean.push_back(' '); // substitui por espaço (evita colar palavras)
    }
    return clean;
}

std::string TextProcessor::remove_accents(const std::string &s)
{
    std::string out;
    out.reserve(s.size());

    for (size_t i = 0; i < s.size(); ++i)
    {
        unsigned char c = s[i];

        // UTF-8 acentuado simples começa com 0xC3
        if (c == 0xC3 && i + 1 < s.size())
        {
            unsigned char next = s[i + 1];

            // mapa dos acentos comuns em português
            switch (next)
            {
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4: // à á â ã ä
            case 0x80: // À
            case 0x81: // Á
            case 0x82: // Â
            case 0x83: // Ã
            case 0x84: // Ä
                out.push_back('a');
                break;

            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB: // è é ê ë
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B: // È É Ê Ë
                out.push_back('e');
                break;

            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF: // ì í î ï
            case 0x8C:
            case 0x8D:
            case 0x8E:
            case 0x8F: // Ì Í Î Ï
                out.push_back('i');
                break;

            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5: // ò ó ô õ ö
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95: // Ò Ó Ô Õ Ö
                out.push_back('o');
                break;

            case 0xB9:
            case 0xBA:
            case 0xBB:
            case 0xBC: // ù ú û ü
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C: // Ù Ú Û Ü
                out.push_back('u');
                break;

            case 0xA7:
            case 0x87: // ç Ç
                out.push_back('c');
                break;

            default:
                // caractere acentuado desconhecido → ignora
                out.push_back(' ');
            }

            // pular o segundo byte
            i++;
        }
        else
        {
            // caractere ASCII normal
            out.push_back(c);
        }
    }

    return out;
}

// Carrega stopwords do arquivo
bool TextProcessor::load_stopwords(const std::string &path)
{
    std::ifstream file(path);
    if (!file)
        return false;

    stopwords.clear();
    std::string word;

    while (file >> word)
    {
        word = to_lower(word);
        word = remove_accents(word);
        stopwords.insert(word);
    }

    return true;
}

// Tokeniza texto: lowercase → remove pontuação → split → remove stopwords
std::vector<std::string> TextProcessor::tokenize(const std::string &text)
{
    // 1) lowercase
    std::string tmp = to_lower(text);

    // 2) remover acentos
    tmp = remove_accents(tmp);

    // 3) remover pontuação
    tmp = remove_punctuation(tmp);

    // 4) dividir por espaços
    std::stringstream ss(tmp);
    std::string word;
    std::vector<std::string> tokens;

    while (ss >> word)
    {
        // 5) ignorar stopwords
        if (stopwords.count(word) == 0)
            tokens.push_back(word);
    }

    return tokens;
}
