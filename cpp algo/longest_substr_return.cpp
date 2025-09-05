#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string lengthOfLongestSubstring(string s) {
        int i,j,n,res=0,count=0;
        int start=0;
        
        n = s.size();
        for(i=0; i<n; i++){
            vector<bool> visited(256);
            for(j=i; j<n; j++){
                if(visited[s[j]] == true){
                    break;
                }
                else{
                    count++;
                    visited[s[j]] = true;
                }
            }
            if(count>res){
            	res = count;
            	start=i;
            }
            //res = max(res, count);
            count=0;
        }
        return s.substr(start,res);
    }
};

int main()
{
	string s = "aabcdeffgh";
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s)<<'\n';
	return 0;
}
