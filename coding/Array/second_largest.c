#include <stdio.h>

int find_snd_larger(int a[], int size)
{
    int large=a[0];
    int snd_large= -1;
    printf("size=%d\n",size);
    for(int i=1; i<size; i++){
        
        if(a[i]>large)  {
            //printf("a[i]=%d\tlarge=%d\n",a[i],large);
            snd_large=large;
            large=a[i];
        }
        else if(a[i] > snd_large && snd_large!=large ){
            //printf("a[i]=%d\tlarge=%d\n",a[i],large);
            snd_large=a[i];
        }
    }
    printf("large=%d\n",large);
    return snd_large;
}

int main() {
    
    int a[] = {2,4,7,13,8,10,16,20,19};
    
    int size = sizeof(a)/sizeof(a[0]);
    
    int slarge = find_snd_larger(a,size);
    printf("slarge= %d\n",slarge);
    return 0;
}