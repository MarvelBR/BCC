/*
 Descrição: Programa escritor (ex1 - FIFO). Lê strings digitadas pelo
            usuário e as envia via FIFO nomeado para o programa reader,
            que realiza a análise de cada string.

 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_PATH "/tmp/fifo_ex1_strings"
#define MAX_BUF   512
#define CMD_SAIR  "SAIR"

/*
 Escreve a string no descritor do FIFO, incluindo o terminador nulo para delimitar mensagens.

 Entrada: fd - descritor do FIFO aberto para escrita
          str - string a ser enviada
 Saída: número de bytes escritos, ou -1 em erro
*/
static ssize_t enviar_string(int fd, const char *str)
{
    size_t tamanho = strlen(str) + 1; // inclui '\0'
    return write(fd, str, tamanho);
}

int main(void)
{
    char  buf[MAX_BUF];
    int   fd;

    // Cria o FIFO; ignora EEXIST caso já exista
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        // pode já existir de uma execução anterior
    }

    printf("[writer] Aguardando reader abrir o FIFO...\n");

    // Abertura bloqueia até o reader abrir a outra ponta
    fd = open(FIFO_PATH, O_WRONLY); // O_WRONLY para escrita
    if (fd < 0) {
        perror("[writer] open FIFO");
        exit(EXIT_FAILURE);
    }

    printf("[writer] Conectado ao reader!\n");
    printf("[writer] Digite strings para analisar (ou '%s' para encerrar):\n\n",
           CMD_SAIR);

    while (1) {
        printf("> ");
        fflush(stdout); // Garante que o prompt seja exibido antes da entrada do usuário

        if (fgets(buf, MAX_BUF, stdin) == NULL) { // fgets captura o que o usuário digitar, incluindo o '\n'
            // EOF (Ctrl+D) – envia comando de saída
            enviar_string(fd, CMD_SAIR);
            break;
        }

        // Remove newline final
        buf[strcspn(buf, "\n")] = '\0';

        // Envia a string (incluindo '\0') pelo FIFO
        if (enviar_string(fd, buf) < 0) {
            perror("[writer] write");
            break;
        }

        // Encerra se o usuário digitou o comando de saída
        if (strcmp(buf, CMD_SAIR) == 0) {
            break;
        }
    }

    close(fd);
    printf("[writer] Encerrado.\n");
    return 0;
}
