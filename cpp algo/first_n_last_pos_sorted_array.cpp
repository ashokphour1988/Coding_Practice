#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left=0,right,start=0;
        int beg=-1,end=-1;
        right = nums.size()-1;
        
        if(nums.empty()){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        //cout<<"+++++++++  1 +++++++++++\n";
        while(right>=0 && left<right){
            int mid = left + ((right-left)/2);
            //cout<<"mid= "<<mid<<"\tleft= "<<left<<"\tright= "<<right<<"\n";
             if(left==right)
                break;
            
            if((mid-1)>=0 && (nums[mid-1]==target)){
                start = mid-1;
                break;
            }
            
            if(nums[mid]==target){
                start = mid;
                break;
            }
            
            if(((mid+1)<nums.size()) && (nums[mid+1]==target)){
                start = mid+1;
                break;
            }
            
            if(nums[mid] < target){
                left=mid+1;
            }
            else{
                right= mid-1;  
            }
            
        }
        int i = start;
        while( i>=0 && (nums[i] == target)){
            i--;
        }
        
        if(i!=start){
        	i++;
        	beg = i;
        	i = start;
        }
        
        while( i+1<nums.size() && (nums[i+1] == target)){
            i++;
        }
        
        if(i!=start){
        	end = i;
        }
        
        if(beg != end){
        	if(beg<0)
        		beg=start;
        	if(end<0)
        		end=start;
        		
        	res.push_back(beg);
            res.push_back(end);
        }
        else{
        	res.push_back(beg);
            res.push_back(end);
        }
        
        return res;
    }
};

int main() {
	Solution sol;
	//vector<int> vec = {1,1,3,4,5,5,5,5,5};
	vector<int> vec = {0,0,1,2,2};
	//vector<int> vec= {5,7,7,8,8,10};
	//vector<int> vec= {1};
	vector<int> out;
	int target=0;
 
	out = sol.searchRange(vec,target);
 
	for(auto i: out){
		cout<<i<<"\n";
	}
 
	return 0;
}