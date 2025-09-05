#include<stdio.h>
int main()
{
        int n,i,min,max,min_index =0, max_index = 0;
        int arr[10]= {5,7,1,10,23,17,19,20,11,-1};
        //printf("EnteranArray numbers\n");
        //for(i=0; i<10; i++)
        //        scanf("%d", arr+i);
        min = max = arr[0];
        for(i=1; i<10; i++)
        {
                if(arr[i] > max)
                {
                        max = arr[i];
                        max_index = i;
                }
                if(arr[i] < min)
                {
                        min = arr[i];
                        min_index = i;
                }
        }
        printf("max number = %d\t, max index = %d\n", max, max_index);
        printf("min number = %d\t, max index = %d\n", min, min_index);
}
