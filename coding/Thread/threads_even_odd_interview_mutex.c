#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int i=0;

void *fun1(void *p)
{
    pthread_mutex_lock(&mutex);
    
    while(i < 10)
    {
        if(i%2 !=0)
        pthread_cond_wait(&cond,&mutex);
        printf("even=%d\n",i++);
        pthread_cond_signal(&cond);
    }
    
    pthread_mutex_unlock(&mutex);
}

void *fun2(void *p)
{
    
    pthread_mutex_lock(&mutex);
    
    while(i < 10)
    {
        if(i%2 !=1)
        pthread_cond_wait(&cond,&mutex);
    
        printf("odd=%d\n",i++);
        pthread_cond_signal(&cond);
    }
    
    pthread_mutex_unlock(&mutex);
}


int main()
{
    pthread_t tid1,tid2;
    
    pthread_create(&tid1,NULL,&fun1,NULL);
    pthread_create(&tid2,NULL,&fun2,NULL);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    //printf("Hello World");

    return 0;
}