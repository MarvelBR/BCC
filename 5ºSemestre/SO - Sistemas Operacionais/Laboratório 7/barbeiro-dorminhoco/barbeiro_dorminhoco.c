/* Funcionalidade: Barbeiro Dorminhoco - Solucao com Monitores
Autor: Erick
Data: 20/05/2026

O problema do barbeiro dorminhoco descreve uma barbearia com um barbeiro,
uma cadeira de barbeiro e um número limitado de cadeiras de espera. Quando
não há clientes, o barbeiro dorme. Quando um cliente chega e o barbeiro está
dormindo, ele acorda o barbeiro e é atendido. Se o barbeiro está ocupado, o
cliente espera em uma cadeira livre. Se não houver cadeira disponível, o
cliente vai embora.

As restrições de sincronização deste problema são as seguintes:
• O barbeiro dorme quando não há clientes;
• Um cliente acorda o barbeiro quando chega e ele está dormindo;
• Apenas um cliente pode cortar o cabelo por vez;
• Clientes só esperam se houver cadeira livre na sala de espera;
• Clientes vão embora quando todas as cadeiras de espera estão ocupadas.
*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define NUM_CLIENTES 12
#define CADEIRAS_ESPERA 3

typedef struct {
    pthread_mutex_t mutex; // mutex para proteger o acesso ao estado compartilhado
    pthread_cond_t cliente_disponivel; // condição para acordar o barbeiro quando um cliente chega
    pthread_cond_t cliente_chamado[NUM_CLIENTES]; // condição para o cliente esperar até ser chamado para a cadeira do barbeiro
    pthread_cond_t corte_finalizado[NUM_CLIENTES]; // condição para o cliente esperar até o corte de cabelo ser finalizado

    int fila[NUM_CLIENTES]; // fila circular para os clientes esperando (armazenando seus ids)
    int inicio;
    int fim;
    int qtd_fila;
    int esperando; // número de clientes esperando na sala de espera

    int cliente_atual; // id do cliente atualmente sendo atendido (-1 se nenhum)
    int barbeiro_ocupado; // flag indicando se o barbeiro está ocupado (1) ou dormindo (0)
    int barbearia_aberta; // flag indicando se a barbearia está aberta (1) ou fechada (0)

    int chamado[NUM_CLIENTES]; // flags para indicar se cada cliente foi chamado para a cadeira do barbeiro (1) ou não (0)
    int finalizado[NUM_CLIENTES]; // flags para indicar se o corte de cabelo de cada cliente foi finalizado (1) ou não (0)
} MonitorBarbearia;

MonitorBarbearia barbearia;

void monitor_inicializar(void);
void monitor_destruir(void);
void monitor_entrar_fila(int id);
int monitor_proximo_cliente(void);
void monitor_finalizar_corte(int id);
void monitor_fechar_barbearia(void);
void* barbeiro(void* arg);
void* cliente(void* arg);

// Inicializa o monitor da barbearia, incluindo mutex, variáveis de condição e estado compartilhado.
void monitor_inicializar(void){
    pthread_mutex_init(&barbearia.mutex, NULL);
    pthread_cond_init(&barbearia.cliente_disponivel, NULL);

    for(int i = 0; i < NUM_CLIENTES; i++){
        pthread_cond_init(&barbearia.cliente_chamado[i], NULL);
        pthread_cond_init(&barbearia.corte_finalizado[i], NULL);
        barbearia.chamado[i] = 0;
        barbearia.finalizado[i] = 0;
    }

    barbearia.inicio = 0;
    barbearia.fim = 0;
    barbearia.qtd_fila = 0;
    barbearia.esperando = 0;
    barbearia.cliente_atual = -1;
    barbearia.barbeiro_ocupado = 0;
    barbearia.barbearia_aberta = 1;
}

// Libera os recursos usados pelo monitor da barbearia.
void monitor_destruir(void){
    pthread_mutex_destroy(&barbearia.mutex); // destrói o mutex
    pthread_cond_destroy(&barbearia.cliente_disponivel); // destrói a condição cliente_disponivel

    for(int i = 0; i < NUM_CLIENTES; i++){
        pthread_cond_destroy(&barbearia.cliente_chamado[i]); // destrói a condição cliente_chamado[i]
        pthread_cond_destroy(&barbearia.corte_finalizado[i]); // destrói a condição corte_finalizado[i]
    }
}

// Entrada do cliente no monitor: acorda o barbeiro, espera em uma cadeira livre ou vai embora.
void monitor_entrar_fila(int id){
    pthread_mutex_lock(&barbearia.mutex); // entra na região crítica para acessar o estado compartilhado

    if(!barbearia.barbeiro_ocupado && barbearia.qtd_fila == 0){ // se o barbeiro está dormindo e não há clientes na fila, acorda o barbeiro para atender este cliente
        barbearia.barbeiro_ocupado = 1;
        barbearia.cliente_atual = id;
        printf("Cliente %d chegou e acordou o barbeiro\n", id);
        pthread_cond_signal(&barbearia.cliente_disponivel); // sinaliza o barbeiro para acordar e atender este cliente
    }
    else if(barbearia.esperando < CADEIRAS_ESPERA){ // se há cadeiras de espera disponíveis, senta na fila
        barbearia.fila[barbearia.fim] = id;
        barbearia.fim = (barbearia.fim + 1) % NUM_CLIENTES;
        barbearia.qtd_fila++;
        barbearia.esperando++;
        printf("Cliente %d sentou na sala de espera. Esperando: %d\n", id, barbearia.esperando);
        pthread_cond_signal(&barbearia.cliente_disponivel); // sinaliza o barbeiro para acordar caso ele esteja dormindo, mesmo que este cliente vá esperar na fila

        while(!barbearia.chamado[id]){
            pthread_cond_wait(&barbearia.cliente_chamado[id], &barbearia.mutex); // espera ser chamado para a cadeira do barbeiro
        }
        barbearia.chamado[id] = 0;
        printf("Cliente %d foi chamado para a cadeira do barbeiro\n", id);
    }
    else{ // se não há cadeiras de espera disponíveis, o cliente vai embora
        printf("Cliente %d foi embora, pois a sala de espera está cheia\n", id);
        pthread_mutex_unlock(&barbearia.mutex); // libera o mutex antes de sair para evitar deadlock
        return;
    }

    while(!barbearia.finalizado[id]){ // espera o corte de cabelo ser finalizado
        pthread_cond_wait(&barbearia.corte_finalizado[id], &barbearia.mutex); // espera ser sinalizado que o corte de cabelo deste cliente foi finalizado
    }
    barbearia.finalizado[id] = 0;

    pthread_mutex_unlock(&barbearia.mutex); // libera o mutex para que outros clientes possam entrar ou o barbeiro possa atender o próximo cliente
    printf("Cliente %d saiu com o cabelo cortado\n", id);
}

// Retorna o próximo cliente para atendimento ou -1 quando a barbearia está fechada e vazia.
int monitor_proximo_cliente(void){
    pthread_mutex_lock(&barbearia.mutex); // entra na região crítica para acessar o estado compartilhado

    while(barbearia.cliente_atual == -1 && barbearia.qtd_fila == 0 && barbearia.barbearia_aberta){ // enquanto não houver cliente atual, fila vazia e barbearia aberta, o barbeiro dorme
        barbearia.barbeiro_ocupado = 0;
        printf("Barbeiro dormindo\n");
        pthread_cond_wait(&barbearia.cliente_disponivel, &barbearia.mutex); // espera ser acordado por um cliente
    }

    if(barbearia.cliente_atual == -1 && barbearia.qtd_fila == 0 && !barbearia.barbearia_aberta){ // se a barbearia estiver fechada e vazia, o barbeiro encerra
        pthread_mutex_unlock(&barbearia.mutex);
        return -1;
    }

    if(barbearia.cliente_atual == -1){ // se não houver cliente atual, pega o próximo da fila
        int id = barbearia.fila[barbearia.inicio];
        barbearia.inicio = (barbearia.inicio + 1) % NUM_CLIENTES;
        barbearia.qtd_fila--;
        barbearia.esperando--;
        barbearia.cliente_atual = id;
        barbearia.barbeiro_ocupado = 1;
        barbearia.chamado[id] = 1;
        pthread_cond_signal(&barbearia.cliente_chamado[id]); // sinaliza o cliente id para ir para a cadeira do barbeiro
    }

    int id = barbearia.cliente_atual;
    pthread_mutex_unlock(&barbearia.mutex); // sai da região crítica para permitir que outros clientes possam entrar ou o barbeiro possa atender o próximo cliente
    return id;
}

// Finaliza o corte do cliente atual e sinaliza que ele pode sair da barbearia.
void monitor_finalizar_corte(int id){
    pthread_mutex_lock(&barbearia.mutex); // entra na região crítica para acessar o estado compartilhado

    barbearia.cliente_atual = -1;
    barbearia.barbeiro_ocupado = 0;
    barbearia.finalizado[id] = 1;
    pthread_cond_signal(&barbearia.corte_finalizado[id]); // sinaliza o cliente id que seu corte de cabelo foi finalizado e ele pode sair da barbearia

    pthread_mutex_unlock(&barbearia.mutex); // sai da região crítica para permitir que outros clientes possam entrar ou o barbeiro possa atender o próximo cliente
}

// Fecha a barbearia depois que todos os clientes criados já chegaram.
void monitor_fechar_barbearia(void){
    pthread_mutex_lock(&barbearia.mutex);
    barbearia.barbearia_aberta = 0;
    pthread_cond_signal(&barbearia.cliente_disponivel);
    pthread_mutex_unlock(&barbearia.mutex);
}

// Rotina da thread do barbeiro: dorme sem clientes, corta cabelo e encerra ao fechar.
void* barbeiro(void* arg){
    (void)arg;

    while(1){
        int id = monitor_proximo_cliente(); // espera o próximo cliente ou -1 se a barbearia estiver fechada e vazia

        if(id == -1){
            break;
        }

        printf("Barbeiro cortando cabelo do cliente %d\n", id);
        sleep(1);
        printf("Barbeiro terminou o corte do cliente %d\n", id);
        monitor_finalizar_corte(id); // sinaliza que o corte do cliente id foi finalizado
    }

    printf("Barbeiro fechou a barbearia\n");
    return NULL;
}

// Rotina da thread do cliente: chega na barbearia e tenta ser atendido.
void* cliente(void* arg){
    int id = *(int*)arg;

    usleep((id % 4) * 200000); // clientes chegam em tempos diferentes para simular a chegada aleatória
    printf("Cliente %d chegou na barbearia\n", id);
    monitor_entrar_fila(id); // tenta entrar na fila, acordar o barbeiro ou ir embora se a sala de espera estiver cheia

    return NULL;
}

int main(){
    pthread_t barbeiro_thread;
    pthread_t clientes_threads[NUM_CLIENTES];
    int clientes_ids[NUM_CLIENTES];

    setbuf(stdout, NULL); // desativa o buffer de stdout para evitar problemas de sincronização na impressão
    monitor_inicializar(); // inicializa o monitor da barbearia

    pthread_create(&barbeiro_thread, NULL, barbeiro, NULL); // cria a thread do barbeiro

    for(int i = 0; i < NUM_CLIENTES; i++){
        clientes_ids[i] = i;
        pthread_create(&clientes_threads[i], NULL, cliente, &clientes_ids[i]); // cria as threads dos clientes, passando seus ids
    }

    for(int i = 0; i < NUM_CLIENTES; i++){
        pthread_join(clientes_threads[i], NULL); // espera as threads dos clientes terminarem (na prática, elas terminam depois de serem atendidos ou irem embora)
    }

    monitor_fechar_barbearia(); // sinaliza para o barbeiro que a barbearia está fechada depois que todos os clientes criados já chegaram
    pthread_join(barbeiro_thread, NULL); // espera a thread do barbeiro terminar depois de fechar a barbearia e atender os clientes restantes na fila

    monitor_destruir(); // libera os recursos usados pelo monitor da barbearia

    return 0;
}
