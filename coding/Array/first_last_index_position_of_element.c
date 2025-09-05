#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findmax(int a, int b){
    if(a>b)
        return a;

    return b;
}
int findmin(int a, int b){
    if(a<b)
        return a;

    return b;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int *p=(int*)malloc(sizeof(int)*2);
    memset(p,0,sizeof(int)*2);

    int i=0,j=0;
    int mid=numsSize/2;
    int min=0,max=0;
    int min_f=0,max_f=0;
    if(numsSize==0 ){
        p[0]=-1;
        p[1]=-1;
        *returnSize=2;
        return p;
    }
    if(nums[0]==target && nums[numsSize-1]==target){
        p[0]=0;
        p[1]=numsSize-1;
        *returnSize=2;
        return p;
    }

    for(i=0,j=numsSize-1;i<=mid,j>=mid;i++,j--){
        /*(min||min_f) -->> if min find on 0th index then it cann't go inside
        as min will be 0 for oth index so applying flag "min_f" cond as well*/
//printf("i=%d\tj=%d\tmin=%d\tmax=%d\n",i,j,min,max);
        if(nums[i]==target && (min||min_f)){
            if(nums[j]==target){
                if(!max_f)
                    max=j;
                else
                    max=findmax(max,j);
            }
            else{
                if(!max_f)
                    max=i;
                else
                    max=findmax(max,i);
            }
            
            max_f=1;
        }

        if(nums[j]==target && max){

            if(nums[i]==target){
                if(!min_f) /*applying condition for [5,7,7,8,8,10], t=8*/
                    min=i;
                else
                    min=findmin(min,i);
            }
            else{
                if(!min_f) /*applying condition for [5,7,7,8,8,10], t=8*/
                    min=j;
                else
                    min=findmin(min,j);
            }
                
            min_f=1;
        }
        /* when value find on 0th index then min=i means min will be zero so 
        avoiding start index updating again for input [1,1,3] and target=1*/
        if(nums[i]==target && min==0&&!min_f){
            min=i;
            min_f=1;
        }

        if(nums[j]==target && max==0){
            max=j;
            max_f=1;
        }

        //if(min_f&&max_f)/*for testcase [3,3,3] target=3*/
            //break;
    }
	
//printf("min=%d\tmin_f=%d\tmax=%d\tmax_f=%d\n",min,min_f,max,max_f);  

    if((!min_f&&!max_f) ){
        p[0]=-1;
        p[1]=-1;
    }
    else if(!min_f&&max_f){ 
        /*flag for dealing with [1,4] target=4 and [2,2] target=2*/
        p[0]=max;
        p[1]=max;
    }
    else if(min_f&&!max_f){ 
        /*dealing with [1,3] target=1*/
        p[0]=min;
        p[1]=min;
    }
    else{
        p[0]=min;
        p[1]=max;
    }

    *returnSize=2;
    return p;   
}

int main() {
   //int a[] = {1,2,2,1,1,0};
	//int a[] = {1,2,3,3,3,3,4,5,9};
	//int a[] = {0,0,0,1,2,3};
	int a[] = {0,1,2,3,4,4,4};
	int target=2;
	int *p;
	int val=0;
	int *retsize=&val;
	//int a[] = {1,1,1,2,2,3};
	int size=sizeof(a)/sizeof(a[0]);
	//p = applyOperations(a, size, retsize);
	p=searchRange(a, size, target, retsize);
	//printf("out=%d\n",out);
	for(int i=0;i<retsize[0];i++){
	    printf("%d\t",p[i]);
	}

    return 0;
}
