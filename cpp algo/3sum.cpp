#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        unordered_set<int> set;
        unsigned int i,j,n;
        n = nums.size();
        
        sort(nums.begin(), nums.end());
        /*bool zeros = std::all_of(nums.begin(), nums.end(), [](int i) { return i==1; });
        if(zeros){
        	cout<< "all elemets are zero\n";
        }
        else{
        	cout<<"not zero\n";
        }*/
        
        for(i=0; i<n;i++){
		    
            if ( i!=0 && nums[i-1] == nums[i] )
                    continue;
            
             for(j=i+1; j<n;j++){
                
                int x = -(nums[i] + nums[j]);
                if(set.find(x) != set.end()){
                    //vector<int> vec = {nums[i],x,nums[j]} ;
                    output.push_back({nums[i],x,nums[j]});
                    while (j+1 < nums.size() && nums[j+1] == nums[j] )
                         ++j;
                }
				else{
					set.insert(nums[j]);
				}
				cout<< "size= "<<set.max_size()<<endl;
                set.clear();
                cout<< "again size= "<<set.max_size()<<endl;
            }
        }
        return output;
    }
};
int main() {
	class Solution sol;
	vector<int> vec = {-1,0,1,2,-1,-4};
	//vector<int> vec = {0,0,0};
	//vector<int> vec = {1,1,1};
	//vector<int> vec = {1,1,-2};
	//vector<int> vec = {-2,0,1,1,2};
	//vector<int> vec = {-2,0,0,2,2};
	vector<vector<int>> vvi;
	vvi = sol.threeSum(vec);
	
	vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
    	cout<<"[ ";
        for (col = row->begin(); col != row->end(); col++) {
            /*if(*col == x){
                
            }*/
            cout<<" "<<*col;
        }
        cout<<" ]"<<endl;
    }
	
	return 0;
}