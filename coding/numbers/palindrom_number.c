#if(0)

// Palindrome Numbers//

#include<stdio.h>
int main()
{
        int n, r,sum = 0,temp = 0;
        printf("Enter a number\n");
        scanf("%d",&n);
        temp = n;
        while(n)
        {
                r = n%10;
                sum = sum*10+r;
                n = n/10;
        }
        n = temp;
        if(n == sum)
                printf("Palindrome Number = %d\n", sum);
        else
                printf("Not Palindrome Number = %d\n", sum);
}

#endif

#include<stdio.h>
int main()
{
        int i,n = 1000,r,temp;
        for(i=1; i<n; i++)
        {
                int sum = 0;
                temp = i;
                while(i)
                {
                        r = i%10;
                        sum = sum*10+r;
                        i= i/10;
                }
                i = temp;
                if(i == sum)
                        printf(" Palindrome Numbers = %d\n", sum);
        }
}