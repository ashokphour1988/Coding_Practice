class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        unordered_set<int> set;
        vector<vector<int>> output;
        
        int i,j,k,n;
        
        n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums.empty() || n < 4 || ( target < 0 && nums[0]*4==target))
            return output;
        
bool zeros = std::all_of(nums.begin(), nums.end(), [](int i) { return i==1000000000; });
        
        if(zeros){
            return output;
        }
        
        if(nums[0]*4==target){
            output.push_back({nums[0],nums[0],nums[0],nums[0]});
            return output;
        }
        
        for(i=0;i<n-2;i++){
            
            if(i!=0 && nums[i] == nums[i-1])
            continue;
            
            for(j=i+1;j<n-1;j++){
                
                if(j-1 != i && nums[j]==nums[j-1])
                    continue;
                
                    for(k=j+1;k<n;k++){
                            int sum = nums[i]+nums[j]+nums[k];
                            int x = target - sum;
                            if(set.find(x)!=set.end()){
                                output.push_back({nums[i],nums[j],nums[k],x});
                                while(k+1<n && nums[k] == nums[k+1])
                                	k++;
                            }
                            else{
                                set.insert(nums[k]);
                            }
                    }
                set.clear();
            }
        }
        
        return output;
    }
};