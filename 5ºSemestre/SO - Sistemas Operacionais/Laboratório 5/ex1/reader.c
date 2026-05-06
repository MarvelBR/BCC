/*
 Descrição: Programa leitor (ex1 - FIFO). Recebe strings enviadas pelo
            programa writer via FIFO nomeado e exibe na tela: a string,
            seu tamanho, número de consoantes, vogais e espaços.

 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strlen(), strcmp() e memset()
#include <ctype.h> // para tolower() e isalpha()
#include <fcntl.h> // para open()
#include <unistd.h> // para read(), close() e unlink()
#include <sys/stat.h> // para mkfifo()
#include <sys/types.h> // para tipos de dados como ssize_t

#define FIFO_PATH "/tmp/fifo_ex1_strings"
#define MAX_BUF   512
#define CMD_SAIR  "SAIR"

/*
 Verifica se um caractere (minúsculo) é vogal.

 Entrada: c - caractere a verificar (já em minúsculo)
 Saída: 1 se vogal, 0 caso contrário
*/
static int eh_vogal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

/*
 Conta vogais, consoantes e espaços de uma string e exibe os resultados na saída padrão.

 Entrada: str - string a ser analisada
 Saída: (nenhuma)
*/
static void analisar_string(const char *str)
{
    int vogais = 0;
    int consoantes = 0;
    int espacos = 0;
    int tamanho = (int)strlen(str);

    for (int i = 0; i < tamanho; i++) {
        char c = (char)tolower((unsigned char)str[i]);

        if (str[i] == ' ') {
            espacos++;
        } else if (isalpha((unsigned char)str[i])) {
            if (eh_vogal(c))
                vogais++;
            else
                consoantes++;
        }
    }

    printf("┌──────────────────────────────────────┐\n");
    printf("│ String     : %-23s │\n", str);
    printf("│ Tamanho    : %-23d │\n", tamanho);
    printf("│ Vogais     : %-23d │\n", vogais);
    printf("│ Consoantes : %-23d │\n", consoantes);
    printf("│ Espaços    : %-23d │\n", espacos);
    printf("└──────────────────────────────────────┘\n\n");
}

/*
 Lê bytes do FIFO até encontrar o terminador '\0', reconstituindo a string enviada pelo writer.

 Entrada: fd  - descritor do FIFO aberto para leitura
          buf - buffer de destino
          max - tamanho máximo do buffer

 Saída: número de caracteres lidos (sem o '\0'), ou -1 em erro/EOF
*/
static int ler_string_fifo(int fd, char *buf, int max)
{
    int  idx = 0;
    char c; 
    ssize_t n; // ssize_t é o tipo retornado por read()

    while (idx < max - 1) {
        n = read(fd, &c, 1); // lê um byte de cada vez para detectar o '\0'
        if (n <= 0)
            return -1; // EOF ou erro
        if (c == '\0')
            break;
        buf[idx++] = c;
    }
    buf[idx] = '\0';
    return idx;
}

int main(void)
{
    char buf[MAX_BUF];
    int  fd;

    // Cria o FIFO; ignora EEXIST 
    if (mkfifo(FIFO_PATH, 0666) == -1) { // 0666 é a permissão rw-rw-rw-
        // pode já ter sido criado pelo writer 
    }

    printf("[reader] Abrindo FIFO para leitura...\n");

    // Abertura bloqueia até o writer abrir a outra ponta
    fd = open(FIFO_PATH, O_RDONLY); // O_RDONLY para leitura
    if (fd < 0) {
        perror("[reader] open FIFO");
        exit(EXIT_FAILURE);
    }

    printf("[reader] Conectado ao writer! Aguardando strings...\n\n");

    // Loop de recebimento e análise
    while (ler_string_fifo(fd, buf, MAX_BUF) >= 0) {
        // Verifica comando de encerramento
        if (strcmp(buf, CMD_SAIR) == 0) {
            printf("[reader] Comando de saída recebido. Encerrando.\n");
            break;
        }
        analisar_string(buf);
    }
 
    close(fd); // Fecha o FIFO
    unlink(FIFO_PATH); // Remove o FIFO do sistema de arquivos
    printf("[reader] Encerrado.\n");
    return 0;
}
