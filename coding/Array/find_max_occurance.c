#include <bits/stdc++.h> 
using namespace std; 
  
int mostFrequent(int arr[], int n) 
{ 
    // Sort the array 
    sort(arr, arr + n); 
  
    // Find the max frequency using linear traversal 
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else
            curr_count = 1; 
        
        if (curr_count > max_count) { 
            max_count = curr_count; 
            res = arr[i - 1]; 
        } 
    } 
  
    return res; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = { 40,50,30,40,50,30,30}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << mostFrequent(arr, n); 
    return 0; 
} 

/*
Brute force O(n2)

#include <bits/stdc++.h> 
using namespace std; 
  
int mostFrequent(int* arr, int n) 
{ 
    // code here 
    int maxcount = 0; 
    int element_having_max_freq; 
    for (int i = 0; i < n; i++) { 
        int count = 0; 
        for (int j = 0; j < n; j++) { 
            if (arr[i] == arr[j]) 
                count++; 
        } 
  
        if (count > maxcount) { 
            maxcount = count; 
            element_having_max_freq = arr[i]; 
        } 
    } 
  
    return element_having_max_freq; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = { 40, 50, 30, 40, 50, 30, 30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << mostFrequent(arr, n); 
    return 0; 
} 






*/