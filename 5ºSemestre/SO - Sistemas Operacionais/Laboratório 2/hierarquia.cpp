/*
 Cria uma hierarquia de processos em árvore binária com N níveis.
 O processo raiz cria 2 filhos, cada filho cria mais 2, e assim
 sucessivamente até atingir o nível máximo. O total de processos
 criados é (2^N - 1). Ao final, exibe a árvore com pstree.

 Autor: Erick Molina Gehring
 Criação: 03/04/2026
*/

#include <cstdio> // para printf, perror
#include <cstdlib> // para exit, atoi
#include <unistd.h> // para fork, sleep
#include <sys/wait.h> // para wait
#include <sys/types.h> // para pid_t

/*
 Cria recursivamente dois processos filhos por nível até atingir
 o nível máximo. Processos folha aguardam antes de encerrar.
 O processo raiz (nível 0) exibe a árvore com pstree ao final.
 
 Entrada:
    nivel_atual  - nível do processo atual na hierarquia (começa em 0)
    niveis_max   - número total de níveis da hierarquia (N)
 
 Saída: void
*/
void criar_hierarquia(int nivel_atual, int niveis_max) {
    if (nivel_atual >= niveis_max) {
        // Processo folha: aguarda para manter a árvore visível no pstree
        sleep(3);
        return;
    }

    // Cria dois filhos para este nível
    for (int i = 0; i < 2; i++) { // cada processo cria 2 filhos
        pid_t pid_filho = fork();

        if (pid_filho < 0) {
            perror("Erro ao criar processo filho (fork)");
            exit(EXIT_FAILURE); // falha na criação do processo, encerra o programa
        }

        if (pid_filho == 0) {
            // Processo filho: desce um nível na hierarquia
            criar_hierarquia(nivel_atual + 1, niveis_max);
            exit(EXIT_SUCCESS); // filho encerra após criar seus descendentes
        }
    }

    // Apenas o processo raiz exibe a árvore
    if (nivel_atual == 0) {
        sleep(1); // aguarda todos os descendentes serem criados

        printf("\n Hierarquia de processos (pstree -p %d) \n", getpid());
        fflush(stdout); // garante que a saída seja exibida antes do comando pstree

        char comando_pstree[64];
        snprintf(comando_pstree, sizeof(comando_pstree), "pstree -p %d", getpid()); // formata o comando para mostrar a hierarquia do processo raiz
        system(comando_pstree); // executa o comando para mostrar a hierarquia de processos
        printf("\n");
        fflush(stdout);
    }

    // Aguarda todos os filhos diretos encerrarem
    int status_filho;
    while (wait(&status_filho) > 0);
}

/*
 Ponto de entrada. Lê o número de níveis N via argumento de linha
 de comando (padrão: 3) e inicia a criação da hierarquia.

 Entrada:
   argc - número de argumentos
   argv - vetor de argumentos; argv[1] = N (opcional)

 Saída: 0 em caso de sucesso, 1 em caso de erro
*/
int main(int argc, char* argv[]) {
    int numero_niveis = 3; // valor padrão

    if (argc > 1) { // se um argumento for fornecido, tenta convertê-lo para inteiro
        numero_niveis = atoi(argv[1]);
        if (numero_niveis <= 0) {
            fprintf(stderr, "Erro: N deve ser maior que 0.\n");
            return 1;
        }
    }

    int total_processos = (1 << numero_niveis) - 1; // 2^N - 1

    printf("Criando hierarquia com N = %d níveis.\n", numero_niveis);
    printf("Total de processos criados: %d\n", total_processos);
    printf("PID do processo raiz: %d\n\n", getpid());
    fflush(stdout);

    criar_hierarquia(0, numero_niveis);

    printf("Hierarquia encerrada.\n");
    return 0;
}