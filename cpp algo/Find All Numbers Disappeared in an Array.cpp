class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int x = abs(nums[i]);
            if(nums[x-1] > 0){
                nums[x-1] *=-1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                vec.push_back(i+1);
            }
        }
        return vec;
           
    }
};


/***

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n

[4,3,2,7,8,2,3,1]

As 4 and 5 are missing so except 4 and 5 index all value will be converted to negative like [-4,-3,-2,-7,8,2,-3,-1]

***/