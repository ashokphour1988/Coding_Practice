#include<stdio.h>
int main()
{
        int n,r,s = 0;
        printf("Enter a number\n");
        scanf("%d", &n);
        while(n)
        {
                r = n%10;
                s = s*10+r;
                n = n/10;
        }
        printf("Reverse of a number = %d\n", s);
}
