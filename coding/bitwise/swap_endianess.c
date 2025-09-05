#include <stdio.h>

int swapendiness(int num){
    char *p = &num;
   
    printf("num=%x\n",num);
   
    int i,j,k,l;
   
   
    i= (num & 0xff);
    j= (num>>8 & 0xff );
    k= (num>>16 & 0xff);
    l= (num>>24 & 0xff);
   
    num = i<<24|j<<16|k<<8|l;
   
    printf("%x\t%x\t%x\t%x\n",i,j,k,l);    
    /*p[0] = p[0]^p[3];
    p[3] = p[0]^p[3];
    p[0] = p[0]^p[3];
   
    p[1] = p[1]^p[2];
    p[2] = p[1]^p[2];
    p[1] = p[1]^p[2];*/
   
    printf("num=%x\n",num);
    return 0;
}

int main()
{
    int num = 0x44332211;
    swapendiness(num);
   
    return 0;
}


######################

// Online C compiler to run C program online
#include <stdio.h>

// Remove duplicates from sorted array

// Given an integery array sorted in non-descreasing order, remove the duplicate such that each unique element only apperas once, then return the number of unique elements

// You can assume the numbers are all positive

// Examples:
// Input: [1, 1, 2]
// Output: [1, 2]
// Return: 2

// Input: [1, 1, 2, 2]
// Output: [1, 2]
// Return: 2

// Input: [1, 1, 1, 2, 2, 3, 4]
// Output: [1, 2, 3, 4]
// Return: 4
int max(int a, int b){
    //printf("%d\t%d\n",a,b);
    if(a>b)
        return a;
    return b;
}
int remove_duplicates(int* nums, int size){
   
    int a[5]={0,};
    int b[5]={0,};
    int i=0;
    int unique=0;
    for(i=0;i<size;i++){
           if(a[nums[i]] == nums[i]){
               b[nums[i]] +=1;
           }
           else{
                b[nums[i]] +=1;    
               a[nums[i]] = nums[i];
           }
           
    }
   
    for(i=0;i<size;i++){
        unique=max(unique,b[i]);
        //printf("unique= %d\n",unique);
   
    }
   
    for(i=0;i<size;i++){
     printf("%d\t",a[i]);          
    }
    //printf("\n");
    for(i=0;i<size;i++){
     //printf("%d\t",b[i]);          
    }
    //printf("\n");
    //printf("unique= %d\n",unique);
    //printf("\n");
    return unique;
}

int main() {
    int a[5] = {1,1,1,2,2};
    int unique=0;
    unique = remove_duplicates(a, 5);
    printf("unique= %d\n",unique);
    return 0;
}
