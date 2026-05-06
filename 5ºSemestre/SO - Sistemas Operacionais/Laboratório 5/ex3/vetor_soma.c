/*
 Descrição: Soma de vetores usando memória compartilhada e pipes.
            O processo pai cria os vetores V1 e V2 em memória
            compartilhada (System V IPC) e distribui os intervalos
            de trabalho para os filhos via pipes. Cada filho soma
            V1[i]+V2[i] para o seu intervalo e armazena em V3.
            O pai aguarda todos os filhos e imprime o resultado.

 Autor: Erick Molina Gehring
 Data de criação: 05/05/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

// Estrutura armazenada na memória compartilhada

/*
 Layout da memória compartilhada (alocada de forma contígua):
   [  v1[0..n-1]  |  v2[0..n-1]  |  v3[0..n-1]  ]

 O ponteiro base retornado por shmat() é interpretado como int*.
 v1 = base + 0
 v2 = base + n
 v3 = base + 2*n
*/

// Intervalo de trabalho enviado pelo pai ao filho via pipe
typedef struct {
    int inicio; // índice inicial (inclusive)
    int fim;    // índice final   (exclusive)
} Intervalo;

/*
 Preenche um vetor com valores aleatórios entre 0 e 99.

 Entrada: v - ponteiro para o vetor
          n - número de elementos
 Saída: (nenhuma)
*/
static void inicializar_vetor_aleatorio(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;
}

/*
 Imprime até MAX_EXIBIR elementos de um vetor, seguido de "..." se houver mais.

 Entrada: nome - nome do vetor (para exibição)
          v - ponteiro para o vetor
          n - número total de elementos
 Saída: (nenhuma)
*/
static void imprimir_vetor(const char *nome, const int *v, int n)
{
    const int MAX_EXIBIR = 20; // Limite de elementos a exibir para evitar poluição visual
    printf("%s = [", nome);
    for (int i = 0; i < n && i < MAX_EXIBIR; i++) {
        printf("%d", v[i]);
        if (i < n - 1 && i < MAX_EXIBIR - 1)
            printf(", ");
    }
    if (n > MAX_EXIBIR)
        printf(", ... (%d elementos)", n);
    printf("]\n");
}

/*
 Determina o intervalo [inicio, fim) de índices que o
 filho de índice 'id' deve processar, distribuindo os
 elementos o mais uniformemente possível.

 Entrada: id - índice do filho (0-based)
          n - número total de elementos
          nfilhos - número total de filhos
 Saída: Intervalo com campos inicio e fim
*/
static Intervalo calcular_intervalo(int id, int n, int nfilhos)
{
    Intervalo iv;
    int base   = n / nfilhos;          // elementos base por filho */
    int sobra  = n % nfilhos;          // elementos extras

    // Os primeiros 'sobra' filhos recebem um elemento a mais
    // Exemplo: n=10, nfilhos=3 -> base=3, sobra=1
    // Filho 0: [0, 4) (4 elementos)
    // Filho 1: [4, 7) (3 elementos)
    // Filho 2: [7, 10) (3 elementos)
    if (id < sobra) {
        iv.inicio = id * (base + 1); 
        iv.fim    = iv.inicio + (base + 1);
    } else {
        iv.inicio = sobra * (base + 1) + (id - sobra) * base;
        iv.fim    = iv.inicio + base;
    }
    return iv;
}

// Processo filho
/*
 Lógica do processo filho. Lê o intervalo do pipe,
 acessa a memória compartilhada, realiza a soma e encerra.

 Entrada: fd_leitura - extremidade de leitura do pipe deste filho
          shmid      - ID do segmento de memória compartilhada
          n          - número total de elementos dos vetores
          id         - índice do filho (para log)
 Saída: (não retorna – chama exit())
*/
static void executar_filho(int fd_leitura, int shmid, int n, int id)
{
    Intervalo iv;
    ssize_t   lidos;

    // Aguarda o intervalo de trabalho enviado pelo pai
    lidos = read(fd_leitura, &iv, sizeof(Intervalo));
    if (lidos != (ssize_t)sizeof(Intervalo)) {
        fprintf(stderr, "[filho %d] Erro ao ler intervalo do pipe.\n", id);
        exit(EXIT_FAILURE);
    }
    close(fd_leitura);

    printf("[filho %d] Processando índices [%d, %d)...\n",
           id, iv.inicio, iv.fim);

    // Anexa à memória compartilhada
    int *base = (int *)shmat(shmid, NULL, 0);
    if (base == (int *)-1) {
        perror("[filho] shmat");
        exit(EXIT_FAILURE);
    }

    int *v1 = base;
    int *v2 = base + n;
    int *v3 = base + 2 * n;

    // Realiza a soma no intervalo designado
    for (int i = iv.inicio; i < iv.fim; i++)
        v3[i] = v1[i] + v2[i];

    // Desanexa a memória compartilhada
    shmdt(base);

    printf("[filho %d] Concluído.\n", id);
    exit(EXIT_SUCCESS);
}


// Main (processo pai)
int main(void)
{
    int n_elem, n_proc;

    // Lê parâmetros do usuário
    printf("Soma de vetores com memória compartilhada e pipes\n");
    printf("=================================================\n");
    printf("Número de elementos dos vetores: ");
    if (scanf("%d", &n_elem) != 1 || n_elem <= 0) {
        fprintf(stderr, "Número de elementos inválido.\n");
        exit(EXIT_FAILURE);
    }
    printf("Número de processos filhos    : ");
    if (scanf("%d", &n_proc) != 1 || n_proc <= 0) {
        fprintf(stderr, "Número de processos inválido.\n");
        exit(EXIT_FAILURE);
    }
    if (n_proc > n_elem) {
        fprintf(stderr, "Número de processos não pode ser maior que "
                        "o número de elementos.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n[pai] Configuração: %d elemento(s), %d processo(s) filho(s)\n",
           n_elem, n_proc);

    srand((unsigned)time(NULL));

    // 1. Cria memória compartilhada para V1, V2, V3
    size_t shm_size = (size_t)(3 * n_elem) * sizeof(int);
    int shmid = shmget(IPC_PRIVATE, shm_size, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("[pai] shmget");
        exit(EXIT_FAILURE);
    }
    printf("[pai] Memória compartilhada criada (shmid=%d, %zu bytes).\n",
           shmid, shm_size);

    // Anexa ao espaço de endereçamento do pai
    int *base = (int *)shmat(shmid, NULL, 0);
    if (base == (int *)-1) {
        perror("[pai] shmat");
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_FAILURE);
    }

    int *v1 = base;
    int *v2 = base + n_elem;
    int *v3 = base + 2 * n_elem;

    // Inicializa V1 e V2 com valores aleatórios; V3 fica zerado
    inicializar_vetor_aleatorio(v1, n_elem);
    inicializar_vetor_aleatorio(v2, n_elem);
    memset(v3, 0, (size_t)n_elem * sizeof(int));

    // 2. Cria pipes (um par por filho)
    // pipes[i][0] = leitura (filho); pipes[i][1] = escrita (pai)
    int (*pipes)[2] = malloc((size_t)n_proc * sizeof(*pipes));
    if (!pipes) {
        perror("[pai] malloc pipes");
        shmdt(base);
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_proc; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("[pai] pipe");
            // limpeza parcial
            for (int j = 0; j < i; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            free(pipes);
            shmdt(base);
            shmctl(shmid, IPC_RMID, NULL);
            exit(EXIT_FAILURE);
        }
    }
    printf("[pai] %d pipe(s) criado(s).\n", n_proc);

    // 3. Cria os processos filhos
    pid_t *pids = malloc((size_t)n_proc * sizeof(pid_t));
    if (!pids) {
        perror("[pai] malloc pids");
        exit(EXIT_FAILURE);
    }

    // Garante que o buffer de saída seja esvaziado antes do fork
    fflush(stdout);
    for (int i = 0; i < n_proc; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("[pai] fork");
            exit(EXIT_FAILURE);
        }
        if (pids[i] == 0) {
            // CÓDIGO DO FILHO
            // Fecha extremidades de escrita de todos os pipes
            for (int j = 0; j < n_proc; j++)
                close(pipes[j][1]);
            // Fecha extremidades de leitura dos outros filhos
            for (int j = 0; j < n_proc; j++) {
                if (j != i)
                    close(pipes[j][0]);
            }
            // Executa a lógica do filho (não retorna)
            executar_filho(pipes[i][0], shmid, n_elem, i);
        }
        // Pai fecha a extremidade de leitura deste pipe
        close(pipes[i][0]);
    }

    // 4. Envia intervalo de trabalho para cada filho via pipe
    printf("[pai] Distribuindo trabalho...\n");
    for (int i = 0; i < n_proc; i++) {
        Intervalo iv = calcular_intervalo(i, n_elem, n_proc);
        printf("[pai] Filho %d: índices [%d, %d) (%d elemento(s))\n",
               i, iv.inicio, iv.fim, iv.fim - iv.inicio);

        if (write(pipes[i][1], &iv, sizeof(Intervalo)) != sizeof(Intervalo)) {
            perror("[pai] write pipe");
        }
        close(pipes[i][1]); // fecha após enviar
    }

    // 5. Aguarda todos os filhos terminarem
    printf("[pai] Aguardando filhos...\n");
    for (int i = 0; i < n_proc; i++) {
        int status;
        pid_t pid = waitpid(pids[i], &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("[pai] Filho PID=%d concluído com sucesso.\n", (int)pid);
        } else {
            printf("[pai] Filho PID=%d terminou com erro (status=%d).\n",
                   (int)pid, WEXITSTATUS(status));
        }
    }

    // 6. Exibe resultado
    printf("\n===== Resultado =====\n");
    imprimir_vetor("V1", v1, n_elem);
    imprimir_vetor("V2", v2, n_elem);
    imprimir_vetor("V3", v3, n_elem);

    // Verifica soma (validação simples)
    int correto = 1;
    for (int i = 0; i < n_elem; i++) {
        if (v3[i] != v1[i] + v2[i]) {
            correto = 0;
            fprintf(stderr, "[pai] ERRO: V3[%d]=%d != V1[%d]+V2[%d]=%d\n",
                    i, v3[i], i, i, v1[i] + v2[i]);
        }
    }
    if (correto)
        printf("\n[pai] Verificação OK: V3 = V1 + V2 (todos os %d elementos).\n",
               n_elem);

    // 7. Limpeza
    shmdt(base);
    shmctl(shmid, IPC_RMID, NULL);
    free(pipes);
    free(pids);

    printf("[pai] Encerrado.\n");
    return 0;
}
