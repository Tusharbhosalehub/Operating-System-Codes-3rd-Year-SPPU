#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;
void* producer(void* arg) {
    int item;
    for (int i = 0; i < *((int*)arg); i++) {
        item = rand() % 100; // Generate a random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Produce item
        printf("Producer produces item: %d\n", item);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

