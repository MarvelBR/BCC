/*
 Interface de shell simples que exibe um prompt ao usuário e
 executa comandos do sistema como processos filhos via execvp().
 Suporta execução em segundo plano com '&' ao final do comando.
 Em foreground, aguarda o filho terminar antes de novo prompt.
 Em background, libera o terminal imediatamente.
 Recolhe filhos em background automaticamente (sem zumbis).
 O comando 'exit' encerra o shell.
        
 Autor: Erick Molina Gehring
 Criação: 03/04/2026
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// Tamanho máximo da linha de entrada
#define TAMANHO_MAXIMO_INPUT 512

// Número máximo de argumentos por comando
#define NUMERO_MAXIMO_ARGS   64

/*
 Divide a linha de entrada em tokens (argumentos) separados por espaço
 e tabulação, preenchendo o vetor argv_comando.

 Entrada:
   linha - string com o comando digitado pelo usuário
   argv_comando - vetor onde os ponteiros para os tokens serão armazenados

 Saída: número de argumentos encontrados (argc)
*/
int tokenizar_comando(char* linha, char* argv_comando[]) {
    int argc = 0;
    char* token = strtok(linha, " \t\n"); // tokeniza usando espaço, tab e newline como delimitadores

    while (token && argc < NUMERO_MAXIMO_ARGS - 1) {
        argv_comando[argc++] = token;
        token = strtok(nullptr, " \t\n");
    }

    argv_comando[argc] = nullptr;
    return argc;
}

/*
 Verifica sem bloquear se algum filho em background já terminou
 e recolhe seu estado, evitando processos zumbis.

 Entrada: void
 Saída:   void
 */
void recolher_filhos_background() {
    int status_filho;
    pid_t pid_encerrado;

    while ((pid_encerrado = waitpid(-1, &status_filho, WNOHANG)) > 0) {
        printf("\n[Background] Processo %d finalizado", pid_encerrado);
        if (WIFEXITED(status_filho)) {
            printf(" (código de saída: %d)", WEXITSTATUS(status_filho));
        }
        printf("\n");
        fflush(stdout);
    }
}

/*
 Loop principal do shell: exibe prompt, lê comando, verifica se é
 background ('&'), cria filho e executa. Repete até o comando 'exit'.
 
 Entrada:
   argc, argv - não utilizados

 Saída: 0 ao encerrar normalmente
*/
int main() {
    char input[TAMANHO_MAXIMO_INPUT];
    char* argv_comando[NUMERO_MAXIMO_ARGS];

    printf("shell — digite 'exit' para sair \n\n");

    while (1) {
        // Recolhe filhos em background antes de exibir o prompt 
        recolher_filhos_background();

        printf("shell$ ");
        fflush(stdout);

        // Lê a linha digitada pelo usuário
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\n");
            break; // EOF (Ctrl+D) encerra o shell 
        }

        // Remove o newline final
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) continue;

        // Verifica se o comando deve ser executado em background
        int executar_background = 0;
        int comprimento = strlen(input);

        if (comprimento > 0 && input[comprimento - 1] == '&') {
            executar_background = 1;
            input[comprimento - 1] = '\0';

            // Remove espaços antes do '&'
            while (strlen(input) > 0 && input[strlen(input) - 1] == ' ') {
                input[strlen(input) - 1] = '\0';
            }
        }

        int argc = tokenizar_comando(input, argv_comando);
        if (argc == 0) continue;

        // Comando interno: encerra o shell
        if (strcmp(argv_comando[0], "exit") == 0) break;

        // Cria processo filho para executar o comando
        pid_t pid_filho = fork();

        if (pid_filho < 0) {
            perror("Erro ao criar processo filho (fork)");
            continue;
        }

        if (pid_filho == 0) {
            // Processo filho: executa o comando
            execvp(argv_comando[0], argv_comando);

            // Só chega aqui se execvp falhar
            fprintf(stderr, "shell: %s: comando não encontrado\n", argv_comando[0]);
            exit(EXIT_FAILURE);
        }

        // Processo pai
        if (executar_background) {
            printf("[Background] PID %d iniciado: %s\n", pid_filho, argv_comando[0]);
            fflush(stdout);
        } else {
            // Foreground: pai aguarda o filho terminar
            int status_filho;
            waitpid(pid_filho, &status_filho, 0);
        }
    }

    // Aguarda filhos em background antes de encerrar
    printf("Encerrando shell...\n");
    int status_filho;
    while (wait(&status_filho) > 0);

    return 0;
}