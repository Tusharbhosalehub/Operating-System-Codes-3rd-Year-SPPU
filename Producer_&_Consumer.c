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
void* consumer(void* arg) {
    int item;
    for (int i = 0; i < *((int*)arg); i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Consume item
        item = buffer[out];
        printf("Consumer consumes item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}
int main() {
    int num_producers, num_consumers, num_iterations;

    printf("Enter the number of producers: ");
    scanf("%d", &num_producers);

    printf("Enter the number of consumers: ");
    scanf("%d", &num_consumers);

    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    pthread_t producers[num_producers];
    pthread_t consumers[num_consumers];

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer threads
    for (int i = 0; i < num_producers; i++) {
        pthread_create(&producers[i], NULL, producer, &num_iterations);
    }




