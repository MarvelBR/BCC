/*
 Gera um vetor de inteiros aleatórios e divide sua busca entre
 N processos filhos. Cada filho pesquisa um intervalo do vetor
 e exibe seu PID e as posições onde o valor foi encontrado.
 Se nenhum filho encontrar o valor, o pai exibe "não encontrado".

 Autor:     Erick Molina Gehring
 Criação:   03/04/2026
*/

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctime> // para time() - semente para rand()

// Valor máximo dos elementos gerados aleatoriamente
#define VALOR_MAXIMO 20

/*
 Preenche o vetor com valores inteiros aleatórios no intervalo [0, VALOR_MAXIMO).

 Entrada:
   vetor   - ponteiro para o vetor a ser preenchido
   tamanho - número de elementos do vetor

 Saída: void
*/
void gerar_vetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % VALOR_MAXIMO;
    }
}

/*
 Imprime os elementos do vetor na saída padrão.

 Entrada:
   vetor   - ponteiro para o vetor
   tamanho - número de elementos do vetor

 Saída: void
*/
void exibir_vetor(int* vetor, int tamanho) {
    printf("Vetor gerado: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n\n");
}

/*
 Lê os parâmetros do usuário, gera o vetor, cria N filhos para busca
 paralela e aguarda os resultados. Se nenhum filho encontrar o valor,
 o pai exibe mensagem de "não encontrado".

 Entrada:
   argc, argv - não utilizados (parâmetros lidos via stdin)

 Saída: 0 em caso de sucesso, 1 em caso de erro
*/
int main() {
    int tamanho_vetor, numero_filhos, valor_buscado;

    printf("Busca paralela em vetor \n");
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    if (tamanho_vetor <= 0) { // validação do tamanho do vetor
        fprintf(stderr, "Erro: tamanho deve ser positivo.\n");
        return 1;
    }

    printf("Número de filhos: ");
    scanf("%d", &numero_filhos);

    if (numero_filhos <= 0 || numero_filhos > tamanho_vetor) { // validação do número de filhos
        fprintf(stderr, "Erro: número de filhos deve estar entre 1 e %d.\n", tamanho_vetor);
        return 1;
    }

    printf("Valor a ser procurado: ");
    scanf("%d", &valor_buscado);

    // Gera e exibe o vetor com valores aleatórios
    srand((unsigned)time(nullptr));
    int* vetor = (int*)malloc(tamanho_vetor * sizeof(int));
    if (!vetor) {
        perror("Erro ao alocar memória (malloc)");
        return 1;
    }

    gerar_vetor(vetor, tamanho_vetor);
    exibir_vetor(vetor, tamanho_vetor);

    int tamanho_intervalo = tamanho_vetor / numero_filhos;  // Quantos elementos cada filho deve processar
    int resto = tamanho_vetor % numero_filhos; // Para distribuir o resto entre os primeiros filhos

    // Cria os N filhos, cada um responsável por um intervalo do vetor
    for (int i = 0; i < numero_filhos; i++) {
        // Distribui o resto entre os primeiros filhos 
        int indice_inicio = i * tamanho_intervalo + (i < resto ? i : resto); // Cálculo do índice de início considerando o resto
        int indice_fim = indice_inicio + tamanho_intervalo + (i < resto ? 1 : 0); // Cálculo do índice de fim considerando o resto

        pid_t pid_filho = fork();

        if (pid_filho < 0) {
            perror("Erro ao criar processo filho (fork)");
            exit(EXIT_FAILURE);
        }

        if (pid_filho == 0) {
            // Processo filho: busca o valor no intervalo [indice_inicio, indice_fim)
            int encontrou = 0;

            for (int j = indice_inicio; j < indice_fim; j++) {
                if (vetor[j] == valor_buscado) {
                    printf("Filho PID %d: valor %d encontrado na posição %d\n",
                           getpid(), valor_buscado, j);
                    fflush(stdout);
                    encontrou = 1;
                }
            }

            free(vetor);
            exit(encontrou ? EXIT_SUCCESS : EXIT_FAILURE);
        }
    }

    // Pai aguarda todos os filhos e verifica se algum encontrou o valor 
    int encontrado_global = 0;
    int status_filho;

    for (int f = 0; f < numero_filhos; f++) {
        wait(&status_filho);
        // Se algum filho encontrou o valor, marca encontrado_global como 1
        if (WIFEXITED(status_filho) && WEXITSTATUS(status_filho) == EXIT_SUCCESS) {
            encontrado_global = 1;
        }
    }

    if (!encontrado_global) {
        printf("Pai: valor %d não encontrado no vetor.\n", valor_buscado);
    }

    free(vetor);
    return 0;
}