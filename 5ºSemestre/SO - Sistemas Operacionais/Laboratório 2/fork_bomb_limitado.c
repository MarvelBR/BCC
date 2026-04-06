/*
 Demonstração de fork bomb recursiva com limite de profundidade.
 Cada processo criado também cria filhos, simulando o crescimento
 exponencial de uma fork bomb real. O limite de profundidade evita
 travar o sistema durante a demonstração.
 Sem esse limite, o sistema esgotaria todos os recursos disponíveis
 (memória, CPU e tabela de processos do kernel).
 
 Autor:     Erick Molina Gehring
 Criação:   03/04/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Profundidade máxima da recursão (total de processos = 2^LIMITE - 1)
#define LIMITE_PROFUNDIDADE 4

/*
 Cria dois processos filhos recursivamente até atingir a profundidade
 máxima. Cada filho também chama esta função, simulando uma fork bomb.

 Entrada:
    profundidade_atual - nível atual da recursão (começa em 0)

 Saída: void
 */
void fork_recursivo(int profundidade_atual) {
    if (profundidade_atual >= LIMITE_PROFUNDIDADE) {
        return; // profundidade máxima atingida, encerra o ramo
    }

    // Cada processo cria dois filhos — crescimento exponencial
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("fork() falhou na profundidade %d! Sistema sem recursos.\n",
                   profundidade_atual);
            fflush(stdout);
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Filho: continua a recursão
            printf("  Nível %d | PID=%d criado pelo pai PID=%d\n",
                   profundidade_atual + 1, getpid(), getppid());
            fflush(stdout);

            fork_recursivo(profundidade_atual + 1);
            exit(EXIT_SUCCESS);
        }
    }

    // Pai aguarda seus dois filhos diretos
    int status;
    wait(&status);
    wait(&status);
}

/*
 Inicia a fork bomb recursiva a partir do processo raiz.
 Saída: 0 em caso de sucesso
*/
int main() {
    int total = (1 << LIMITE_PROFUNDIDADE) - 1; /* 2^N - 1 */

    printf("=== Fork Bomb Recursiva (limitada a %d níveis) ===\n", LIMITE_PROFUNDIDADE);
    printf("PID inicial: %d\n", getpid());
    printf("Total esperado de processos filhos: %d\n\n", total);
    fflush(stdout);

    fork_recursivo(0);

    return 0;
}