#include <stdio.h>

int main()
{
    unsigned char p1=2, p2=5, num =60, n=3;
    unsigned char temp1, temp2;
    // int p1=2, p2=5, num =862, n=3;
    //int temp1, temp2;
   
    temp1 = (num >> p1) & ((1U<<n)-1);
    temp2 = (num >> p2) & ((1U<<n)-1);
    
    temp1 = (temp1 << p2) | (temp2 << p1);
    
    num = (num & ~(((1U<<n)-1)<<p1)) & (num & ~(((1U << n)-1) << p2));
    
    num = num|temp1;
    printf("num = %d\n",num);
    return 0;
}
