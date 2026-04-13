/*
  Implemente um programa multithread com pthreads que calcule a média aritmética 
  de cada linha de uma matriz MxN e a média geométrica de cada coluna. 
  O programa suporta paralelização de funções e de dados.

  Autor:     Erick Molina Gehring
  Criação:   12/04/2026
  Atualização: 13/04/2026
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <math.h> // Biblioteca para funções matemáticas, como log e exp
#include <time.h> // Biblioteca para funções de tempo, usada para gerar números aleatórios
#include "matriz/matriz.h"

// Estrutura para passagem de parâmetros para as threads
typedef struct {
    int **matriz;       // Matriz de dados
    int inicio;         // Índice inicial (linha ou coluna)
    int fim;            // Índice final (exclusivo)
    int outra_dim;      // Dimensão oposta (colunas se inicio/fim forem linhas)
    double *resultados; // Vetor para armazenar os resultados
} ArgsThread;

/*
 Calcula a média aritmética das linhas em um intervalo específico.

 Entrada:
    arg - ponteiro para ArgsThread
  
 Saída: NULL
*/
void* calcular_media_aritmetica_linhas(void* arg) {
    ArgsThread* args = (ArgsThread*)arg;
    for (int i = args->inicio; i < args->fim; i++) {
        double soma = 0;
        for (int j = 0; j < args->outra_dim; j++) {
            soma += args->matriz[i][j];
        }
        // Média aritmética: soma / número de elementos
        args->resultados[i] = soma / args->outra_dim;
    }
    return NULL;
}

/*
 Calcula a média geométrica das colunas em um intervalo específico.
 Utiliza logaritmos para evitar overflow em produtos de muitos elementos.
 
 Entrada:
   arg - ponteiro para ArgsThread
 
 Saída: NULL
*/
void* calcular_media_geometrica_colunas(void* arg) {
    ArgsThread* args = (ArgsThread*)arg;
    for (int j = args->inicio; j < args->fim; j++) {
        double soma_log = 0;
        for (int i = 0; i < args->outra_dim; i++) {
            // Média geométrica: exp( (1/n) * sum(log(x_i)) )
            soma_log += log((double)args->matriz[i][j]);
        }
        args->resultados[j] = exp(soma_log / args->outra_dim);
    }
    return NULL;
}

/*
 Fluxo principal: gerencia leitura/geração da matriz, criação de threads
 e gravação dos resultados.
 
 Entrada:
   argc, argv - parâmetros de linha de comando

 Saída: 0 em sucesso, 1 em erro
*/
int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Uso: %s <num_threads> <arquivo_entrada> <arquivo_saida> [gerar M N]\n", argv[0]);
        return 1;
    }

    int qtd_threads = atoi(argv[1]);
    char* arquivo_entrada = argv[2];
    char* arquivo_saida = argv[3];

    // Opcional: Gera uma nova matriz aleatória se M e N forem fornecidos
    if (argc >= 6) {
        int M = atoi(argv[4]);
        int N = atoi(argv[5]);
        int** matriz_temp = create_matrix(M, N); // Cria uma matriz temporária para gerar os dados
        srand(time(NULL)); 
        generate_elements(matriz_temp, M, N, 100); // Popula a matriz com valores aleatórios entre 0 e 99
        write_matrix_to_file(arquivo_entrada, matriz_temp, M, N); // Salva a matriz gerada no arquivo de entrada
        printf("Matriz %dx%d gerada e salva em %s\n", M, N, arquivo_entrada);
    }

    int linhas, colunas;
    int** matriz = read_matrix_from_file(arquivo_entrada, &linhas, &colunas); // Lê a matriz do arquivo e obtém suas dimensões
    if (!matriz) {
        fprintf(stderr, "Erro ao ler matriz do arquivo %s\n", arquivo_entrada);
        return 1;
    }

    double* medias_arit_linhas = (double*)malloc(linhas * sizeof(double)); // Vetor para armazenar as médias aritméticas das linhas
    double* medias_geo_colunas = (double*)malloc(colunas * sizeof(double)); // Vetor para armazenar as médias geométricas das colunas

    // Paralelização de Funções e Dados:
    // Divide o pool de threads entre as duas funções de cálculo
    int threads_linhas = qtd_threads / 2;
    if (threads_linhas == 0) threads_linhas = 1;
    int threads_colunas = qtd_threads - threads_linhas;
    if (threads_colunas == 0) threads_colunas = 1;

    pthread_t *ids_threads = (pthread_t*)malloc((threads_linhas + threads_colunas) * sizeof(pthread_t)); // Array para armazenar os identificadores das threads
    ArgsThread *args_threads = (ArgsThread*)malloc((threads_linhas + threads_colunas) * sizeof(ArgsThread)); // Array para armazenar os argumentos de cada thread

    // Configuração das threads para linhas (Média Aritmética)
    int pedaco_linhas = linhas / threads_linhas;
    for (int i = 0; i < threads_linhas; i++) {
        args_threads[i].matriz = matriz;
        args_threads[i].inicio = i * pedaco_linhas;
        args_threads[i].fim = (i == threads_linhas - 1) ? linhas : (i + 1) * pedaco_linhas;
        args_threads[i].outra_dim = colunas;
        args_threads[i].resultados = medias_arit_linhas;
        pthread_create(&ids_threads[i], NULL, calcular_media_aritmetica_linhas, &args_threads[i]);
    }

    // Configuração das threads para colunas (Média Geométrica)
    int pedaco_colunas = colunas / threads_colunas;
    for (int i = 0; i < threads_colunas; i++) {
        int idx = threads_linhas + i; // Índice para as threads de colunas, após as de linhas
        args_threads[idx].matriz = matriz;
        args_threads[idx].inicio = i * pedaco_colunas;
        args_threads[idx].fim = (i == threads_colunas - 1) ? colunas : (i + 1) * pedaco_colunas;
        args_threads[idx].outra_dim = linhas;
        args_threads[idx].resultados = medias_geo_colunas;
        pthread_create(&ids_threads[idx], NULL, calcular_media_geometrica_colunas, &args_threads[idx]);
    }

    // Aguarda sincronização de todas as threads 
    for (int i = 0; i < (threads_linhas + threads_colunas); i++) {
        pthread_join(ids_threads[i], NULL);
    }

    // Gravação dos resultados no arquivo de saída
    FILE* arquivo_out = fopen(arquivo_saida, "w");
    if (!arquivo_out) {
        perror("Erro ao abrir arquivo de saída");
        return 1;
    }
    
    fprintf(arquivo_out, "Medias Aritmeticas das Linhas (M):\n");
    for (int i = 0; i < linhas; i++) fprintf(arquivo_out, "L[%d]: %.4f\n", i, medias_arit_linhas[i]);
    
    fprintf(arquivo_out, "\nMedias Geometricas das Colunas (N):\n");
    for (int j = 0; j < colunas; j++) fprintf(arquivo_out, "C[%d]: %.4f\n", j, medias_geo_colunas[j]);
    
    fclose(arquivo_out);
    printf("Resultados salvos com sucesso em: %s\n", arquivo_saida);

    // Limpeza de memória
    free(medias_arit_linhas);
    free(medias_geo_colunas);
    free(ids_threads);
    free(args_threads);

    return 0;
}
