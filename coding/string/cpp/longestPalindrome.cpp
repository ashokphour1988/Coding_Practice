// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int i,len1,len2,len,prevlen=0;
        int start=0,end=0;
        int slen = s.size();
        
        if(s.empty() || s.length() < 1)
            return "";
            
        for(i=0;i<slen-1;i++){
            len1 = expandfrommiddle(s,i,i); // check odd substring is Palindrome or not
            len2 = expandfrommiddle(s,i,i+1); // check even substring
            
            len = max(len1,len2);
            
            if(len > (end-start) && len != prevlen ){
                //std::cout << "______ 1 ______";
                start = i - (len-1)/2;
                end = i + len/2;
                
                std::cout << "start=" << start << "\tend=" << end << "\ti="<<i << "\tlen="<<len;
                std::cout << "\n";
            }
            prevlen  = len;
        }
        
        return s.substr(start,len); // substr([position], [length]) --->>> to calculate the length from start and end position of substring --->>> end - start + 1 ( As array index start from 0 but length of substring will be actual length which start from 1)
    }
    
    int expandfrommiddle(string s,int left, int right){
        if(left>right)
            return 0;
        
        
        while(left >=0 && right<s.length() && s[left] == s[right] ){
            left--;
            right++;
        }
        return right-left-1; // subtracting -1 as during finding substring we moved one step ahead.
    }
};

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    
    Solution c;
    //string s = "adbab";
    string s = "oabbac";
    //c.longestPalindrome(s);
    cout << c.longestPalindrome(s);
    return 0;
}