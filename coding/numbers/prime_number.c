#if(0)


// Whether it is PRime number or NOT /

#include<stdio.h>
int main()
{
        int i,n, flag = 0;
        printf("Enter a Positive number\n");
        scanf("%d", &n);
        for(i = 2; i<n; i++)
        {
                if(n%i == 0)
                {
                        flag = 1;
                        break;
                }
        }
        if(flag == 0)
                printf("Prime Number = %d\n", n);
        else
                printf("Not a Prime Number = %d\n",n);
}

#endif

#include<stdio.h>
int main()
{
        int i, j, n = 100;
        for(i = 2; i<n; i++)
        {
                for(j = 2; j<i; j++)
                {
                        if(i%j == 0)
                                break;
                }
                if(i == j)
                        printf("%d - Prime Number\n", i);
        }
}
