/*
  Faça um programa com N threads que localiza um valor em um vetor de inteiros. 
  O espaço de busca no vetor deve ser distribuído para as N threads.

  Autor:     Erick Molina Gehring
  Criação:   12/04/2026
  Atualização: 13/04/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Biblioteca para threads
#include <time.h>

// Estrutura para passar dados para as threads
typedef struct {
    int *vetor;      // Ponteiro para o vetor compartilhado
    int inicio;      // Índice de início da busca para esta thread
    int fim;         // Índice de fim 
    int alvo;        // Valor sendo procurado
    int id;          // Identificador da thread
} ThreadData;

// Variáveis globais para controle do resultado
int encontrado = -1;
pthread_mutex_t mutex_encontrado = PTHREAD_MUTEX_INITIALIZER; // Declara e inicializa um Mutex (Mutual Exclusion)
// Ele serve para garantir que, se duas threads acharem o valor ao mesmo tempo, elas não tentem escrever na variável encontrado simultaneamente


/*
 Função executada pelas threads para buscar um valor em um intervalo do vetor.

 Entrada:
    valor - ponteiro para estrutura ThreadData
 
 Saída: NULL
*/
void* buscar_valor(void* valor) {
    ThreadData* data = (ThreadData*)valor;
    for (int i = data->inicio; i < data->fim; i++) {
        // Checagem rápida para ver se outra thread já encontrou o valor
        if (encontrado != -1) return NULL;

        if (data->vetor[i] == data->alvo) {
            pthread_mutex_lock(&mutex_encontrado);
            // Double-check após adquirir o lock
            if (encontrado == -1) {
                encontrado = i;
                printf("Thread %d encontrou o valor %d na posicao %d\n", data->id, data->alvo, i);
            }
            pthread_mutex_unlock(&mutex_encontrado); // Libera o lock
            return NULL;
        }
    }
    return NULL;
}

/*
 Fluxo principal: inicializa o vetor, cria as threads e exibe o resultado.

 Entrada:
    argc - número de argumentos
    argv - [1] tamanho do vetor, [2] num de threads, [3] valor alvo

 Saída: 0 em caso de sucesso, 1 em erro
*/
int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Uso: %s <tamanho_vetor> <num_threads> <valor_alvo>\n", argv[0]);
        return 1;
    }

    int tamanho = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    int alvo = atoi(argv[3]);

    if (num_threads <= 0 || num_threads > tamanho) {
        fprintf(stderr, "Erro: número de threads inválido.\n");
        return 1;
    }

    // Alocação e inicialização do vetor
    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if (!vetor) {
        perror("Erro ao alocar vetor");
        return 1;
    }

    srand(time(NULL)); // Semente para geração de números aleatórios
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000; // Valores entre 0 e 999
    }

    pthread_t threads[num_threads]; // Array para armazenar os identificadores das threads
    ThreadData tdata[num_threads]; // Array para armazenar os dados de cada thread
    int chunk_size = tamanho / num_threads;

    // Criação das threads e divisão do trabalho
    for (int i = 0; i < num_threads; i++) {
        tdata[i].vetor = vetor;
        tdata[i].inicio = i * chunk_size;
        tdata[i].fim = (i == num_threads - 1) ? tamanho : (i + 1) * chunk_size; // Garante que a última thread pegue o restante do vetor
        tdata[i].alvo = alvo;
        tdata[i].id = i;
        pthread_create(&threads[i], NULL, buscar_valor, &tdata[i]); // Cria a thread para buscar o valor
    }

    // Aguarda a finalização das threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL); // Espera a thread terminar
    }

    if (encontrado != -1) {
        printf("Resultado: Valor %d encontrado no indice %d\n", alvo, encontrado);
    } else {
        printf("Resultado: Valor %d nao encontrado no vetor.\n", alvo);
    }

    free(vetor);
    return 0;
}