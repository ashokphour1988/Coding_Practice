class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n,true);
        if(n<=2){
            return 0;
        }
        vec[0]=false;
        vec[1]=false;
        for(int i=0; i<sqrt(n);i++){
            if(vec[i]){
                for(int j = i*i; j<n; j=j+i){
                    vec[j]=false;
                }
            }
        }
        return count(vec.begin(),vec.end(),true);
    }
};