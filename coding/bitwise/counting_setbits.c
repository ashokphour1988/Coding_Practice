#include <bits/stdc++.h>
using namespace std;
 
int BitsSetTable256[256];
 
// Function to initialise the lookup table 
void initialize() 
{ 
 
    // To initially generate the 
    // table algorithmically 
    BitsSetTable256[0] = 0; 
    for (int i = 0; i < 256; i++)
    { 
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2]; 
    } 
} 
 
// Function to return the count 
// of set bits in n 
int countSetBits(int n) 
{ 
    return (BitsSetTable256[n & 0xff] + 
            BitsSetTable256[(n >> 8) & 0xff] + 
            BitsSetTable256[(n >> 16) & 0xff] + 
            BitsSetTable256[n >> 24]); 
} 
 
// Driver code 
int main() 
{ 
    // Initialise the lookup table 
    initialize(); 
    int n = 9; 
    cout << countSetBits(n);
} 

#if 0

#include <bits/stdc++.h>
using namespace std;
 
// recursive function to count set bits
int countSetBits(int n)
{
    // base case
		unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
}
 
// driver code
int main()
{
    // get value from user
    int n = 9;
 
    // function calling
    cout << countSetBits(n);
 
    return 0;
}

#endif


#if 0



#endif