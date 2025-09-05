#include <stdio.h>
#include <stdlib.h>
struct List{
	int data;
	struct List *next;
};

void Listadd(struct List **start, int data)
{
	struct List *newnode = (struct List *)malloc(sizeof(struct List));
	newnode->data = data;
	newnode->next = (*start);
	(*start) = newnode;

}

void Listdel(struct List **first, int data)
{
	struct List *temp1 = *first;
	struct List *temp2 = *first;
	
	
	if(*first == NULL){
		return;
	}
	
	if(temp1->data == data){
		temp1->next = NULL;
		free(temp1);
		temp1 = NULL;
		*first = temp1;
		return;
	}
	
	temp1 = temp1->next;
	
	while(temp1 != NULL){
		if(temp1->data = data){
			temp2->next = temp1->next;
			temp1->next = NULL;
			free(temp1);
			temp1 = NULL;
			return;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

void Listdisplay(struct List *first)
{
	if(first ==NULL)
		printf("nothing to display\n");
		
	while(first!=NULL){
		printf("data = %d\n",first->data);
		first = first->next;
	}
}

int main(void) {
	
	struct List *start = NULL;
	int i=0;
	printf("____ adding  _______ \n");
	for(i=3; i>=1; i--){
		Listadd(&start, i);
	}
	printf("____ displaying  _______ \n");
	Listdisplay(start);
	
	Listdel(&start, 2);
	printf("____ displaying after deletion 2 _______ \n");
	Listdisplay(start);
	
	
	Listdel(&start, 3);
	printf("____ displaying after deletion  3_______ \n");
	Listdisplay(start);
	
	Listdel(&start, 1);
	printf("____ displaying after deletion  1 _______ \n");
	Listdisplay(start);
	
	Listdel(&start, 3);
	printf("____ displaying after deletion  when List is empty_______ \n");
	Listdisplay(start);
	
	return 0;
}
