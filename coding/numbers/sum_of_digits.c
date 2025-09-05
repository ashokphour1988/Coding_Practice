#if(0)

// count of a number

#include<stdio.h>
int main()
{
        int n, count = 0;
        printf("Enter a number \n");
        scanf("%d", &n);
        while(n)
        {
                count++;
                n = n/10;
        }
        printf("Count of a number = %d\n", count);
}

#endif

#if(1)

// Sum of a number

#include<stdio.h>
int main()
{
        int n, sum =  0, r;
        printf("Enter a number \n");
        scanf("%d", &n);
        while(n)
        {
                r = n%10;
                sum = sum+r;
                n = n/10;
        }
        printf("Sum of a Number = %d\n", sum);
}

#endif
