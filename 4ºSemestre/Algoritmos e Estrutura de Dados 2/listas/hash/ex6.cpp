#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

// 6. Dado um vetor de strings palavras, retorne um vetor de vetores, onde cada vetor interno contém todas
// as palavras que são anagramas entre si. Por exemplo, se palavras = {"ate", "eat", "tea", "bat",
// "tab"}, então a saída deve ser {{"ate", "eat", "tea"}, {"bat", "tab"}}.


std::vector<std::vector<std::string>> agruparAnagramas(std::vector<std::string>& palavras){
    std::unordered_map<std::string, std::vector<std::string>> mapaAnagramas;
    
    for (const std::string& palavra : palavras) {
        std::string chave = palavra;
        std::sort(chave.begin(), chave.end()); // Ordena os caracteres da palavra para formar a chave
        
        mapaAnagramas[chave].push_back(palavra); // Adiciona a palavra ao grupo correspondente
    }
    
    std::vector<std::vector<std::string>> resultado;
    for (const auto& par : mapaAnagramas) {
        resultado.push_back(par.second); // Adiciona cada grupo de anagramas ao resultado
    }
    
    return resultado;

}

int main() {
    std::vector<std::string> palavras = {"ate", "eat", "tea", "bat", "tab"};
    std::vector<std::vector<std::string>> resultado = agruparAnagramas(palavras);
    
    std::cout << "Grupos de anagramas:\n";
    for (const auto& grupo : resultado) {
        std::cout << "{ ";
        for (const auto& palavra : grupo) {
            std::cout << palavra << " ";
        }
        std::cout << "}\n";
    }
    
    return 0;
}

/*
  Vamos seguir o exemplo palavras = {"ate", "eat", "tea", "bat", "tab"}.

   1. `std::unordered_map<std::string, std::vector<std::string>> mapaAnagramas;`
       Primeiro, é criado um mapaAnagramas. Pense nele como um dicionário ou um classificador.
       A chave do mapa será a palavra com as letras ordenadas (ex: "aet").
       O valor associado a essa chave será uma lista de todas as palavras originais que resultaram naquela chave (ex: {"ate", "eat", "tea"}).


   2. O Loop Principal (`for (const std::string& palavra : palavras)`)
       O código percorre cada palavra da lista de entrada.


       1ª Palavra: `"ate"`
           Cria uma cópia da palavra: chave = "ate".
           Ordena a chave: std::sort(chave.begin(), chave.end()); -> chave agora é "aet".
           Adiciona a palavra original ("ate") à lista de anagramas correspondente à chave "aet": mapaAnagramas["aet"].push_back("ate");.
           Nesse ponto, o mapa está assim: {"aet": {"ate"}}.


       2ª Palavra: `"eat"`
           Cria a cópia: chave = "eat".
           Ordena: chave vira "aet".
           Adiciona a palavra original ("eat") à lista da chave "aet": mapaAnagramas["aet"].push_back("eat");.
           Agora o mapa é: {"aet": {"ate", "eat"}}.


        3ª Palavra: `"tea"`
           Cria a cópia: chave = "tea".
           Ordena: chave vira "aet".
           Adiciona a palavra original ("tea") à lista da chave "aet": mapaAnagramas["aet"].push_back("tea");.
           Agora o mapa é: {"aet": {"ate", "eat", "tea"}}.


       4ª Palavra: `"bat"`
           Cria a cópia: chave = "bat".
           Ordena: chave vira "abt".
           Como a chave "abt" não existe no mapa, ela é criada. A palavra original ("bat") é adicionada à sua lista:
             mapaAnagramas["abt"].push_back("bat");.
           O mapa agora é: {"aet": {"ate", "eat", "tea"}, "abt": {"bat"}}.


        5ª Palavra: `"tab"`
           Cria a cópia: chave = "tab".
           Ordena: chave vira "abt".
           Adiciona a palavra original ("tab") à lista da chave "abt": mapaAnagramas["abt"].push_back("tab");.
           O mapa final é: {"aet": {"ate", "eat", "tea"}, "abt": {"bat", "tab"}}.


   3. Preparando o Resultado Final
       O loop termina. Agora o mapaAnagramas contém todos os grupos, mas o formato não é o vector<vector<string>> que a função precisa
         retornar.
       O código então percorre o mapaAnagramas e simplesmente pega as listas de valores (os grupos de anagramas) e as adiciona a um
         vector<vector<string>> resultado.
       No final, resultado será {{"ate", "eat", "tea"}, {"bat", "tab"}}.
*/