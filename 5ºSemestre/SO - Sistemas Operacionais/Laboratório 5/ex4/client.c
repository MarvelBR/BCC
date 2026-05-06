/*
 Descrição: Cliente do serviço de tradução via socket UNIX.
            Conecta-se ao servidor e envia requisições no formato
            "LANG:PALAVRA" (ex: "pt-en:cachorro"). Exibe a resposta
            do servidor. Encerra enviando "NO-NO".
 
 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/traducao_socket"
#define MAX_MSG     256
#define CMD_SAIR    "NO-NO"

/*
 Lê a resposta do servidor linha a linha (até '\n' ou EOF).

 Entrada: fd  - descritor do socket
          buf - buffer de destino
          max - tamanho máximo do buffer
 Saída: número de caracteres lidos, ou -1 em erro/EOF
*/
static int ler_resposta_servidor(int fd, char *buf, int max)
{
    int    idx = 0;
    char   c;
    ssize_t n;

    while (idx < max - 1) {
        n = read(fd, &c, 1);
        if (n <= 0) return -1;
        if (c == '\n') break;
        buf[idx++] = c;
    }
    buf[idx] = '\0';
    return idx;
}

/*
 Exibe instruções de uso para o usuário.

 Entrada: (nenhuma)
 Saída: (nenhuma)
*/
static void exibir_ajuda(void)
{
    printf("\n  Serviço de Tradução - Uso:\n");
    printf("  Formato  : LANG:PALAVRA\n");
    printf("  Exemplo  : pt-en:cachorro\n");
    printf("  Exemplo  : en-pt:dog\n");
    printf("  Exemplo  : pt-es:carro\n");
    printf("  Encerrar : NO-NO\n\n");
    printf("  Idiomas suportados: pt, en, es (pares: pt-en, en-pt,\n");
    printf("                       pt-es, es-pt, en-es, es-en)\n\n");
}

// Main
int main(void)
{
    int  fd;
    struct sockaddr_un addr;
    char entrada[MAX_MSG];
    char resposta[MAX_MSG];

    // Cria socket UNIX
    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("[cliente] socket");
        exit(EXIT_FAILURE);
    }

    // Configura endereço do servidor
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Conecta ao servidor
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("[cliente] connect");
        fprintf(stderr, "[cliente] Certifique-se de que o servidor está "
                        "rodando.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("╔══════════════════════════════════════╗\n");
    printf("║   Cliente de Tradução - Socket UNIX  ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("[cliente] Conectado ao servidor.\n");
    exibir_ajuda();

    // Loop de envio de requisições
    while (1) {
        printf("traduzir> ");
        fflush(stdout);

        if (fgets(entrada, MAX_MSG, stdin) == NULL) {
            // EOF: encerra
            printf("\n[cliente] EOF detectado. Encerrando...\n");
            // Envia NO-NO para o servidor
            const char *msg_sair = CMD_SAIR "\n";
            write(fd, msg_sair, strlen(msg_sair));
            break;
        }

        // Remove newline
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strlen(entrada) == 0)
            continue;

        // Envia ao servidor (com '\n' como delimitador)
        char msg[MAX_MSG + 2];
        snprintf(msg, sizeof(msg), "%s\n", entrada);
        if (write(fd, msg, strlen(msg)) < 0) {
            perror("[cliente] write");
            break;
        }

        // Se for NO-NO, lê a confirmação e encerra
        if (strcmp(entrada, CMD_SAIR) == 0) {
            ler_resposta_servidor(fd, resposta, MAX_MSG);
            printf("[cliente] Servidor respondeu: %s\n", resposta);
            printf("[cliente] Encerrando.\n");
            break;
        }

        // Lê e exibe a resposta
        if (ler_resposta_servidor(fd, resposta, MAX_MSG) < 0) {
            printf("[cliente] Servidor desconectou.\n");
            break;
        }

        printf("[resultado] %s\n\n", resposta);
    }

    close(fd);
    return 0;
}
