#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_function1(void *);
void *thread_function2(void *);
void semaphore_init();
void semaphore_destroy();
sem_t s1,s2;
int cond_var=0;

main()
{
   int res;
   char Arr1[6] = {'a','b','c','d','e','f'};
   int  Arr2[6] = {1,2,3,4,5,6};
   pthread_t t1,t2;
   semaphore_init();
   res=pthread_create( &t1, NULL, thread_function1, (void*)Arr1 );
   if (res != 0) 
   {
      printf("Creation of thread1 failed\n");
      exit(-1);
   }
   res=pthread_create( &t2, NULL, thread_function2, (void*)Arr2 );
   if (res != 0) 
   {
      perror("Creation of thread2 failed\n");
      exit(-1);
   }

   pthread_join( t1, NULL); 
   if (res != 0) 
    {
      printf("Joining of thread1 failed\n");
      exit(-1);
    }
   pthread_join( t2, NULL); 
   if (res != 0) 
    {
      printf("Joining of thread2 failed\n");
      exit(-1);
    }

   semaphore_destroy();
}

void *thread_function1(void *dummyPtr)
{
   int i=0;
   char *p=(char*)dummyPtr;
   printf("Thread number %ld\n", pthread_self());
   while(1)
	{
        if(cond_var==0)
            {
	    printf("%c",*(p+i));
            i++;
            cond_var=1;
	    sem_post(&s2);
            }
	else
            {
            sem_wait(&s1);	
            }
	if(i==6)
	    return NULL;
    }
}
void *thread_function2(void *dummyPtr)
{
   
   int i=0;
   int *p=(int*)dummyPtr;
   printf("Thread number %ld\n", pthread_self());
   while(1)
	{
        if(cond_var==1)
            {
			printf("%d",*(p+i));
            i++;
            cond_var=0;
			sem_post(&s1);
            }
	else
            {
            sem_wait(&s2);	
            }
			
			if(i==6)
			{
				return 	NULL;			
			}
        }
   
}
void semaphore_init()
{
	if((sem_init(&s1,0,0))==-1)
        {
        printf("semaphore1 init error\n");
	exit(-1);
        }
	if((sem_init(&s2,0,0))==-1)
        {
        printf("semaphore2 init error\n");
	exit(-1);
        }
}
void semaphore_destroy()
{
     if((sem_destroy(&s1))==-1)
	{
	printf("semaphore1 distroy error\n");
	exit(-1);
	}
       if((sem_destroy(&s2))==-1)
	{
	printf("semaphore2 distroy error\n");
	exit(-1);
	}
}


adp payrole provider

remote.com

oister in german

