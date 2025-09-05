#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = "deep vision systems hyd";
    char *p = str;
    int len = strlen(str);
    
    int i=0,j=0,k=0,l=0, m=0;
    int count=0, prevcnt;
    
    char *res = (char*)malloc(len+1);
    memset(res,'\0',len+1);
    
    prevcnt = count;
    i=len-1;
    
    printf("___ Input String  = ");
    for(i=0; i<len; i++){
    	printf("%c",str[i]);
    }
    printf("\n");
    while(1){
        
        if(p[i] == ' ' || i == -1){
        	//printf("prevcnt = %d\tj= %d\tcount=%d\n",prevcnt, j, count);
            k=prevcnt;
            l=j-1;
            
            for(m=k; m<=l; m++){
            	printf("%c",res[m]);
            }
            
            while(k<(prevcnt + count/2)){
                res[k] = res[k]^res[l];
                res[l] = res[k]^res[l];
                res[k] = res[k]^res[l];
                k++;
                l--;
            }
            
            if(i == -1)
            	break;
            	
            res[j++] = ' ';
            prevcnt = j;
            count=0;
            printf("\n");
        }
        else{
            res[j++] = p[i];
            count++;
        }
        i--;
    }
    
    printf("\n___ Output String = ");
    for(i=0; i<len+1; i++){
    	printf("%c",res[i]);
    }
}