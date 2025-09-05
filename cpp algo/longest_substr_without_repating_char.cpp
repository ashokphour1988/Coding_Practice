class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,n,res=0,count=0;
        
        
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
            res = max(res, count);
            count=0;
        }
        return res;
    }
};