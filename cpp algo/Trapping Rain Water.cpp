//#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

/*
every element in array telling the height of baars and weidth on bar is 1, needs to find out how much water can be traped between bars.
input array and i th element telling height of ith  bar.

Stack approch: 
			when stack elements are in decreasing order then there is not be container but when incoming elements is begger than stack element
			then it will make container with previous elemnts then that water needs to take in account. 
			Length is distance between bars and hight will be minimum of 2 bigger bars.
			1) if elements in decresing order push into the stack
			2) if incoming elemts is bigger than stack elemnts then pick the top of stack on current variable
			3) if stack is empty then not any bar in left of that current bar so container in not enclose and needs to exit in this condition.
			4) if stack not empty then calculate then distance between incoming elemts index and stack top index (i-top-1)
			5) then calculate the minimum of stack top index elemts and incoming bar and substract the currret index element height
			6) multiply with distance and add inside answer then return answer.

*/


using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st, st1;
        int area =0;
        int len = height.size();
        
        for(int i=0;i<len;i++){
        	//cout<<"index= "<<i<<'\n';
        	if(1){
        		cout<<"index= "<<i<<'\n';
        		while(!st.empty()){
        			cout<<st.top()<<'\n';
        			st1.push(st.top());
        			st.pop();
        		}
        		cout<<"pusing values again to stack"<<'\n';
        		while(!st1.empty()){
        			st.push(st1.top());
        			st1.pop();
        		}
        	}
        	while(!st.empty() && height[st.top()] < height[i] ){
        		int cur = st.top();
        		st.pop();
        		if(st.empty()){
        			break;
        		}
        		int diff = i - st.top() -1;
        		area +=((minm(height[i],height[st.top()]) - height[cur])*diff);
        		
  //cout<<"area= "<<area<<"\theight[cur]= "<<height[cur]<<"\theight[i]= "<<height[i];
  //cout<<"\theight[st.top()] = "<<height[st.top()]<<"\tdiff= "<<diff<<'\n';
        	}
        	st.push(i);
        }
        return area;
    }
    
    unsigned int minm(unsigned int a, unsigned int b){
    	
    	return a<b?a:b;
    }
};
int main() {
	// your code goes here
	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution sol;
	int area = sol.trap(arr);
	
	cout << "area= "<<area<<'\n';
	return 0;
}


/*index= 0
pusing values again to stack
index= 1
0
pusing values again to stack
index= 2
1
pusing values again to stack
index= 3
2
1
pusing values again to stack
index= 4
3
pusing values again to stack
index= 5
4
3
pusing values again to stack
index= 6
5
4
3
pusing values again to stack
index= 7
6
4
3
pusing values again to stack
index= 8
7
pusing values again to stack
index= 9
8
7
pusing values again to stack
index= 10
9
8
7
pusing values again to stack
index= 11
10
8
7
pusing values again to stack
area= 6*/

