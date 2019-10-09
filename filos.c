#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FILOS   5
pthread_mutex_t tenedores[NUM_FILOS];

void actividad() {
    sleep(1 + rand()%5);
}

void * vida(void *id) {
    long tid;
    tid = (long)id;
    srand(tid + time(NULL));
    while(1) {

            //PENSAR
            printf("Soy el hilo %ld, estoy pensando.\n", tid);
            actividad();
        if(tid %2 == 0) {
            pthread_mutex_lock(&tenedores[tid]);
            pthread_mutex_lock(&tenedores[(tid+1)%NUM_FILOS]);
            printf("Soy el hilo %ld, estoy comiendo.\n", tid);
            actividad();
            pthread_mutex_unlock(&tenedores[tid]);
            pthread_mutex_unlock(&tenedores[(tid+1)%NUM_FILOS]);
        } else {
            pthread_mutex_lock(&tenedores[(tid+1)%NUM_FILOS]);
            pthread_mutex_lock(&tenedores[tid]);
            printf("Soy el hilo %ld, dejé de comer.\n", tid);
            actividad();
            pthread_mutex_unlock(&tenedores[(tid+1)%NUM_FILOS]);
            pthread_mutex_unlock(&tenedores[tid]);
        }
    }
}

int main() {
    pthread_t threads[NUM_FILOS];
    int rc;
    long t;
    for(t=0;t<NUM_FILOS;t++) {
        printf("In main, created philosopher #%ld\n", t);
        rc = pthread_create(&threads[t], NULL, vida, (void *)t);
        if(rc) {
            printf("ERROR");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}