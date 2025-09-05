#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 3
#device MAX_SIZE_DATA 20
pthread_mutex_t mutex;
pthread_cond_t cond;
int result=0;

unsigned int data[MAX_SIZE_DATA] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int index=0;

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
	//printf("front=%d\trear=%d\n",front,rear);
	if((rear == MAX_SIZE && front == 0 ) || (rear%MAX_SIZE == front))  //(rear+1)%MAX_SIZE
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
    pthread_mutex_lock(&mutex);
    while(1){
			if(!is_full()/*&&(data-result) == 1)*/){
			printf("enqued: data = %d\tthread_id=%lu\n",data, pthread_self());
			enqueue(data[index]);
			index++;
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&mutex);
			if(index == MAX_SIZE_DATA)
					pthread_exit(0);
		}
		else{
			pthread_cond_wait(&cond, &mutex);
			pthread_cond_signal(&cond);
		}
    }
   
    return NULL;
}

void *myThreadFun2(void *arg)
{
	unsigned int data;	// = (unsigned int*)arg;
    pthread_mutex_lock(&mutex);
    while(1){
			if(!is_empty()){
			data = dequeue();
			printf("dequeued:  data = %d\tthread_id=%lu\n",data, pthread_self());
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&mutex);
			if(data == MAX_SIZE_DATA)
					pthread_exit(0);
		}
		else{
			pthread_cond_wait(&cond, &mutex);
			pthread_cond_signal(&cond);
		}
    }
   
    return NULL;
}

int main(void) {

	pthread_t thread_id[6];
	int i;
	printf("Before Thread\n");
   
    for(i=0;i<3;i++){
		pthread_create(&thread_id[i], NULL, myThreadFun1, (void*)data);
    }
	
	 for(i=0;i<3;i++){
		pthread_create(&thread_id[i], NULL, myThreadFun2, NULL);
    }
   
    for(i=0;i<6;i++){
		pthread_join(thread_id[i], NULL);
    }
   
	printf("After Thread\n");
    exit(0);

}