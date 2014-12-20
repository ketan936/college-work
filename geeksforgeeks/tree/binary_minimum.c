#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* left;
	struct node* right;	
};

struct node* new_node(int data)
{
	struct node* node = (struct node*)malloc (sizeof(struct node));
	node->data = data;
	node->left = NULL;	
	node->right = NULL;
	return node;
}


struct node* insert_node (struct node* node , int data)
{
	if (node == NULL)
		return new_node(data);
	else
	{
		if(data <node->data)
		insert_node(node->left,data);

		else
		insert_node(node->right, data);

	}
	return node;
}



