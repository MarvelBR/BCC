/* Jantar dos Selvagens - Solução com Semáforos

Uma variação curiosa do problema dos produtores/consumidores foi proposta
em [Andrews, 1991] com o nome de Jantar dos Selvagens: uma tribo de selvagens está
jantando ao redor de um grande caldeirão contendo N porções de missionário cozido.
Quando um selvagem quer comer, ele se serve de uma porção no caldeirão, a menos
que este esteja vazio. Nesse caso, o selvagem primeiro acorda o cozinheiro da tribo e
espera que ele encha o caldeirão de volta, para então se servir novamente. Após encher
o caldeirão, o cozinheiro volta a dormir.

As restrições de sincronização deste problema são as seguintes:
• Selvagens não podem se servir ao mesmo tempo (mas podem comer ao mesmo
tempo);
• Selvagens não podem se servir se o caldeirão estiver vazio;
• O cozinheiro só pode encher o caldeirão quando ele estiver vazio.
*/

#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<semaphore.h>

#define NUM_SELVAGENS 5 // número de selvagens
#define NUM_PORCOES 10 // número de porções que o cozinheiro coloca no caldeirão quando ele enche

int porcoes = 0;

sem_t mutex, cald_cheio, cald_vazio;

void* cozinheiro (void* arg){
    int quantidade = *(int*)arg;
    while(1){
        sem_wait(&cald_vazio); // espera o caldeirão ficar vazio
        // encher_caldeirao()
        printf("Enchendo caldeirão\n");
        sleep(1);
        porcoes = quantidade; // o cozinheiro enche o caldeirão com a quantidade de porções definida
        sem_post(&cald_cheio); // sinaliza que o caldeirão está cheio
        printf("Dormindo\n");
        // dormir ()
    }
}

void* selvagem (void* arg){
    int id = *(int*)arg;

    while(1){
        sem_wait(&mutex);
        if (porcoes == 0){ // se o caldeirão estiver vazio, acorda o cozinheiro
            printf("Selvagem %d acordou o cozinheiro\n", id);
            sem_post(&cald_vazio); // sinaliza que o caldeirão está vazio para o cozinheiro
            sem_wait(&cald_cheio); // espera o cozinheiro encher o caldeirão
        }
        // servir_caldeirao()
        printf("Selvagem %d se serviu. Restam %d\n", id, porcoes - 1);
        porcoes--;
        sem_post(&mutex); // libera o mutex para que outros selvagens possam se servir
        printf("Selvagem %d comendo\n", id);
        // comer()
        sleep(1);
    }
}

int main(){
    pthread_t cozinheiro_thread;
    pthread_t selvagens[NUM_SELVAGENS]; // threads dos selvagens
    int ids[NUM_SELVAGENS]; // ids dos selvagens (1, 2, 3, 4, 5)

    sem_init(&mutex, 0, 1);
    sem_init(&cald_vazio, 0, 0);
    sem_init(&cald_cheio, 0, 0);

    int quantidade = NUM_PORCOES;
    pthread_create(&cozinheiro_thread, NULL, cozinheiro, &quantidade); // cria a thread do cozinheiro, passando a quantidade de porções que ele deve colocar no caldeirão

    for (int i = 0; i < NUM_SELVAGENS; i++){
        ids[i] = i + 1;
        pthread_create(&selvagens[i], NULL, selvagem, &ids[i]); // cria as threads dos selvagens, passando seus ids
    }
    
    pthread_join(cozinheiro_thread, NULL); // espera a thread do cozinheiro terminar (na prática, ela roda para sempre)
    for (int i = 0; i < NUM_SELVAGENS; i++){
        pthread_join(selvagens[i], NULL); // espera as threads dos selvagens terminarem (na prática, elas rodam para sempre)
    }

    return 0;
}
