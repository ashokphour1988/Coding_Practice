#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        sort(candidates.begin(),candidates.end());
        
        vector<int> combination;
        combinationSum(candidates, target, 0, ans, combination);
        
        return ans;
    }
    
void combinationSum(vector<int>& candidates, int target, int begin, vector<vector<int> >& ans, vector<int>& combination){
    
        if(!target){
            ans.push_back(combination);
            return;
        }

        for(int i=begin; i<candidates.size() && target >= candidates[i]; i++ ){

            combination.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], i, ans, combination);
            combination.pop_back();
        }
    }
};

int main() {
	vector<int> vec = {2,3,6,7};
	int target=7;
	Solution sol;
	vector<std::vector<int> > vvi;
	vvi = sol.combinationSum(vec,target);
 
	vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
    	cout<<"[";
        for (col = row->begin(); col != row->end(); col++) {
            cout<<*col<<",";
        }
        cout<<"]\n";
    }
 
	return 0;
}