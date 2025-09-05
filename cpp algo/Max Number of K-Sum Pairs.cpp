class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        
        int count=0,i=0,j=0;
        //k=1;
        sort(nums.begin(),nums.end());
        j = nums.size()-1;
        
        while(i<j){
            //compliment = k - nums[i];
            if( nums[i] + nums[j] == k){
                i++;
                j--;
                count++;
            }
            else if( nums[i] + nums[j] < k){
                i++;
            }
            if( nums[i] + nums[j] > k){
                j--;
            }
        }
        
        return count;
    }
};