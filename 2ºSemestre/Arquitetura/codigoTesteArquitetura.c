#include <stdio.h>

// Função Normal (Chamada de função folha)
int soma(int a, int b) {
    return a + b;   //Add
}

// Função Não-Folha (Chama outra função)
int multiplicarPor2(int a, int b) {
    return soma(a, b) * 2; //Sll por 2
}

int main() {
    // Variáveis para os testes
    int x = 3, y = 2;     //Addi //$s1 e $s2
    int resultado;        //Add ou Addi //$s0

    // Instruções R (Add, Sub, And, Or, Xor)
    resultado = x + y;  // Add
    
    resultado = x - y;  // Sub
    
    resultado = x & y;  // And
    
    resultado = x | y;  // Or
    
    resultado = x ^ y;  // Xor

    // Instruções com Imediato (Addi, Andi, Ori)
    resultado = x + 5;  // Addi
    
    resultado = x & 5;  // Andi
    
    resultado = x | 5;  // Ori

    // Desvios Condicionais (Beq, Bne)
    if (x == y) {
        resultado += y; //!ver os valores aqui

    } else { 
        resultado += x; //!ver os valores aqui
    }
    
    if (x > y) {  // Slt
        resultado = x+y; //!ver os valores aqui
    }

    // Operações de Memória (Lw, Sw)   

    //No Assembly, será um pouco diferente, pois não sabemos declarar um vetor lá!
    int memoria[10]; //! CABULOSO, CPA Q TA ERRADO PRA KRL
    memoria[0] = 42;  // Sw
    resultado = memoria[0];  // Lw

    // Laços de Repetição não Aninhados (For, While)

    //For
    for (int i = 0; i < x; i++) {
        resultado+=i; //!ver os valores aqui
    }

    //While
    int i = 0;
    while (i < y) {
        resultado+=i; //!ver os valores aqui
        i++;
    }

    // Laço de Repetição Aninhado (For dentro de For)
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            resultado+=i+j; //!ver os valores aqui
        }
    }

    // Chamada de Função Folha
    resultado = soma(x, y);

    // Chamada de Função Não-Folha
    resultado = multiplicarPor2(x, y);

    return 0;
}