#include <stdio.h>
#include <string.h>
// Driver Code
int main()
{
        int id=0,begnum=0,traveltime=0;
        int ret;
        int val1=3,val2=4;
        char name[10]={'a','b','c'};
        name[9]='\0';
    FILE* ptr = fopen("travellers.txt", "wr");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    FILE* ptr1 = fopen("staff.txt", "wr");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }

    /* Assuming that abc.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderabad
       bef     25    delhi
       cce     65    bangalore */
    char buf[100];
        for(int i=0;i<1000;i++){
                id = id+i;
                begnum = (id+1+i)*val1;
                traveltime = (traveltime+1+i)*val2;
                //printf("%d\t%d\t%d\n", id, begnum, traveltime);
                fprintf(ptr, "%d %d %d\n", id, begnum, traveltime);
                sprintf(name, "abc%d", i);
                fprintf(ptr1, "%s\n",name );

                if(i==2){
                        val1=1;
                        val2=1;
                }
        }

    while (fscanf(ptr, "%d %d %d", &id, &begnum, &traveltime) == 3)
        printf("%d\t%d\t%d\n", id, begnum, traveltime);


    /*ret=fscanf(ptr, "%d %d %d", &id, &begnum, &traveltime);
        printf("ret= %d\n",ret);
        printf("%d\t%d\t%d\n", id, begnum, traveltime);*/
        fclose(ptr);

    return 0;
}
