#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *add(struct node *root, int data)
{
	if(root == NULL){
		root = (struct node *)malloc(sizeof(struct node));
		//printf(" _______ 1 _______\n");
		
		root->data = data;
		root->left= NULL;
		root->right = NULL;
	}
	else{
		//printf(" _______ 2 _______\n");
		if(data < root->data){
			root->left = add(root->left, data);
		}
		else{
			root->right = add(root->right, data);
		}
	}
	return root;
}

void preorder(struct node *root){
	if(root == NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
	
}

void delete(struct)


int FindMax(struct node *root){
	if(root == NULL){
		return NULL;
	}
	else if(root->right == NULL){
		return root;
	}
	else{
		return FindMax(root->right);
	}
}

int main() {
	struct node *root = NULL;
	/*for(int i=1; i<4; i++){
		root = add(root, i);
	}*/
	
	root = add(root, 4);
	add(root, 2);
	add(root, 6);
	add(root, 3);
	add(root, 5);
	add(root, 1);
	
	printf("root= %u\n",root);
	
	preorder(root);
	
	return 0;
}