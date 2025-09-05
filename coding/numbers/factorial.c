#include<stdio.h>
int main()
{
        int n, fact =1;
        printf("Enter a number\n");
        scanf("%d",&n);
        while(n)
        {
                fact = fact*n;
                n--;
        }
        printf("Factorial of n = %d\n", fact);
}
