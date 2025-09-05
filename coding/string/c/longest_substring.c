#include <stdio.h>
#include <string.h>

int max (int a , int b){
    if(a>b)
        return a;
    else
        return b;
}

int lengthOfLongestSubstring(char *p, int len)
{
	int i=0,j=0;
	char visited[256] = {0,};
	int res=0,count=0;
	printf("str= %s\n",p);
	while(i<len){
		memset(visited, '0', len);
		for(j=0;j<len;j++){
			if(visited[p[j]] == 1)
			{
				break;
			}
			else{
				count++;
				visited[p[j]]=1;
			}
		}
		res = max(res,count);
		i++;
	}
	printf("res = %d\n",res);
}

int main(void) {
	char *str = "abcdefghiabc";
	
	int len = strlen(str);

	lengthOfLongestSubstring(str, len);
	
	return 0;
}