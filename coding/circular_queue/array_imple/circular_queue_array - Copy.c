#include <stdio.h>

#define MAX_SIZE 3

int a[MAX_SIZE];
int front=-1;
int rear = -1;

int is_empty()
{
	if((front == -1 && rear == -1))
		return 1;
	else
		return 0;
}

int is_full()
{
	//printf("front=%d\trear=%d\n",front,rear);
	if((rear == MAX_SIZE && front == 0 ) || (rear%MAX_SIZE == front))
		return 1;
	else
		return 0;
}

void enqueue(int data)
{
	if(is_empty()){
		front++;
		rear++;
	}
	else if(is_full()){
		printf("Overflow Queue Full\n");
		display();
		return;
	}
	else if((rear == MAX_SIZE) && ( rear%MAX_SIZE != front )){
		rear=0;
	}
	
	a[rear++] = data;
	//printf("front=%d\trear=%d\n",front,rear);
	
}

int dequeue()
{
	int data;
	if(is_empty()){
		printf("Underflow\n");
		return -1;
	}
	
	data = a[front];
	a[front] = 0;
	front++;
	//printf("front=%d\trear=%d\n",front,rear);
	if( front == rear){
		front=-1;
		rear=-1;
	}
	
	if(front == MAX_SIZE && (front%MAX_SIZE != rear))
		front=0;
		
	return data;
}

void display()
{
	int i;
	printf("##### available elements in queue #######\n");
	for(i=0;i<MAX_SIZE;i++)
		printf("data=%d\n",a[i]);
	printf("##################################\n");
}

int main(void) {
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	
	printf("dequeue data=%d\n",dequeue());	
	enqueue(4);
	enqueue(5);
	printf("dequeue data=%d\n",dequeue());
	enqueue(5);
	printf("dequeue data=%d\n",dequeue());
	printf("dequeue data=%d\n",dequeue());
	printf("dequeue data=%d\n",dequeue());
	printf("dequeue data=%d\n",dequeue());
	return 0;
}