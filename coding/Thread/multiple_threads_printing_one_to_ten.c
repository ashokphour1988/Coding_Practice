#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int result=0;

void *myThreadFun(void *arg)
{
unsigned int data = (unsigned int)arg;
    pthread_mutex_lock(&mutex);
    while(1){
		if((data-result) == 1){
			printf("results = %d\tthread_id=%lu\n",result, pthread_self());
			result++;
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&mutex);
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

pthread_t thread_id[10];
int i;
    printf("Before Thread\n");
   
    for(i=0;i<10;i++){
    pthread_create(&thread_id[i], NULL, myThreadFun, (void*)(i+1));
    }
   
    for(i=0;i<10;i++){
    pthread_join(thread_id[i], NULL);
    }
   
    printf("After Thread\n");
    exit(0);


return 0;
}