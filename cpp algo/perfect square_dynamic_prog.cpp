#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1,0);
       for(int x=1; x<=n; ++x){
       	int min_val=x;
       	int y=1, sq=1;
       	cout<<"########### while loop starting ############\n";
       	while(sq<=x){
       		cout<<"x= "<<x<<"\tmin_val= "<<min_val<<"\ty= "<<y<<"\tsq= "<<sq<<"\t(1+dp[x-sq])= "<<1+dp[x-sq]<<"\n";
       		min_val = min(min_val, 1+dp[x-sq]);
       		y++;
       		sq = y*y;
       	}
       	dp[x] = min_val;
       	cout<<"__________________________________\n";
       	for(int i=0; i<=x; i++){
       		cout<<dp[i]<<"\n";
       	}
       }
       return dp[n];
    }
};

int main() {
	Solution sol;
	
	int num = sol.numSquares(13);
	
	cout<<"num = "<<num<<"\n";
	
	return 0;
}


/*
########### while loop starting ############
x= 1	min_val= 1	y= 1	sq= 1	(1+dp[x-sq])= 1
__________________________________
0
1
########### while loop starting ############
x= 2	min_val= 2	y= 1	sq= 1	(1+dp[x-sq])= 2
__________________________________
0
1
2
########### while loop starting ############
x= 3	min_val= 3	y= 1	sq= 1	(1+dp[x-sq])= 3
__________________________________
0
1
2
3
########### while loop starting ############
x= 4	min_val= 4	y= 1	sq= 1	(1+dp[x-sq])= 4
x= 4	min_val= 4	y= 2	sq= 4	(1+dp[x-sq])= 1
__________________________________
0
1
2
3
1
########### while loop starting ############
x= 5	min_val= 5	y= 1	sq= 1	(1+dp[x-sq])= 2
x= 5	min_val= 2	y= 2	sq= 4	(1+dp[x-sq])= 2
__________________________________
0
1
2
3
1
2
########### while loop starting ############
x= 6	min_val= 6	y= 1	sq= 1	(1+dp[x-sq])= 3
x= 6	min_val= 3	y= 2	sq= 4	(1+dp[x-sq])= 3
__________________________________
0
1
2
3
1
2
3
########### while loop starting ############
x= 7	min_val= 7	y= 1	sq= 1	(1+dp[x-sq])= 4
x= 7	min_val= 4	y= 2	sq= 4	(1+dp[x-sq])= 4
__________________________________
0
1
2
3
1
2
3
4
########### while loop starting ############
x= 8	min_val= 8	y= 1	sq= 1	(1+dp[x-sq])= 5
x= 8	min_val= 5	y= 2	sq= 4	(1+dp[x-sq])= 2
__________________________________
0
1
2
3
1
2
3
4
2
########### while loop starting ############
x= 9	min_val= 9	y= 1	sq= 1	(1+dp[x-sq])= 3
x= 9	min_val= 3	y= 2	sq= 4	(1+dp[x-sq])= 3
x= 9	min_val= 3	y= 3	sq= 9	(1+dp[x-sq])= 1
__________________________________
0
1
2
3
1
2
3
4
2
1
########### while loop starting ############
x= 10	min_val= 10	y= 1	sq= 1	(1+dp[x-sq])= 2
x= 10	min_val= 2	y= 2	sq= 4	(1+dp[x-sq])= 4
x= 10	min_val= 2	y= 3	sq= 9	(1+dp[x-sq])= 2
__________________________________
0
1
2
3
1
2
3
4
2
1
2
########### while loop starting ############
x= 11	min_val= 11	y= 1	sq= 1	(1+dp[x-sq])= 3
x= 11	min_val= 3	y= 2	sq= 4	(1+dp[x-sq])= 5
x= 11	min_val= 3	y= 3	sq= 9	(1+dp[x-sq])= 3
__________________________________
0
1
2
3
1
2
3
4
2
1
2
3
########### while loop starting ############
x= 12	min_val= 12	y= 1	sq= 1	(1+dp[x-sq])= 4
x= 12	min_val= 4	y= 2	sq= 4	(1+dp[x-sq])= 3
x= 12	min_val= 3	y= 3	sq= 9	(1+dp[x-sq])= 4
__________________________________
0
1
2
3
1
2
3
4
2
1
2
3
3
########### while loop starting ############
x= 13	min_val= 13	y= 1	sq= 1	(1+dp[x-sq])= 4
x= 13	min_val= 4	y= 2	sq= 4	(1+dp[x-sq])= 2
x= 13	min_val= 2	y= 3	sq= 9	(1+dp[x-sq])= 2
__________________________________
0
1
2
3
1
2
3
4
2
1
2
3
3
2
num = 2
*/