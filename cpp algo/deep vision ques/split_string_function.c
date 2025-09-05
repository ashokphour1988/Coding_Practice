#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **str_split(char *str, char a_delim)
{
    char **result=NULL;
    int count=0;
    char* tmp=str;
    
    char *last_comma=0;
    
    char delim[2];
    
    delim[0]=a_delim;
    delim[1]=0;
    
    while(*tmp){
        if(a_delim==*tmp){
            count++;
            last_comma=tmp;  
        }
        tmp++;
    }
    /*Add space for trailing token*/
    count += last_comma<(str+strlen(str)-1);
    /*Add space for terminating null string so caller knows where the list of returned strings end.*/
    count++;
    //printf("____ 111_______\n");
    result=(char**)malloc(sizeof(char*)*count);
    printf("tokens= %u\n",result);
    //printf("____ 1_______\n");
    if(result){
        
        int i=0;
        //printf("____ 222_______%s\ta_delim= %c\n",str,a_delim);
        char *token=strtok(str,delim);
        
        while(token!=NULL){
            int len=strlen(token);
            result[i]=(char*)malloc(sizeof(char)*len);
            printf("____ 3333_______\n");
            //*(result+i) = token;
            strncpy(result[i],token,len);
            token = strtok(NULL,delim);
            i++;
        }
        
        result[i]=0;
    }
    for(int i=0;*(result+i);i++){
            printf("tokens= %u\n",*(result+i));
            //free(*(result+i));
    }
    
    return result;
}

int main()
{
    char months[] = "deep,vision,systems,hyd";
    char **tokens;
    
    tokens=str_split(months, ',');
    
    if(*tokens!=NULL){
        for(int i=0;*(tokens+i);i++){
            printf("tokens= %u\n",*(tokens+i));
            free(*(tokens+i));
        }
    }
}


/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split_string(char *str, int len, char dm)
{
    char *temp = str;
    char **p;
    int i=0;
    int count=0;
    char delim[2];
    delim[0] = dm;
    delim[1] = '\0';
    for(i=0;i<len;i++){
        if(str[i]==delim)
            count++;
    }
  
    count=count+1;

    p = (char**)malloc(sizeof(char*)*count);
    
    if(p){
        i=0;
        char *token = strtok(str, delim);
        while(token!=NULL){
        
            int slen = strlen(token);
            p[i] = (char*)malloc(sizeof(char)*slen);
            strncpy(p[i],token,slen);
            token = strtok(NULL, delim);
            i++;
        }
    }
    
    printf("i=%d\n",i);
    for(int j=i-1;j>=0;j--){
        
        int slen = strlen(p[j]);

        strncpy(temp,p[j],slen);
        temp = temp+slen;
        *temp = ' ';
        temp++;
        //printf("%d\t%s\n",j,p[j]);
        //free(p[j]);
    }
    
    //free(p);
    return 0;
}

int main() {
    
    char a[] = "deep,vision,systems,hyd";
    
    printf("%s\n",a);
    split_string( a, strlen(a), ',');
    printf("%s\n",a);
    return 0;
}


*/