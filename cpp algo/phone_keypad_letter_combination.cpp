#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        vector<string> vec;
        string table[10] = { "0",   "1",   "abc",  "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz" };
        
        int n = digits.size();
        
        //cout<<"n= "<<n<<"\tsize= "<<digits.size()<<"\n";
        
        q.push("");
        
        if(q.empty()){
        	cout<<"empty queue\n";
        }
        cout<<"___ 1 ___ \n";
        while(!q.empty()){
            
            string s= q.front();
            
            
            q.pop();
            cout<<"___ 2 ____\n";
            if(s.length() == n){
            	cout<<"___ 3 ____\n";
                vec.push_back(s);
            }
            else{
            	//cout<<"str = "<<s<<"\t"<<"length = "<<s.length()<<"\tdigit = "<<digits[s.length()]<<"\n";
            	cout<<"table = "<<table[int(digits[s.length()]-48)]<<'\n';
                for(auto letter : table[int(digits[s.length()]-48)] ){
                	cout<<"___ 4 ____\n";
                    q.push(s+letter);
                }
            }
        }
        return vec;
    }
};
 
// Driver code
int main()
{
    //int number[] = { 2, 3 };
    //int n = sizeof(number) / sizeof(number[0]);
	string s = "23";
	vector<string> vec;
    // Function call
    Solution sol;
    vec = sol.letterCombinations(s);
    
    for(auto v : vec){
    	cout<< v << "\n";
    }
    
 
    return 0;
}