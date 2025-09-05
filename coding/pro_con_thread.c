#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define STRLEN 15

struct traveler{
	int id;
	int bagnum;
	int travtime;
	struct traveler *next;
}

struct traveler *queue;

int produced; // The total # of produced in the queue

pthread_mutext_t queue_lock;
pthread_cond_t prod, cons;

int prod_count=0;
int cons_count=0;

int timeout=0;

int CheckIn(){
		if(produced)
			return 1;
		else 
			return 0;
}

void *producerThread(void *args){
	
	struct traveler *trav = (struct traveler*)args;
	struct traveler *temp;
	
	pthread_mutex_lock(&queue_lock);
	produced++;
	pthread_cond_wait(&prod, &queue_lock);
	
	printf("Producer_thread id=%d\t bagnum=%d\t travtime=%d\n", queue->id, queue->bagnum, queue->travtime);
	
	temp = queue;
	queue = queue->next;
	free(temp);
    pthread_mutex_unlock(&queue_lock);
}

int Producer(int id, int numBags, int arrTime){
	
	int ret;
	pthread_t tid;
	
	struct traveler *trav = (struct traveler*)malloc(sizeof(struct traveler));
	trav->id = id;
	trav->bagnum = bagnum;
	trav->travtime = travtime;
	trav->next = NULL;

	if(queue!=NULL){
		struct traveler *temp = queue;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = trav;
	}
	else
		queue=trav;
	
	ret = pthread_create(&tid, NULL, producerThread, (void*)trav);
	prod_count++;
	if(ret == 0){
		printf("Producer_function id=%d\t arrTime=%d\t numBags=%d\t produced=%d\t thread_count=%d\n", id, arrTime, numBags, produced, prod_count);
		pthread_cond_signal(&cons);
		return 0;
	}
	else return -1;
}

void *consumerThread(void *arg){
	
	char *Name = (char*)arg;
	int i=0;
	while(1){
			if(i==20){
				printf("Consumer %s's service has completed!\n", Name);
                		pthread_exit(NULL);
			}
			
			if(timeout == 6){
				pthread_exit(NULL);
			}
			
			if(CheckIn()){
				pthread_mutex_lock(&queue_lock);
				pthread_cond_wait(&cons, &queue_lock);
				printf("Consumer_thread name=%s\t id=%d\t bagnum=%d\t travtime=%d\n", Name, queue->id, queue->bagnum, queue->travtime);
				i++;
				produced--;
				timeout=0;
				pthread_mutex_unlock(&queue_lock);
				pthread_cond_signal(&prod);
			}
			else{
				sleep(2);
				timeout++;
			}
	}
	
}

int Consumer(char *Name){
	
	int ret;
	pthread_t tid;
	
	sleep(3);
	
	ret = pthread_create(&tid, NULL, consumerThread, (void*)Name);
	cons_count++;
	if(ret == 0){
		printf("Consumer_function %s's service has begun and thread count= %d\n", Name, cons_count);
		return 0;
	}
	else return -1;
}

int main()
{

	int staff_check=0;
	int trav_check=0;	
	int id;
	int bagnum;
	int travtime;

	FILE *consumer_fp;
	FILE *producer_fp;

	char *staff_name = (char*)malloc(sizeof(char)*STRLEN);
	memset(staff_name, '\0', sizeof(char)*STRLEN);

	producer_fp = fopen("travellers.txt", "r");
	if (producer_fp == NULL) {
		printf("no such file.");
		return 0;
	}
	
	consumer_fp = fopen("staff.txt", "r");
	if (consumer_fp == NULL) {
		printf("no such file.");
		return 0;
	}

	staff_check = fscanf(consumer_fp, "%s", staff_name);
	trav_check = fscanf(producer_fp, "%d %d %d", &id, &bagnum, &travtime);
	
	while(1){
	
		K:
		if(staff_check==1){
			Consumer(staff_name);
			staff_check = fscanf(consumer_fp, "%s", staff_name);
			goto L;
		}
		L:
		if(trav_check==3){
			Producer(id, numBags, arrTime);
			trav_check = fscanf(producer_fp, "%d %d %d", &id, &bagnum, &travtime);
			goto K;
		}
		pthread_exit(NULL);
	}

}

go/ipcat pe ddr cornor--->>>> 

2.4

547 

