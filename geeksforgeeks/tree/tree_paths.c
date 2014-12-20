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
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
 
}

void tree_print(int path[],int pathlen)
{
	int i ;
	for (i=0;i<pathlen;i++)
	{
		printf("%d ",path[i]);
	}
	printf("\n");
	

} 


void tree_paths(struct node* node,int  path[],int pathlen)
{
	if (node == NULL )
		return;
	path[pathlen] = node->data;
	pathlen++;

	if(node->left==NULL && node->right ==NULL)
	{
		tree_print(path,pathlen);
	}else{
		tree_paths(node->left,path,pathlen);
		tree_paths(node->right,path,pathlen);
	
	}	



}


