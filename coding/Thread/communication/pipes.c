#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pipefd[2];

void* producer(void* arg) {
    char message[] = "Hello from producer";
    write(pipefd[1], message, sizeof(message));
    return NULL;
}

void* consumer(void* arg) {
    char buffer[128];
    read(pipefd[0], buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    pipe(pipefd);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    return 0;
}