#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<semaphore.h>

int porcoes = 0;

sem_t mutex, cald_cheio, cald_vazio;

void* cozinheiro (void* arg){
    int quantidade = *(int*)arg;
    while(1){
        // encher_caldeirao()
        printf("Enchendo caldeirão\n");
        sem_wait(&cald_vazio);
        porcoes = quantidade;
        sem_post(&cald_cheio);
        printf("Dormindo\n");
        // dormir ()
    }
}

void* selvagem (){
    while(1){
        sem_wait(&mutex);
        if (porcoes == 0){
            sem_post(&cald_vazio);
            sem_wait(&cald_cheio);
        }
        // servir_caldeirao()
        printf("Servindo caldeirão. Restam %d\n", porcoes);
        porcoes--;
        sem_post(&mutex);
        printf("Comendo\n");
        // comer()
    }
}

int main(){
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);
    sem_init(&cald_vazio, 0, 0);
    sem_init(&cald_cheio, 0, 0);

    int quantidade = 10;
    pthread_create(&t1, NULL, cozinheiro, &quantidade);
    pthread_create(&t2, NULL, selvagem, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}