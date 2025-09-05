#include <stdio.h>

int find_max_pow_of_two ( int num){
	
	int pow2 = 1;
	
	if( num & num-1 == 0 ){
		return num;
	}
	
	while(1){
		if(pow2 < num)
			pow2 = pow2 << 1;
		else
			return pow2;
	}
}

int main(void) {
	int max_pow = 0;
	max_pow = find_max_pow_of_two ( 31 );
	printf("max_pow = %d\n", max_pow);
	return 0;
}