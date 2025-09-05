#if(0)

// An armstrong number is a number which equal to the sum of the cubes of its individual digits.
#include<stdio.h>
int main()
{
        int n,c,r,sum = 0,temp;
        printf("Enter a number\n");
        scanf("%d",&n);
        temp = n;
        while(n)
        {
                r = n%10;
                c = r*r*r;
                sum = sum+c;
                n = n/10;
        }
        n = temp;
        if(n == sum)
                printf("Arm_Strong Number =%d\n", sum);
        else
                printf("Non Arm-Strong Number = %d\n",sum);
}

#endif

#if(0)

// Arm strong numbers between 1 - 1000 numbers
//
#include<stdio.h>
int main()
{
        int i,n= 1000,c,r,temp;
        for(i=1; i<n; i++)
        {
                int s = 0;
                temp = i;
                while(i)
                {
                         r = i%10;
                         c = r*r*r;
                         s = s+c;
                         i = i/10;
                }
                i = temp;
                if(i == s)
                        printf("Arm Strong Number = %d\n", s);
        }
}

#endif