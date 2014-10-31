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
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
		
}

void tree_mirror(struct node* node)
{
	struct node* temp; 
	if (node == NULL)
		return;	
	tree_mirror(node->left);
	tree_mirror(node->right);
	
	temp = node->left;
	node->left = node->right;
	node->right = temp;
}

void in_order(struct node* node)
{
  if (node == NULL)
    return;
   
  in_order(node->left);
  printf("%d ", node->data);
 
  in_order(node->right);
} 


int main()
{
  struct node *root = new_node(1);
  root->left        = new_node(2);
  root->right       = new_node(3);
  root->left->left  = new_node(4);
  root->left->right = new_node(5);
   
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  in_order(root);
   
  /* Convert tree to its mirror */
  tree_mirror(root);
   
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n"); 
  in_order(root);
   
  getchar();
  return 0; 
}
 
