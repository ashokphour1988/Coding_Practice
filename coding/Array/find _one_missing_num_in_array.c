#include <stdio.h>

// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++){
		printf("res = %d\n",res);
		res ^= arr[i];
	}
	return res;
}

// Driver Method
int main(void)
{
	int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The odd occurring element is %d ",
		findOdd(arr, n));
	return 0;
}


Find missing number:

#include <bits/stdc++.h>
using namespace std;
  
// Function to get the missing number
int getMissingNo(int a[], int n)
{
    // Given the range of elements
    // are 1 more than the size of array
    int N = n + 1;
    
    int total = (N) * (N + 1) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
  
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    
    // Function call
    int miss = getMissingNo(arr, N);
    cout << miss;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
  
// Function to get the missing number
int getMissingNo(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];
  
    // For xor of all the elements from 1 to n+1
    int x2 = 1;
  
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
  
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
  
    return (x1 ^ x2);
}
  
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    
    // Function call
    int miss = getMissingNo(arr, N);
    cout << miss;
    return 0;
}


