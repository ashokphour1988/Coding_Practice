#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){

    int *p;
    int count=0;
    int j=0;
    int x;
    for(int i=0; i<numsSize; i++){
        x=abs(nums[i]);
        printf("%d\n",nums[i]);
        if(nums[x-1]>=0){
            nums[x-1]*=-1;
            count++;
        }
        else{
            //printf("i=%d\t%d\n",i,nums[i]);
        }
    }
    
    printf("count=%d\tnumsSize=%d\n",count,numsSize);
    count = numsSize-count;
    p = (int*)malloc(sizeof(int)*count);
    *returnSize = count;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i] >=0 ){
            p[j++] = i+1; 
        }
    }
    return p;    
}

int main() {
    // Write C code here
    int nums[8] = {4,3,2,7,8,2,3,1};
    int size = sizeof(nums)/sizeof(nums[0]);
    int val=0;
    int* returnSize=&val;
    int *p;
    p = findDisappearedNumbers(nums, size, returnSize);
    
    for(int i=0; i<*returnSize;i++){
        printf("%d\n",p[i]);
    }

    return 0;
}
