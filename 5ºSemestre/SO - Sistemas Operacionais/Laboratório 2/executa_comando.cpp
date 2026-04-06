/*
 Recebe um comando e seus argumentos via linha de comando e o
 executa como processo filho usando execvp(). O processo pai
 aguarda o término do filho antes de exibir a mensagem final.

 Autor:     Erick Molina Gehring
 Criação:   03/04/2026
*/

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <libgen.h> // para basename() - extrai o nome do programa a partir do caminho

/*
 Cria um processo filho que executa o comando recebido via argv.
 O processo pai aguarda o filho terminar e exibe o código de saída.

 Entrada:
   argc - número de argumentos (mínimo 2: programa + comando)
   argv - vetor de argumentos; argv[1] = comando, argv[2..] = argumentos
 
 Saída: 0 em caso de sucesso, 1 em caso de erro
*/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <comando> [argumentos...]\n", argv[0]);
        fprintf(stderr, "Exemplo: %s ping 8.8.8.8 -c 3\n", argv[0]);
        return 1;
    }

    pid_t pid_filho = fork();

    if (pid_filho < 0) {
        perror("Erro ao criar processo filho (fork)");
        return 1;
    }

    if (pid_filho == 0) {
        // Processo filho: substitui sua imagem pelo comando informado
        execvp(argv[1], &argv[1]);

        // Só chega aqui se execvp falhar
        perror("Erro ao executar o comando (execvp)");
        exit(EXIT_FAILURE);
    }

    // Processo pai: aguarda o filho terminar
    int status_filho;
    waitpid(pid_filho, &status_filho, 0);

    if (WIFEXITED(status_filho)) { // filho terminou normalmente, exibe o código de saída
        printf("\nProcesso %s finalizado (código de saída: %d).\n",
               basename(argv[0]), WEXITSTATUS(status_filho));
    } else if (WIFSIGNALED(status_filho)) { // filho foi terminado por um sinal, exibe o número do sinal
        printf("\nProcesso %s encerrado por sinal %d.\n",
               basename(argv[0]), WTERMSIG(status_filho));
    }

    return 0;
}