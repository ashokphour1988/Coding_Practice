#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int reductionCost(vector<int> num) {
    int cost=0;
    sort(num.begin(),num.end());
    int i=0; 
    while(num.size()>1){
     //cout<<"i= "<<i<<"\t"<<"size= "<<num.size()<<"\n";
     cost = num[i] + num[i+1];
     num.erase(num.begin(),num.begin()+2);
     num.push_back(cost);
     /*for(int j=0;j<num.size();j++){
    	cout<<"num= "<<num[j]<<"\n";
    	}*/
    }
    
    //cout<<"last size= "<<num.size()<<"\n";
    return num[0];
}
/*1,2,3,3

3,3,3
3,6
9
*/


int main() {
	//vector<int> vec = {3,1,2,3};
	vector<int> vec = {5,5,5,5};
	int cost=0;
	cost = reductionCost(vec);
	cout<<"cost= "<<cost<<"\n";
	return 0;
}