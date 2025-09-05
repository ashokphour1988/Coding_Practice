#if(0)

#include<stdio.h>
int main()
{
        int arr[10],i;
        for(i=0; i<10; i++)
                arr[i] = rand()%100;
        for(i=0; i<10; i++)
                printf("%d ", *(arr+i));
        printf("\n");
}

#endif

#if(0)

#include<stdio.h>
int main()
{
        int arr[10],i;
        srand(getpid());
        for(i=0; i<10; i++)
                arr[i] = rand()%101;
        for(i=0; i<10; i++)
                printf("%d ", *(arr+i));
        printf("\n");
}

#endif

#include<stdio.h>

int main()
{
        int i,arr[10],max = arr[0];
        srand(time(0));
        for(i=0; i<10; i++)
        {
                arr[i] = rand()%100;
                printf("%d ", arr[i]);
                if(arr[i] > max)
                        max = arr[i];
        }
        printf("max = %d\n",max);
        printf("index = ");
        for(i=0; i<10; i++)
                if(arr[i] == max)
                        printf("%d ", i);
        printf("\n");
}
~
