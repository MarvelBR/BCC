/* Funcionalidade: Jantar dos Filosofos - Solucao com Semaforos
Autor: Erick
Data: 19/05/2026

O problema pode ser colocado de maneira bastante simples, 
como a seguir: cinco filósofos estão sentados em torno de uma mesa circular. 
Cada filósofo tem um prato de espaguete. O espaguete é tão
escorregadio que um filósofo precisa de dois garfos para
comê-lo. Entre cada par de pratos há um garfo.

A vida de um filósofo consiste em alternar períodos de
alimentação e pensamento. (Trata-se de um tipo de abs-
tração, mesmo para filósofos, mas as outras atividades
são irrelevantes aqui.) Quando um filósofo fica suficien-
temente faminto, ele tenta pegar seus garfos à esquerda
e à direita, um de cada vez, não importa a ordem. Se for
bem-sucedido em pegar dois garfos, ele come por um
tempo, então larga os garfos e continua a pensar. A ques-
tão fundamental é: você consegue escrever um programa
para cada filósofo que faça o que deve fazer e jamais fi-
que travado? (Já foi apontado que a necessidade de dois
garfos é de certa maneira artificial; talvez devamos trocar
de um prato italiano para um chinês, substituindo o espa-
guete por arroz e os garfos por pauzinhos.)

*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define N 5 /* numero de filosofos */
#define PENSANDO 0 /* o filosofo esta pensando */
#define FOME 1 /* o filosofo esta tentando pegar garfos */
#define COMENDO 2 /* o filosofo esta comendo */

int estado[N]; /* estado de cada filosofo */
sem_t mutex; /* semaforo para exclusao mutua */
sem_t S[N]; /* semaforo para cada filosofo */

void testar(int n);
void pegar_garfos(int n);
void largar_garfos(int n);

/* Rotina da thread de cada filosofo. Recebe o id do filosofo por ponteiro e alterna entre pensar, pegar garfos, comer e largar garfos. */
void* filosofos (void* arg){
    int n = *(int*)arg; // numero do filosofo
    while(1){
        printf("Filósofo %d pensando\n", n);
        sleep(1);

        pegar_garfos(n); // pega 2 garfos ou bloqueia

        printf("Filósofo %d comendo\n", n);
        sleep(1);

        largar_garfos(n); // devolve os garfos
    }

    return NULL;
}

/* Tenta pegar os dois garfos do filosofo n. Bloqueia no semaforo individual se algum vizinho estiver comendo. */
void pegar_garfos (int n){
    sem_wait(&mutex); // entra na regiao critica
    estado[n] = FOME; // registra que o filosofo esta com fome
    printf("Filósofo %d com fome\n", n);
    testar(n); // tenta pegar os garfos
    sem_post(&mutex); // sai da regiao critica
    sem_wait(&S[n]); // bloqueia se os garfos nao foram pegos
}

/* Devolve os garfos do filosofo n e testa se os vizinhos bloqueados podem comer. */
void largar_garfos (int n){
    int ESQUERDA = (n+N-1)%N;
    int DIREITA = (n+1)%N;

    sem_wait(&mutex); // entra na regiao critica
    estado[n] = PENSANDO; // registra que o filosofo esta pensando (acabou de comer)
    printf("Filósofo %d largou os garfos\n", n);
    testar(ESQUERDA); // ve se o vizinho da esquerda pode comer
    testar(DIREITA); // ve se o vizinho da direita pode comer
    sem_post(&mutex); // sai da regiao critica
}

/* Verifica se o filosofo n pode passar para o estado COMENDO sem conflito com seus vizinhos. */
void testar (int n){
    int ESQUERDA = (n+N-1)%N;
    int DIREITA = (n+1)%N;

    if (estado[n] == FOME && estado[ESQUERDA] != COMENDO && estado[DIREITA] != COMENDO){
        estado[n] = COMENDO; // registra que o filosofo esta comendo
        sem_post(&S[n]); // acorda o filosofo n, se ele estava bloqueado
    }
}

/* Inicializa os semaforos, cria as threads dos filosofos e aguarda sua execucao. */
int main(){
    pthread_t filosofos_threads[N]; // threads dos filosofos
    int filosofos_ids[N]; // ids dos filosofos (0, 1, 2, 3, 4)

    setbuf(stdout, NULL); // desativa o buffer de stdout para evitar problemas de sincronizacao na impressao

    sem_init(&mutex, 0, 1); // inicializa o semaforo mutex para exclusao mutua
    for(int i = 0; i < N; i++){ // inicializa o estado dos filosofos e os semaforos individuais
        estado[i] = PENSANDO;
        sem_init(&S[i], 0, 0);
    }

    for(int i = 0; i < N; i++){ // cria as threads dos filosofos
        filosofos_ids[i] = i;
        pthread_create(&filosofos_threads[i], NULL, filosofos, &filosofos_ids[i]);
    }

    for(int i = 0; i < N; i++){ // espera as threads dos filosofos terminarem (na pratica, elas rodam para sempre)
        pthread_join(filosofos_threads[i], NULL);
    }

    return 0;
}
