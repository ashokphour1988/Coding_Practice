#include<stdio.h>
#include<string.h>
int main()
{
        char s1[20];
        int i;
        printf("Enter a string \n");
        gets(s1);
        for(i=0; s1[i]; i++)
        {
                if((s1[i] >='a')&&(s1[i]<='z') ||(s1[i] >='A') && (s1[i] <='Z'))
                        continue;
                else
                {
                        memmove(s1+i, s1+i+1, strlen(s1+i));
                        i--;
                }
        }
        printf("Modified String S1 : %s\n", s1);
}
