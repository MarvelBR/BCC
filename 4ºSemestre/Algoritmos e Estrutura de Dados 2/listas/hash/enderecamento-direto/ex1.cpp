#include <iostream> 
#include <string>    

/*
1. Hashing de Strings – Uma função de hashing popularmente utilizada em strings baseia-se em converter
a representação em ASCII da string em um inteiro em uma base K qualquer, seguido por módulo M. Por
exemplo, a string “ABC” (65, 66, 67) pode ser representada na base K=31 por: 65 ×31^2 +66 ×31^1 +67 ×31^0 =
65 × 961 + 66 × 31 + 67 × 1 = 64578. Com M=37, H(ABC; 37) = 64578 % 37 = 13. Lembrando que K e M
são parâmetros e podem ser escolhidos de acordo com a aplicação
*/


// a. Implemente a função de hashing sugerida acima. Use o protótipo: unsigned int string_hash(char* string,
// int M). Considere que a string é terminada em ‘\0’ (null-terminated).
unsigned int string_hash(const char* str, int M) {
    const int K = 31;
    unsigned long long soma = 0;

    // 1. Substituindo strlen(): Calcula o comprimento da string manualmente.
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        n++;
    }

    // Itera sobre cada caractere da string.
    for (int i = 0; i < n; i++) {
        // 2. Substituindo pow(): Calcula K^(n - 1 - i) manualmente.
        unsigned long long potencia_de_K = 1;
        int expoente = n - 1 - i;
        // Loop para calcular a potência através de multiplicação repetida.
        for (int j = 0; j < expoente; j++) {
            potencia_de_K *= K;
        }
        // Acumula o valor do caractere ponderado pela potência de K.
        soma += (unsigned int)(str[i]) * potencia_de_K;
    }

    return soma % M;
}

// b. Implemente a função de hashing usando o Método de Horner (versão sem strlen).
unsigned int string_hash_horner(const char* str, int M) {
    const int K = 31;
    unsigned int hash = 0;

    // Itera sobre cada caractere da string até encontrar o terminador nulo '\0'.
    // Isso elimina a necessidade de chamar strlen() previamente.
    for (int i = 0; str[i] != '\0'; i++) {
        // Aplica a fórmula de Horner.
        hash = (hash * K + (unsigned int)(str[i])) % M;
    }

    return hash;
}

/*
c. Análise de Complexidade (não muda com a remoção de pow/strlen,
   pois a implementação manual de pow tem a mesma complexidade do que a da biblioteca).
*/

int main() {
    char str[] = "ABC";
    int M = 37;

    unsigned int hash_a = string_hash(str, M);
    unsigned int hash_b = string_hash_horner(str, M);

    std::cout << "String: " << str << std::endl;
    std::cout << "M = " << M << std::endl;
    std::cout << "Hash (metodo a: " << hash_a << std::endl;
    std::cout << "Hash (metodo b - Horner): " << hash_b << std::endl;

    // A verificação manual continua a mesma, pois a lógica matemática não mudou.
    // O resultado esperado para ambos ainda é 13.

    return 0;
}