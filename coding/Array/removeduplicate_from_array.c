#include <stdio.h>
 
// Function to remove duplicate elements
// This function returns new size of modified array.
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
 
    // To store index of next unique element
    int j = 1;
 
    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=0; i < n; i++)
        if (arr[i] != arr[j-1])
            arr[j++] = arr[i];
 
    return j;
}

// Driver code
int main()
{
    int arr[] =  {1,1,2,2};//{0,0,1,1,1,2,2,3,3,4,4,4,4};//{1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // removeDuplicates() returns new size of array.
    n = removeDuplicates(arr, n);
    printf("%d\n",n);
    // Print updated array
    for (int i=0; i<n; i++)
        printf("%d ",arr[i]);
 
    return 0;
}