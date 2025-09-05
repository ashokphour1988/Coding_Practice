#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* insert_node(struct node *root, int val){
    
    if(!root){
        root = (struct node*)malloc(sizeof(struct node));
        root->data= val;
        root->right= NULL;
        root->left= NULL;
        return root;
    }
    
    if(val < root->data ){
        root->left = insert_node(root->left, val);
        //printf("left portion\n");
    }
    else{
        root->right = insert_node(root->right, val);
        //printf("right portion\n");
    }
    
    return root;
}

void display_nodes1(struct node *root)
{
    if(!root)
        return;
    
    printf("%d\t",root->data);
    display_nodes1(root->left);
    display_nodes1(root->right);
    return;
}

void display_nodes2(struct node *root)
{
    if(!root)
        return;
    
    display_nodes2(root->left);
    printf("%d\t",root->data);
    display_nodes2(root->right);
    return;
}

void display_nodes3(struct node *root)
{
    if(!root)
        return;
    
    display_nodes3(root->left);
    display_nodes3(root->right);
    printf("%d\t",root->data);
    return;
}
int main() {
	
	struct node *root=NULL;
    int a[12] = {12,8,20,5,6,11,4,21,17,16,13,18};
    int i=0;
    
    for(i=0;i<12;i++){
        root = insert_node(root, a[i]);
    }
    
    printf("## PreOrder ##\n");
    display_nodes1(root);
    printf("\n");
    printf("## InOrder ##\n");
    //printf("###################################\n");
    display_nodes2(root);
    printf("\n");
    printf("## postOrder ##\n");
    //printf("###################################\n");
    display_nodes3(root);
	return 0;
}