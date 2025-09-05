#include <stdio.h>
#include <stdlib.h>
 
struct node {
	int data;
	struct node *next;
	//struct node *prev;
};
 
struct node *add_node(struct node *head, int data)
{
	struct node *temp=head;
 
	if(head == NULL){
		head = (struct node*)malloc(sizeof(struct node));
		head->data = data;
		head->next = NULL;
		//head->prev = NULL;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
 
		temp->next = (struct node*)malloc(sizeof(struct node));
		temp = temp->next;
		temp->data = data;
		temp->next = NULL;
	}
	return head;
}

/* delete duplecate nodes in sorted linklist*/
struct node *delete_duplicate_node(struct node *head)
{
	struct node *temp = head;
	struct node *prev = head;

	if(head == NULL)
		return NULL;
 
	if(head->next == NULL){
		return head;
	}
	
	temp = temp->next;
	
	while(prev->next!=NULL){
		
		if(prev->data == temp->data){
			prev->next = temp->next;
			free(temp);
			temp = prev->next;
		}
		else{
			prev = prev->next;
			temp = temp->next;
		}
	}
	return head;
}

 
/*
Before deleting : 0,1,2,3,4,5,6,7,8
After delete : 0,2,4,6,8
*/
 
struct node *delete_odd_alternate(struct node *head)
{
	struct node *fast = head;
	struct node *slow = head;
	struct node *prev = head;
 
	//if there is not any node in linklist
	if(head == NULL)
		return NULL;
 
	//if only one existing in linklist
	if(head->next == NULL){
		return head;
	}
 
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
 
		/*
		  during the traversing the linklist just checking if fast pointer is getting NULL for even number of nodes when end of the list is reached in case of even nodes in linklist (2,4,6,8 etc) then no needs to move 
		  previous and slow pointers because these pointers will be on 2nd last node only as these are moving with fast points because of deletion of nodes.
		*/
		if(fast!=NULL){
			slow = slow->next;
			prev->next = slow->next;
			free(slow);
			slow = fast;
			prev = fast;
		}
	}
 
	if(fast == NULL){
		slow = slow->next;
		prev->next = slow->next;
		free(slow);
	}
 
 
	return head;
}

/*
Before deleting : 0,1,2,3,4,5,6,7,8
After delete : 1,3,5,7,9
*/
struct node *delete_even_alternate(struct node *head)
{
	struct node *fast = head;
	struct node *slow = head;
	struct node *prev = head;
	struct node *temp = head;
 
	if(head == NULL)
		return NULL;
 
	if(head->next == NULL){
		free(head);
		return NULL;
	}
 
	if(head->next != NULL){
		temp = temp->next;
		free(head);
		head = temp;
		fast = head;
		slow = head;
		prev = head;
	}
 //printf("____ data = %d\n", head->data);
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
 
		if(fast!=NULL){
			slow = slow->next;
			prev->next = slow->next;
			free(slow);
			slow = fast;
			prev = fast;
		}
	}
 
	if(fast == NULL){
		slow = slow->next;
		prev->next = slow->next;
		free(slow);
	}
 
	return head;
}
 
struct node *delete_fromm_middle(struct node *head)
{
	struct node *fast = head;
	struct node *slow = head;
	struct node *prev;
 
	if(head == NULL){
		return head;
	}
	if(head->next == NULL){
		free(head);
		return NULL;
	}
 
	while((fast != NULL) && (fast->next != NULL) ){
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
 
	prev->next= slow->next;
	slow->next = NULL;
	free(slow);
	return head;
}
 
struct node *reverse_list(struct node *head)
{
	struct node *temp = head;
	struct node *prev = NULL;
	struct node *temp1;
 
	while(temp != NULL){
		temp1 = temp;
		temp = temp->next;
		temp1->next = prev;
		prev = temp1;
	}
 
	return prev;
}
 
void display_node(struct node *head)
{
	struct node *temp=head;
	while(temp != NULL){
		printf("data = %d\n",temp->data);
		temp = temp->next;
	}
}
 
int main(void) {
	struct node *head=NULL;
	int i;
	for(i=1; i<16;i++){
		head = add_node(head, i);
	}
 
	printf("before deleting\n");
	display_node(head);
 
	//delete_fromm_middle(head);
	//head = reverse_list(head);
	//delete_even_alternate(head);
	head = delete_odd_alternate(head);
	printf("After deleting\n");
	display_node(head);
 
	return 0;
}