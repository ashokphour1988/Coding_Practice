#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

        int i,j,k;
        int maxlen=0,flag=0;
        char *ptr;
        
        for(i=0;i<s.size();i++){
            for(j=i;j<s.size();j++){
                flag=1;
                for(k=0;k<(j-i+1)/2;k++){
                    if(s[i+k] != s[j-k]){
                        flag = 0;
                    }
                }
                if(flag == 1 && (j-i+1)>maxlen){
                	ptr = &s[i];
                    maxlen = max(maxlen,(j-i+1));
                }
            }
        }
    
    char *ptr1 = new char[maxlen];
    for(i=0;i<maxlen;i++){
    	ptr1[i] = ptr[i];
    }
    
	return ptr1;	
    }
};
int main() {
	// your code goes here
	Solution sol;
	cout << "str = "<< sol.longestPalindrome("forgeeksskeegfor")<<'\n';
	return 0;
}