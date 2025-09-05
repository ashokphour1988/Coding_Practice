#if(0)

// input a character and search no of occurance in the string

#include<stdio.h>
int main()
{
        char str[20], ch;
        printf("Enter a string \n");
        gets(str);
        printf("Enter a character\n");
        scanf("%c", &ch);
        int i, count = 0;
        for(i=0; str[i]; i++)
        {
                if(str[i] == ch)
                count++;
        }
        printf("String =%s\n", str);
        printf("String = %c\n", ch);
        printf("Count of repeated character in a string = %d\n", count);
}

#endif



#if(0)


// Reverse the String
//
#include<stdio.h>
int main()
{
        char str[20],temp;
        int i,cnt=0;
        printf("Enter a string\n");
        gets(str);
        for(i=0; str[i]; i++);
        cnt = i;
        printf("cnt = %d\n", cnt);
        for(i=0; i<cnt/2; i++)
        {
                temp = str[i];
                str[i] = str[cnt -i -1];
                str[cnt -i -1] = temp;
        }
        printf("Reversed String = %s\n", str);
}
#endif

// Convert Lower Case to Upper Case
#include<stdio.h>
int main()
{
        char str[100];
        int i;
        printf("Enter a string\n");
        gets(str);
        for(i=0; str[i]; i++)
        {
                if((str[i] >='a')&&(str[i]<='z'));
                str[i] = str[i]-32;
        }
        printf("String = %s\n", str);
}