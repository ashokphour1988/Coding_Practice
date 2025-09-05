#include <stdio.h>

int findmax(int a, int b){
    if(a>b)
        return a;
    return b;
}

int find_maxsum(int a[], int n, int k)
{
    int wsum=0;
    int msum=-99999999;
    
    
    for(int i=0;i<k;i++){
        msum += a[i];    
    }
    
    for(int i=k; i<n; i++){
        wsum = msum - a[i-k] + a[i];
        msum = findmax(msum, wsum);
    }
    
    return msum;
}

int main()
{
    int a[] = {2,9,31,-4,21,7};
    
    int size = sizeof(a)/sizeof(a[0]);
    int k=3;
    int msum = find_maxsum( a, size, k);
    printf("msum= %d\n",msum);
    return 0;
}


/*  

subarray pair based on k value if k=3

2,9,31 = 42
9,31,-4= 36

31,-4,21=48
-4,21,7=24

output= 48
*/