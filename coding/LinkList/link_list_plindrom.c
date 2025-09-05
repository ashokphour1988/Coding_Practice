#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void move_list(struct node **dest, struct node **src){
    struct node *new_node = *src;
    
    *src = new_node->next;
    new_node->next = *dest;
    *dest = new_node;
}

void insert_node(struct node** head, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = *head;
    *head = temp;
}

void display(struct node *head){
    while(head!=NULL){
        printf("val = %d\n",head->val);
        head = head->next;
    }
}

int find_plindrom(struct node* head){
    if(head==NULL)
        return 0;
        
    int count=0;
    struct node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    
    temp = head;
    int mid = count/2;
    for(int i=0; i<mid; i++){
        temp=temp->next;
    }
    struct node *tail=NULL;

    while(temp){
        move_list(&tail,&temp);
    }
    display(tail);
    temp=head;
    for(int i=0; i<mid; i++){
        if(temp->val == tail->val ){
            temp=temp->next;
            tail=tail->next;
        }
        else
            return 0;
    }
    return 1;
}

int main() {
    struct node* head=NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    //insert_node(&head, 3);
    insert_node(&head, 3);
    insert_node(&head, 2);
    insert_node(&head, 1);
    printf("is_plindrom= %d\n",find_plindrom(head));
    //display(head);
    return 0;
}