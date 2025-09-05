#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 3
#define MAX_SIZE_DATA 200
#define MAX_THREADS 1

void display();


pthread_mutex_t mutex;
pthread_cond_t pro, cons; // producer and consumer mutex conditional veriables
int result=0;

unsigned int data[MAX_SIZE_DATA]; // Array to pass to thread.
int my_index=0;

unsigned int a[MAX_SIZE];
int front=-1;
int rear = -1;

int is_empty()
{
	if((front == -1 && rear == -1))
		return 1;
	else
		return 0;
}

int is_full()
{
	if((rear == MAX_SIZE && front == 0 ) || (rear%MAX_SIZE == front))
		return 1;
	else
		return 0;
}

void enqueue(unsigned int data)
{
	if(is_empty()){
		front++;
		rear++;
	}
	else if(is_full()){
		printf("Overflow Queue Full\n");
		display();
		return;
	}
	else if((rear == MAX_SIZE) && ( rear%MAX_SIZE != front )){
		rear=0;
	}

	a[rear++] = data;
	//printf("front=%d\trear=%d\n",front,rear);
}

unsigned int dequeue()
{
	unsigned int data;
    if(is_empty()){
        printf("Underflow\n");
        return -1;
    }

	data = a[front];
	a[front] = 0;
	front++;
	//printf("front=%d\trear=%d\n",front,rear);
	if( front == rear){
		front=-1;
		rear=-1;
	}

	if(front == MAX_SIZE && (front%MAX_SIZE != rear))
		front=0;
	
	return data;
}

void display()
{
	int i;
	printf("##### available elements in queue #######\n");
	for(i=0;i<MAX_SIZE;i++)
			printf("data=%d\n",a[i]);
	printf("##################################\n");
}

void *myThreadFun1(void *arg)
{
	unsigned int *data = (unsigned int*)arg;
	int error;
	
    pthread_mutex_lock(&mutex);
	
    while(1){
        
		if(!is_full() || is_empty()/*&&(data-result) == 1)*/){
			printf("enqued: data = %d\tthread_id=%lu\n",data[my_index], pthread_self());
			enqueue(data[my_index]);
			my_index++;

			if(my_index == MAX_SIZE_DATA){
				printf("_____ myThreadFun2345  _____ \n ");
				pthread_cond_signal(&cons);
				pthread_mutex_unlock(&mutex);
				pthread_exit(0);
			}
		}
		else{
			printf("_____ myThreadFun11  _____ \n ");
			pthread_cond_signal(&cons);
			error = pthread_cond_wait(&pro, &mutex);
		}
    }
 
    return NULL;
}

void *myThreadFun2(void *arg)
{
	unsigned int data;      // = (unsigned int*)arg;
	printf("_____ myThreadFun2  _____ \n ");
    int error;
    pthread_mutex_lock(&mutex);
    while(1){
		if(!is_empty()){
			data = dequeue();
			printf("dequeued:  data = %d\tthread_id=%lu\n",data, pthread_self());
			
			if(data == MAX_SIZE_DATA){
				pthread_cond_signal(&pro);
				pthread_mutex_unlock(&mutex);
				pthread_exit(0);
			}
		}
		else{
			printf("_____ myThreadFun22222  _____ \n ");
			pthread_cond_signal(&pro);
			error = pthread_cond_wait(&cons, &mutex);
		}
	}

    return NULL;
}

int main(void) {

	pthread_t thread_id1[MAX_THREADS];
	pthread_t thread_id2[MAX_THREADS];
	int i;

	pthread_mutex_init(&mutex, NULL);


	// Initialize condition variables
	pthread_cond_init(&pro, NULL);
	pthread_cond_init(&cons, NULL);

	for(i=0;i<MAX_SIZE_DATA;i++){
			data[i]=i+1;
	}

    printf("Before Thread\n");

    for(i=0;i<MAX_THREADS;i++){
        pthread_create(&thread_id1[i], NULL, myThreadFun1, (void*)data);
    }
	
    for(i=0;i<MAX_THREADS;i++){
        pthread_create(&thread_id2[i], NULL, myThreadFun2, NULL);
    }

    for(i=0;i<MAX_THREADS;i++){
		pthread_join(thread_id1[i], NULL);
    }

   for(i=0;i<MAX_THREADS;i++){
		pthread_join(thread_id2[i], NULL);
    }

	printf("After Thread\n");
	
    exit(0);
}