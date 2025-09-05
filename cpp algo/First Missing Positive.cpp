#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //vector<int> temp(n+1,0);
        bool one_cnt=false;
        
        for(auto x: nums){
            if(x == 1)
                one_cnt = true;
        }
        
        if(!one_cnt)
            return 1;
        
        int n = nums.size();
        
        if(n == 1){
            return 2;
        }
        
        for(int i=0; i<n; i++){
            
            if(nums[i] <= 0 || nums[i] > n )
                nums[i] = 1;
        }
        
        for(int i=0;i<n;i++){
            int x = abs(nums[i]);
            if(nums[x-1]>0)
                nums[x-1] *=-1;
        }
        
        for(int i=0; i<n;i++){
            if(nums[i] >0){
                return i+1;
            }
        }
        
        return n+1;
    }
};

int main() {
	vector<int> nums = {1,2,0};
	
	Solution sol;
	int val=0;
	val = sol.firstMissingPositive(nums);
	
	cout<<"val= "<<val<<"\n";
	
	return 0;
}