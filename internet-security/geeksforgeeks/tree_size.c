#include <stdio.h>
#include <stdlib.h>


struct node 
{
	int data;
	struct node* left;
	struct node* right;	
};


struct node* new_node(int data)
{
	struct node* node = (struct node*) malloc(sizeof (struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


int size_of_tree(struct node* node)
{
	if (node == NULL)
		return 0;
	return size_of_tree(node->left) + 1 + size_of_tree(node->right);

}

int main()
{

	struct node *root = new_node(1);
	root->left  = new_node(2);
	root->right       = new_node(3);
  	root->left->left  = new_node(4);
	root->left->right = new_node(5);  
 	printf("Size of the tree is %d", size_of_tree(root)); 
	getchar();
 	return 0;
}

