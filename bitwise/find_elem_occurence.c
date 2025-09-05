#include <stdio.h>
#include <string.h>

int main(void) {
	int a[] = {0,3,1,0,5,1,2,0,4,5};
	
	int size = sizeof(a)/sizeof(int);
	int i=0;
	int temp[sizeof(a)/sizeof(int)]={-1};
	
	for(i=0;i<size;i++){
		if(temp[a[i]] == -1){
			temp[a[i]] = 1;
		}
		else{
			temp[a[i]] += 1;
			//printf("___2 ___ i=%d   temp[a[i]]=%d\n",i,temp[a[i]]);
		}
	}
	
	for(i=0;i<size;i++){
		if(temp[i] <=1){
			//printf("____ 2222 ___temp[%d]= %d\n",i,temp[i]);
		}
		else if(temp[i] > 1){
			printf("%d\t is coming %d times\n",i,temp[i]);
		}
	}
	return 0;
}