#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 10

typedef struct travs {
    int id;
    int numBags;
    int arrTime;
    struct travs *next;
} travs;


travs *queue;
//travs *servicing[MAX];

int produced; // The total # of produced in the queue

pthread_mutex_t queue_lock;
//pthread_mutex_t staff_lock;
pthread_cond_t ct, cs;

int CheckIn(){
    sleep(1);
    if(produced != 0) return 1;
    else return 0;
}

void *producerThread(void *args){
    travs *traveler = (travs *)args;
    // Acquire the mutex
    pthread_mutex_lock(&queue_lock);
    produced++;
//  pthread_cond_signal(&cs);
    pthread_cond_wait(&ct, &queue_lock);
    printf("Producer %d is now checked in at time %d.\n", queue->id, (1+queue-    >arrTime));
    queue = queue->next;
    pthread_mutex_unlock(&queue_lock);

    return;
}

int Producer(int id, int numBags, int arrTime){

    int ret;
    pthread_t ttid;
    travs *traveler = malloc(sizeof(travs));
    traveler->id = id;
    traveler->numBags = numBags;
    traveler->arrTime = arrTime;
    sleep(arrTime);
    pthread_mutex_lock(&queue_lock);
    if(queue != NULL) {
        travs *check_in = malloc(sizeof(travs));
        check_in = queue;
        while(check_in->next != NULL){
            check_in = check_in->next;
        }
        check_in->next = traveler;
    }
    else { queue = traveler; }
    pthread_mutex_unlock(&queue_lock);
    // Create a new traveler thread
    ret = pthread_create(&ttid, NULL, producerThread, (void *)traveler);

    // Check if thread creation was successful
    if(ret == 0) {
        printf("Producer %d has entered the check-in line at time %d; s/he is at     position %d and has %d bags.\n", id, arrTime, produced, numBags);
        pthread_cond_signal(&cs);
        return 0;
    }
    else return -1;

}


void *consumerThread(void *arg){

    int i = 0; // travelers serviced
    char *name = (char *)arg;
    while(1) { // run iteratively

        // If 20 producers have been served, the consumer's work is done.
        if(i == 20) {
            printf("Consumer %s's service has completed!\n", name);
                pthread_exit(NULL);
            }
        // Sleep for 10s if 5 travelers have been checked in
        if (((i+1) % 5) == 0) {
                // Wake up sleeping travelers
                printf("Consumer %s is taking a break.\n", name);
                sleep(2);
                printf("Consumer %s's break is over.\n", name);
        }

        if(CheckIn()) {
            pthread_mutex_lock(&queue_lock);
            int j = 1;
                    pthread_cond_wait(&cs, &queue_lock);
                    printf("Producer %d presents ticket to consumer     %s.\n", queue->id, name);
                    printf("Consumer %s gives boarding pass to producer     %d.\n", name, queue->id);
                    while(j <= queue->numBags){
                        printf("Consumer %s checks in bag %d for producer %d; baggage tag is _X_.\n", name, j, queue->id);
                        j++;
                }
            // Signal producer being serviced that their check in is complete.
            i++;
            pthread_mutex_unlock(&queue_lock);
            produced--;
            pthread_cond_signal(&ct);
        }
    sleep(3);
    }
}

int Consumer(char *Name) {

    sleep(5);
    int ret;
    pthread_t stid;
    // Create a staff thread

    ret = pthread_create(&stid, NULL, consumerThread, (void *)Name);
    // Acquire the lock
    if(ret == 0) {
        printf("Producer %s's service has begun!\n", Name);
        return 0;
    }
    else    return -1;
}

int main() {
    int ret = 0;
    char *staff_name = malloc(sizeof(char));
    int staff_check = 0;
    int trav_check = 0;
    int id;
    int bagnum;
    int travtime;
    FILE *consumer_fp;
    FILE *producer_fp;
    queue = malloc(sizeof(travs));
    queue = NULL;
    /*while(ret < 10){
        servicing[ret] = malloc(sizeof(travs));
        servicing[ret] = NULL;
    }*/

    // Initilize mutexes
    pthread_mutex_init(&queue_lock, NULL);
    //pthread_mutex_init(&staff_lock, NULL);

    // Initialize condition variables
    pthread_cond_init(&ct, NULL);
    pthread_cond_init(&cs, NULL);

    // Open the file so we can start reading from it

    consumer_fp = fopen("staff.txt", "r");
    producer_fp = fopen("travelers.txt", "r");

    staff_check = fscanf(consumer_fp, "%s", staff_name);
    trav_check = fscanf(producer_fp, "%d %d %d", &id, &bagnum, &travtime);
    while(1){

        K:
        while(staff_check == 1) {
            Consumer(staff_name);
            staff_check = fscanf(consumer_fp, "%s", staff_name);
            goto L;
        }
        L:
        while(trav_check == 3) {
            Producer(id, bagnum, travtime);
            trav_check = fscanf(producer_fp, "%d %d %d", &id, &bagnum,     &travtime);
            goto K;
        }

    pthread_exit(NULL);
    }

}


cs goal is not just anumber
ab/ib expectation at what cornore/thershold a particular bus should run --->>> interconnetc
bus pm expectation ---->>>>> bus bandwidth

if not meeting cs goal then needs to check what changes and if that changes can impact on the power.