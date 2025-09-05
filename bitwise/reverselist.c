/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void createnew(int val)
{
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data = val;
  new->next = head;
  head = new;
}
void reverselist()
{
    struct node *temp=NULL;
    struct node *prev=NULL;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    head = temp;
}
void printlist()
{
    struct node *temp = head;
    while(temp!=NULL)
    {
        printf("data = %d\n",temp->data);
        temp = temp->next;
    }
}

struct node* listDuplication(struct node* head){
        struct node* temp1 = head;
        struct node* temp2 = head;
        struct node *snext = head;
        while(temp1->next != NULL)
        {
            temp2 = (struct node*)malloc(sizeof(struct node));
            temp2->data = temp1->data;
            snext  =snext->next;
            temp1->next = temp2;
            temp2->next = snext;
            temp1 = temp1->next->next;
        }
		if(temp1->next == NULL)
		{
		temp2 = (struct node*)malloc(sizeof(struct node));
		temp2->data = temp1->data;
		snext  =snext->next;
		temp1->next = temp2;
		temp2->next = snext;
		}
		return head;
}

int main()
{
    int i;
    for(i=50;i>0;i--){
        createnew(i);
    }
    printlist();
    printf("___1 ___\n");
	listDuplication(head);
    //reverselist();
    printlist();
    return 0;
}