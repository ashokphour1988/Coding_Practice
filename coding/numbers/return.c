#include<stdio.h>
int *fun()
{
        int v = 5;
        //static int v = 5;
        printf("in Fun : &v =%ld\t V= %d\n", &v, v);
        return &v;
}
int main()
{
        int *
        p = fun();
        printf("value = %d\n", *p);
}
