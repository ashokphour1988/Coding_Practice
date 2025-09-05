#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t mutex;
  
void* thread(void* arg)
{
	unsigned int data = (unsigned int*)arg;
    //wait
    sem_wait(&mutex);
    printf("\nEntered..thread = %lu\tdata=%d\n",pthread_self(),data);
  
    //critical section
    sleep(4);
      
    //signal
    printf("\nJust Exiting...thread = %lu\tdata=%d\n",pthread_self(),data);
    sem_post(&mutex);
}
  
  
int main()
{
	int i=10,j=20;
	// value 0 means no semaphore cann't enter in critical region and will wait on semaphore untill semphore is not signaled
	// value 1 means only one process can enter in critical region and upcoming process will wait on semaphore untill semohore is not signaled.
    sem_init(&mutex, 0, 0); 
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,&i);
    sleep(2);
    pthread_create(&t2,NULL,thread,&j);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}