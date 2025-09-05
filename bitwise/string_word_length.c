#include <stdio.h>
#include <string.h>

int main(void) {
	char *str = "Mary had a little lamb";
	int len = strlen(str);
	int count=0;
	char *p = str;
	
	while(1){
		
		if(*p == ' ' || *p == '\0'){
			printf("count = %d\n",count);
			if(*p=='\0')
				break;
				
			count=0;
		}
		else{
			count++;
		}
		p++;
	}
	
	return 0;
}