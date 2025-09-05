#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int** returnSize){
    int i,j;
    printf("_____ 0 ____\n");
    for(i=0;i<numsSize;i++)
    {
    	printf("_____ 111111 ____\n");
        for(j=i+1;j<numsSize;i++)
        {
            if((nums[i]+nums[j]==target))
            {
                *(returnSize+0) = (int*)malloc(sizeof(int)*2);
                printf("_____ 1 ____ %u\n",(*(returnSize+0)+0);
                printf("_____ 1 ____ %u\n",(*(returnSize+0)+1));
                *(*(returnSize+0)+0)  = i;
                 *(*(returnSize+0)+1) = j;
                 printf("_____ 2 ____\n");
                return returnSize;
            }
        }
    }
     return returnSize;
}

int main(void) {
	// your code goes here
	int *returnSize;
	//int numsSize = 4;
	int nums[]={2,7,11,15};
	//int target = 9;
	twoSum(nums, 4, 9, &returnSize);
	 printf("_____ 3 ____ %u\n",(returnSize+0));
     printf("_____ 3 ____ %u\n",(returnSize+1));
      printf("_____ 3 ____ %u\n",*(returnSize+0));
     printf("_____ 3 ____ %u\n",*(returnSize+1));
	//printf("results = %d\t%d\n",*(returnSize+0),*(returnSize+1));
	//printf("hello world\n");
	free(returnSize);
	return 0;
}
