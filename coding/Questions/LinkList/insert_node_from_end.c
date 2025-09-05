#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

struct node* insert_node( struct node *first, int data){
	struct node *temp = first;
	if(temp == NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		return temp;
	}
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = (struct node*)malloc(sizeof(struct node));
	temp = temp->next;
	temp->data = data;
	temp->next = NULL;
	
	return first;
}

/*
Input : 1->2->3->4->5 , N = 2 
Output : 1->2->3->5

Input : 7->8->4->3->2 , N = 1 
Output : 7->8->4->3  
*/

struct node *delete_nth_node_from_end(struct node *first, int pos ){
	struct node *temp = first;
	struct node *prev = first;
	struct node *curr = first;
	int diff=0;
	int i;
	int len=0;
	
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	
	
	// when position is grater than the length of linklist
	if(pos > len){
		return first;
	}
	else if(pos == len){ // when position on nth node is equal to length of the linklist then We need to remove head node suppose if 5 node and deleting pos also is 5
		temp = first;
		first = first->next;
		free(temp);
		return first;
	}
	else{
		diff = len-pos;
		
		for(i=0; i<diff; i++){
			prev = curr;
			curr = curr->next;
		}
		if(curr != NULL){  /* if position is 0 then no needs to delete  as considering not any zeroth node*/
			prev->next = curr->next;
			free(curr);
		}
	}
	return first;
}

struct node *reverse_list(struct node *first ){
	struct node *temp = first;
	struct node *newlist;
	struct node *curr = NULL;
	
	while( temp != NULL ){
		newlist = temp;
		temp = temp->next;
		newlist->next = curr;
		curr = newlist;
	}
	
	return newlist;
}

void display(struct node *first){
	
	if(first == NULL)
		return;
	
	while( first != NULL ){
		printf("data = %d\n", first->data);
		first = first->next;
	}
	return;
}

int main(void) {
	
	struct node *first = NULL;
	first = insert_node( first, 1);
	first = insert_node( first, 2);
	first = insert_node( first, 3);
	first = insert_node( first, 4);
	first = insert_node( first, 5);
	first = insert_node( first, 6);
	
	printf("Before deleting ####### \n");
	display( first );
	//first = delete_nth_node_from_end( first, 6 );
	first = reverse_list(first );
	printf("After deleting ####### \n");
	display( first );
	return 0;
}


void move(struct list **dest, struct list **src){
	struct list *newnode = *src;

	*src = newnode->next;

	newnode->next = *dest;

	*dest = newnode;
}