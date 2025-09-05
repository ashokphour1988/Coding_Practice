#include <stdio.h>
int *sort_array(int* nums, int numsSize)
{
    int i=0,j=0;
    int a=0;
    for (i = 0; i < numsSize; ++i) 
    {
        for (j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] > nums[j]) 
            {
                a =  nums[i];
                nums[i] = nums[j];
                nums[j] = a;
            }

        } 
    }
    return nums;
}  

int* targetIndices(int* nums, int numsSize, int target, int* returnSize){

    int i=0,j=0;
    int *p=NULL;

    for(i=0;i<numsSize;i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");
    
    nums = sort_array(nums, numsSize);

    for(i=0;i<numsSize;i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");
    
    for(i=0;i<numsSize;i++){
        
        if(nums[i]==target ){
            
            nums[j++]=i;
        }
    }

    p=(int*)malloc(sizeof(int)*j);
    memset(p,0,sizeof(int)*j);
    for(i=0;i<j;i++){
        p[i]=nums[i];
    }
    *returnSize=j;
    return p;   
}

int main() {
       //int a[] = {1,2,2,1,1,0};
	//int a[] = {1,2,3,3,3,3,4,5,9};
	//int a[] = {0,0,0,1,2,3};
	int a[] = {1,2,5,2,3};
	int target=3;
	int *p;
	int val=0;
	int *retsize=&val;
	//int a[] = {1,1,1,2,2,3};
	int size=sizeof(a)/sizeof(a[0]);
	//p = applyOperations(a, size, retsize);
	p=targetIndices(a, size, target, retsize);
	//printf("out=%d\n",out);
	for(int i=0;i<retsize[0];i++){
	    printf("%d\t",p[i]);
	}

    return 0;

    return 0;
}
