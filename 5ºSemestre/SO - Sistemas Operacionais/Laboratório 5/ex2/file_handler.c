/*
 Descrição: Programa que manipula um arquivo (leitura e escrita) e,
            ao receber SIGINT (sinal 2) ou SIGTERM (sinal 15), realiza
            uma finalização limpa (graceful stop): salva os dados
            pendentes em memória e fecha o arquivo corretamente antes
            de encerrar.

 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

#define ARQUIVO_SAIDA  "dados.txt"
#define MAX_BUF        256
#define BUFFER_MAX     16      // número máximo de linhas no buffer pendente

// Estado global compartilhado com os handlers de sinal

// Buffer de linhas pendentes (ainda não escritas no arquivo)
static char  buffer_pendente[BUFFER_MAX][MAX_BUF];
static int   num_pendentes = 0;

// Descritor do arquivo aberto
static FILE *arquivo = NULL;

// Flag de encerramento (volatile para visibilidade entre handler/main)
static volatile sig_atomic_t encerrar = 0;

/*
 Preenche o buffer com a data/hora atual formatada.

 Entrada: buf - buffer de destino
          size - tamanho do buffer
 Saída: (nenhuma)
*/
static void timestamp_atual(char *buf, size_t size)
{
    time_t agora = time(NULL);
    struct tm *tm_info = localtime(&agora);
    strftime(buf, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

/*
 Grava todas as linhas do buffer pendente no arquivo
 aberto e zera o contador de pendentes.

 Entrada: fp - ponteiro para o arquivo de saída
 Saída: (nenhuma)
*/
static void flush_buffer(FILE *fp)
{
    if (fp == NULL || num_pendentes == 0)
        return;

    printf("[info] Gravando %d linha(s) pendente(s) no arquivo...\n",
           num_pendentes);

    for (int i = 0; i < num_pendentes; i++) {
        char ts[32];
        timestamp_atual(ts, sizeof(ts));
        fprintf(fp, "[%s] %s\n", ts, buffer_pendente[i]);
    }
    fflush(fp); // fflush garante que os dados sejam realmente escritos no arquivo
    num_pendentes = 0;
    printf("[info] Gravação concluída.\n");
}

/*
 Captura SIGINT e SIGTERM. Sinaliza ao loop principal para encerrar de forma limpa.

 Entrada: signo - número do sinal recebido
 Saída: (nenhuma)
*/
static void handler_graceful_stop(int signo)
{
    const char *nome = (signo == SIGINT) ? "SIGINT" : "SIGTERM"; // Identifica o sinal recebido

    // write() é async-signal-safe; printf/fprintf não são
    const char msg1[] = "\n[sinal] Recebido ";
    const char msg2[] = " - iniciando finalização limpa...\n";
    write(STDOUT_FILENO, msg1, sizeof(msg1) - 1); // escreve a parte fixa da mensagem
    write(STDOUT_FILENO, nome, strlen(nome)); // escreve o nome do sinal
    write(STDOUT_FILENO, msg2, sizeof(msg2) - 1); // escreve a parte final da mensagem

    encerrar = 1;
}

int main(void)
{
    char entrada[MAX_BUF];

    // Abre o arquivo para escrita em modo de adição
    arquivo = fopen(ARQUIVO_SAIDA, "a");
    if (arquivo == NULL) {
        perror("[erro] fopen");
        exit(EXIT_FAILURE);
    }
    printf("[info] Arquivo '%s' aberto para escrita.\n", ARQUIVO_SAIDA);

    // Registra handlers para SIGINT e SIGTERM
    struct sigaction sa; // estrutura para configurar o handler de sinal
    memset(&sa, 0, sizeof(sa)); // inicializa a estrutura com zeros
    sa.sa_handler = handler_graceful_stop; // função a ser chamada quando o sinal for recebido
    sigemptyset(&sa.sa_mask); // não bloqueia nenhum sinal adicional durante a execução do handler
    sa.sa_flags = 0; // sem flags especiais

    if (sigaction(SIGINT, &sa, NULL) == -1) { // registra handler para SIGINT
        perror("[erro] sigaction SIGINT");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGTERM, &sa, NULL) == -1) { // registra handler para SIGTERM
        perror("[erro] sigaction SIGTERM");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    printf("[info] Handlers registrados para SIGINT e SIGTERM.\n");
    printf("[info] Digite linhas de texto (Ctrl+C ou 'kill -15 PID' para encerrar):\n");
    printf("[info] PID deste processo: %d\n\n", (int)getpid());

    // Loop principal: lê linhas do usuário e as armazena em buffer
    while (!encerrar) {
        printf("entrada> ");
        fflush(stdout);

        if (fgets(entrada, MAX_BUF, stdin) == NULL) { // o stdin serve para simular uma fonte de dados
            // EOF ou interrupção por sinal
            if (encerrar)
                break;
            // Stdin fechado sem sinal: encerra normalmente
            break;
        }

        // Remove newline
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strlen(entrada) == 0)
            continue;

        // Armazena no buffer pendente
        if (num_pendentes < BUFFER_MAX) {
            strncpy(buffer_pendente[num_pendentes], entrada, MAX_BUF - 1); // copia a linha para o buffer, garantindo que não ultrapasse o tamanho máximo
            buffer_pendente[num_pendentes][MAX_BUF - 1] = '\0'; // garante terminação nula
            num_pendentes++;
            printf("[info] Linha armazenada no buffer (%d/%d pendentes).\n",
                   num_pendentes, BUFFER_MAX);
        } else {
            // Buffer cheio: grava no arquivo e reseta
            printf("[info] Buffer cheio. Realizando flush automático...\n");
            flush_buffer(arquivo);
            // Armazena a linha atual após o flush
            strncpy(buffer_pendente[0], entrada, MAX_BUF - 1);
            buffer_pendente[0][MAX_BUF - 1] = '\0';
            num_pendentes = 1;
        }
    }

    // Finalização limpa: grava dados pendentes e fecha o arquivo
    printf("\n[info] Iniciando finalização limpa...\n");

    // Salva quaisquer dados ainda em memória
    flush_buffer(arquivo);

    // Fecha o arquivo de forma segura
    if (fclose(arquivo) == 0) {
        printf("[info] Arquivo '%s' fechado com sucesso.\n", ARQUIVO_SAIDA);
    } else {
        perror("[erro] fclose");
    }

    arquivo = NULL;
    printf("[info] Programa encerrado de forma limpa.\n");
    return 0;
}
