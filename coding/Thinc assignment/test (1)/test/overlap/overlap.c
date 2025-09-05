#include<stdio.h>
#include<stdlib.h>
struct memory{
	unsigned int start;
	unsigned int end;
	unsigned int len;
    struct memory *next;
	struct memory *prev;
};
unsigned long hex2int(char *a, unsigned int len);
void overlap_validation(struct memory *first,int total_items);
int main()
{
        char start[9]={0};
	char end[9]={0};
	int i=0,j=0,total=0;
	struct memory *first=NULL,*tmp=NULL,*temp1=NULL;
	FILE *fp = fopen("address.txt","r");
    while(1)
	{
	char b=fgetc(fp);
	if(b==EOF)
	     break;
        if(b =='\n')
             {
	     if(first == NULL)
		{
		tmp=first = (struct memory *)malloc(sizeof(struct memory));
		first->prev=NULL;
		}
	     else
		{
		tmp->next = (struct memory *)malloc(sizeof(struct memory));
		temp1=tmp;
		tmp = tmp->next;
		tmp->prev = temp1;
		}
	     if(tmp){	
	     	tmp->start=hex2int(start,8);
	     	tmp->end=hex2int(end,8);
	     	tmp->len=(tmp->end-tmp->start);
	     	//printf("start=%x\tend=%x\tlen=%d\n",tmp->start,tmp->end,tmp->len);
		total++;
		}
		else{
		printf("memory allocation failed\n");
		}
	     }
	else{

	if(b=='-')
	    {
		//do nothing
	    }
	else
	   {
	    if(i==8)
	    {
            end[j]=b;
	    j++;
	    if(j==8)
		{
		i=0;
		j=0;
		}
	    }
            else
            {
            start[i]=b;
	    i++;
            }
          }
	}
}
       overlap_validation(first,total);
       tmp=first;
       while(tmp)
	{
	first=tmp->next;
	free(tmp);
	tmp=first;	
	}
	close(fp);
	return 0;
}
unsigned long hex2int(char *a, unsigned int len)
{
    int i;
    unsigned long val = 0;

    for(i=0;i<len;i++)
       if(a[i] <= 57)
        val += ((a[i]-48)<<(4*(len-1-i)));
       else
        val += (((a[i]-55)& 0x0f)<<(4*(len-1-i)));

    return val;
}
void overlap_validation(struct memory *first,int total_items)
{
	struct memory *temp = first;
	struct memory *temp1 = first->next;
	int i=0,j=0;

	while(i<total_items)
	{
	   if(i>0){
		temp=temp->next;
		temp1=first;
		j=0;
		}
		if(temp!=NULL)
		{
		  printf("Overlapping validation performing for address rage %x-%x :\n",temp->start,temp->end);
		  while(temp1)
		  {
		  if(temp != temp1)
		    if(((temp->start+temp->len)<temp1->start) || ((temp1->start+temp1->len)<temp->start))
		     {
		     printf("         Not Overlapping with address rang : %x-%x\n",temp1->start,temp1->end);
		     }
		  else
		     {
                     printf("                          Overlapping with : %x-%x\n",temp1->start,temp1->end);                    
		     if(j==0)
			 j++; 
		     }
		     temp1=temp1->next;
		  }
		}
		printf("\n");
                   if(j==0){ 
		       printf("This address range %x-%xis unique\n",temp->start,temp->end);
		    }
	   i++;
	}
}
