#include <stdio.h>
#include <stdlib.h>
 
/* C Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
    /* create stack to store leaders*/
    int* sk = (int*)malloc(size * sizeof(int));
    int top = -1;
    sk[++top] = arr[size - 1];
 
    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] >= sk[top]) {
            sk[++top] = arr[i];
        }
    }
 
    /* print stack elements*/
    /* run loop till stack is not empty*/
    while (top != -1) {
        printf("%d ", sk[top--]);
    }
    free(sk);
}
 
/* Driver program to test above function*/
int main()
{
    int arr[] = { 16, 17, 4, 3, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}


// An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. 
