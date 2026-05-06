/*
 Descrição: Servidor de tradução de palavras usando socket UNIX.
            Para cada cliente que se conecta, o servidor cria um
            processo filho para atender as requisições de tradução.
            O cliente envia solicitações no formato "LANG:PALAVRA"
            (ex: "pt-en:cachorro") e recebe a tradução ou
            "ERROR:UNKNOWN". O cliente encerra enviando "NO-NO".
 
 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
*/

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>

#define SOCKET_PATH   "/tmp/traducao_socket"
#define MAX_MSG       256
#define MAX_CLIENTES  10   // backlog de conexões

// Dicionário de traduções

typedef struct {
    char lang[8];      // par de idiomas, ex: "pt-en"
    char origem[64];   // palavra na língua de origem
    char destino[64];  // palavra traduzida
} Traducao;

// Dicionário hardcoded com pares pt-en e en-pt (ISO 639-1)
static const Traducao dicionario[] = {
    // pt → en
    {"pt-en", "cachorro",    "dog"},
    {"pt-en", "gato",        "cat"},
    {"pt-en", "casa",        "house"},
    {"pt-en", "carro",       "car"},
    {"pt-en", "computador",  "computer"},
    {"pt-en", "livro",       "book"},
    {"pt-en", "agua",        "water"},
    {"pt-en", "pão",         "bread"},
    {"pt-en", "escola",      "school"},
    {"pt-en", "amigo",       "friend"},
    {"pt-en", "sol",         "sun"},
    {"pt-en", "lua",         "moon"},
    {"pt-en", "cidade",      "city"},
    {"pt-en", "tempo",       "weather"},
    {"pt-en", "trabalho",    "work"},
    // en → pt
    {"en-pt", "dog",         "cachorro"},
    {"en-pt", "cat",         "gato"},
    {"en-pt", "house",       "casa"},
    {"en-pt", "car",         "carro"},
    {"en-pt", "computer",    "computador"},
    {"en-pt", "book",        "livro"},
    {"en-pt", "water",       "agua"},
    {"en-pt", "bread",       "pão"},
    {"en-pt", "school",      "escola"},
    {"en-pt", "friend",      "amigo"},
    {"en-pt", "sun",         "sol"},
    {"en-pt", "moon",        "lua"},
    {"en-pt", "city",        "cidade"},
    {"en-pt", "weather",     "tempo"},
    {"en-pt", "work",        "trabalho"},
    // pt → es
    {"pt-es", "cachorro",    "perro"},
    {"pt-es", "gato",        "gato"},
    {"pt-es", "casa",        "casa"},
    {"pt-es", "carro",       "coche"},
    {"pt-es", "amigo",       "amigo"},
    // es → pt
    {"es-pt", "perro",       "cachorro"},
    {"es-pt", "gato",        "gato"},
    {"es-pt", "casa",        "casa"},
    {"es-pt", "coche",       "carro"},
    {"es-pt", "amigo",       "amigo"},
    // en → es
    {"en-es", "dog",         "perro"},
    {"en-es", "cat",         "gato"},
    {"en-es", "house",       "casa"},
    {"en-es", "car",         "coche"},
    {"en-es", "friend",      "amigo"},
    /* es → en */
    {"es-en", "perro",       "dog"},
    {"es-en", "gato",        "cat"},
    {"es-en", "casa",        "house"},
    {"es-en", "coche",       "car"},
    {"es-en", "amigo",       "friend"},
};
static const int TAM_DICIONARIO =
    (int)(sizeof(dicionario) / sizeof(dicionario[0]));

/*
 Converte uma string para minúsculas in-place.

 Entrada: s - ponteiro para a string
 Saída: (nenhuma)
*/
static void str_para_minusculo(char *s)
{
    for (int i = 0; s[i]; i++)
        s[i] = (char)tolower((unsigned char)s[i]);
}

/*
 Procura uma tradução no dicionário para o par de idiomas e a palavra fornecidos.

 Entrada: lang     - par de idiomas (ex: "pt-en")
          palavra  - palavra a traduzir
 Saída: ponteiro para a tradução, ou NULL se não encontrada
*/
static const char *traduzir(const char *lang, const char *palavra)
{
    for (int i = 0; i < TAM_DICIONARIO; i++) {
        if (strcmp(dicionario[i].lang, lang) == 0 &&
            strcmp(dicionario[i].origem, palavra) == 0) {
            return dicionario[i].destino;
        }
    }
    return NULL;
}

/*
 Analisa uma mensagem no formato "LANG:PALAVRA", consulta o dicionário e escreve a resposta no socket.

 Entrada: fd  - descritor do socket do cliente
          msg - mensagem recebida do cliente (terminada em '\0')
 Saída: (nenhuma)
*/
static void processar_requisicao(int fd, char *msg)
{
    char resposta[MAX_MSG];
    char lang[8]    = {0};
    char palavra[64] = {0};

    // Separa o código de idioma da palavra: "LANG:PALAVRA"
    char *sep = strchr(msg, ':');
    if (sep == NULL) {
        snprintf(resposta, MAX_MSG, "ERROR:FORMATO_INVALIDO\n");
        write(fd, resposta, strlen(resposta));
        return;
    }

    // Copia o código de idioma
    size_t lang_len = (size_t)(sep - msg);
    if (lang_len >= sizeof(lang)) lang_len = sizeof(lang) - 1;
    strncpy(lang, msg, lang_len);
    lang[lang_len] = '\0';

    // Copia a palavra
    strncpy(palavra, sep + 1, sizeof(palavra) - 1);
    palavra[sizeof(palavra) - 1] = '\0';

    // Normaliza para minúsculas
    str_para_minusculo(lang);
    str_para_minusculo(palavra);

    printf("[filho] Traduzir '%s' de '%s'\n", palavra, lang);

    // Consulta o dicionário
    const char *traducao = traduzir(lang, palavra);
    if (traducao != NULL) {
        snprintf(resposta, MAX_MSG, "%s\n", traducao);
    } else {
        snprintf(resposta, MAX_MSG, "ERROR:UNKNOWN\n");
    }

    write(fd, resposta, strlen(resposta));
}

/*
 Loop de atendimento do processo filho para um cliente.
 Lê requisições e responde até receber "NO-NO".

 Entrada: fd_cliente - descritor do socket do cliente
 Saída: (não retorna – chama exit())
*/
static void atender_cliente(int fd_cliente)
{
    char buf[MAX_MSG];
    ssize_t n;

    printf("[filho] Atendendo cliente (fd=%d).\n", fd_cliente);

    while (1) {
        memset(buf, 0, sizeof(buf));

        // Lê a requisição do cliente linha a linha
        int idx = 0;
        char c;
        while (idx < MAX_MSG - 1) {
            n = read(fd_cliente, &c, 1);
            if (n <= 0) {
                // Cliente desconectou
                printf("[filho] Cliente desconectou.\n");
                close(fd_cliente);
                exit(EXIT_SUCCESS);
            }
            if (c == '\n') break;
            buf[idx++] = c;
        }
        buf[idx] = '\0';

        if (strlen(buf) == 0)
            continue;

        printf("[filho] Recebido: '%s'\n", buf);

        // Verifica comando de encerramento
        if (strcmp(buf, "NO-NO") == 0) {
            const char *msg = "CONEXAO_ENCERRADA\n";
            write(fd_cliente, msg, strlen(msg));
            printf("[filho] Cliente solicitou encerramento.\n");
            break;
        }

        processar_requisicao(fd_cliente, buf);
    }

    close(fd_cliente);
    printf("[filho] Processo filho encerrado.\n");
    exit(EXIT_SUCCESS);
}


/*
 Recolhe processos filhos encerrados (evita zumbis).

 Entrada: signo - número do sinal (SIGCHLD)
 Saída: (nenhuma)
*/
static void handler_sigchld(int signo)
{
    (void)signo;
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ; // recolhe todos os filhos prontos 
}

int main(void)
{
    int  fd_servidor, fd_cliente;
    struct sockaddr_un addr;

    // Registra handler para recolher filhos
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler_sigchld;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCHLD, &sa, NULL);

    // Remove socket anterior (se existir)
    unlink(SOCKET_PATH);

    // Cria socket UNIX de domínio (stream)
    fd_servidor = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd_servidor < 0) {
        perror("[servidor] socket");
        exit(EXIT_FAILURE);
    }

    // Configura endereço
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    // Bind
    if (bind(fd_servidor, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("[servidor] bind");
        close(fd_servidor);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(fd_servidor, MAX_CLIENTES) < 0) {
        perror("[servidor] listen");
        close(fd_servidor);
        unlink(SOCKET_PATH);
        exit(EXIT_FAILURE);
    }

    printf("[servidor] Serviço de tradução iniciado.\n");
    printf("[servidor] Socket: %s\n", SOCKET_PATH);
    printf("[servidor] Aguardando conexões...\n\n");

    // Loop de aceitação de clientes
    while (1) {
        fd_cliente = accept(fd_servidor, NULL, NULL);
        if (fd_cliente < 0) {
            if (errno == EINTR)
                continue; // interrompido por sinal, tenta novamente
            perror("[servidor] accept");
            continue;
        }

        printf("[servidor] Novo cliente conectado (fd=%d). "
               "Criando processo filho...\n", fd_cliente);

        pid_t pid = fork();
        if (pid < 0) {
            perror("[servidor] fork");
            close(fd_cliente);
            continue;
        }

        if (pid == 0) {
            //PROCESSO FILHO
            close(fd_servidor); // filho não precisa do socket do servidor
            atender_cliente(fd_cliente); // não retorna
        }

        // Pai fecha o fd do cliente (filho tem sua própria cópia)
        close(fd_cliente);
        printf("[servidor] Filho PID=%d criado para atender o cliente.\n",
               (int)pid);
    }

    close(fd_servidor);
    unlink(SOCKET_PATH);
    return 0;
}
