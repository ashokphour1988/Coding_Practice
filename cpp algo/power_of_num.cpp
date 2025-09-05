#include <iostream>
using namespace std;

int powernum(int n, int pow)
{	
	int res = n;
	if(pow == 0){
		return 1;
	}
	else if(pow == 1){
		return n;
	}
	else{
		for(int i=1; i<pow; i++){
			res = res*n;
		}
	}
	return res;
}

int main() {
	cout<<"power= "<<powernum(3, 4);
	return 0;
}