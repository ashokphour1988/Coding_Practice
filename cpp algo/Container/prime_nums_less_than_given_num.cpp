class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n,true);
        vec[0]=false;
        vec[1]=false;
        for(int i=2; i<sqrt(n);i++){
            if(vec[i]){
                for(int j = i*i; j<num; j=j+i){
                    vec[j]=false;
                }
            }
        }
        return count(vec.begin(),vec.end(),true)
    }
};




/*class Solution {
public:
    int countPrimes(int n) {
        int flag;
        int count=0;
        if(n==0 || n==1 || n==2)
            return count;
        count++; /* incrementing for 2 */
        for(unsigned int i=3; i<n; i++){
            flag=1;
            int j = i-1;
            while(j > 1 ){
                if(i%j == 0){
                    flag=0;
                    break;
                }
                j--;
            }
            if(flag)
                count++;
        }
        return count;
    }
};*/