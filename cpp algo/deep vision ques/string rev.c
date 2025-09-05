#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = "deep vision systems hyd";
    char *p =str;
    
    int len = strlen(str);
    int i=0,j=0,left=0,right=0,newlen=0;
    int m=0;
    int count=0, prevcnt;
    char *res = (char*)malloc(len);
    memset(res,'\0',len);
    
    prevcnt = count;
    i=len-1;
    printf("len=%d\n",len);
    printf("%s\n",p);
    //for(i=len-1; i>=0; i--){
    while(1){
        
        if(p[i] == ' ' || i == -1){
        	printf("prevcnt = %d\tnewlen= %d\tcount=%d\n",prevcnt, newlen, count);
            left=prevcnt;
            right=j-1;
            //printf("k=%d\tl=%d\t",k,l);
            for(m = prevcnt; m< newlen; m++){
            	//printf("%c",res[m]);
            }
            //printf("\t");
            m=0;
            while(m<count/2){
                res[left] = res[left]^res[right];
                res[right] = res[left]^res[right];
                res[left] = res[left]^res[right];
                left++;
                right--;
                m++;
            }
            
            for(m = prevcnt; m< newlen; m++){
            	//printf("%c",res[m]);
            }
            //printf("\n");
            if(i == -1)
            	break;
            res[j++] = ' ';
            newlen++;
            prevcnt = newlen;
            count=0;
        }
        else{
            res[j++] = p[i];
            count++;
            newlen++;
            //printf("%c\t",res[i]);
        }
        i--;
    }
    printf("_____ 1 _____ \n");
    for(i=0; i<len; i++){
    	printf("%c",res[i]);
    }
    
}