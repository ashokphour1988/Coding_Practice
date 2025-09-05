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

void Listdel(struct List **start, int data)
{
	struct List *prev = *start;
	struct List  *nextnode = (*start)->next;
	
	if(prev->data == data){
		free(prev);
		*start = nextnode;
		return;
	}
	
	while(nextnode != NULL){
		
		if(nextnode->data == data){
			prev->next = nextnode->next;
			free(nextnode);
		}
		prev = prev->next;
		nextnode = nextnode->next;
	}
}

void Listdisplay(struct List *first)
{
	
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
	
	
	
	return 0;
}
