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
	struct node* node = (struct  node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


int binary_count(struct node* node)
{
	if (node== NULL)
		return 0;
	if (node->left ==NULL && node->right == NULL)
		return 1;
	else 
		return binary_count(node->left) + binary_count(node->right);
}

int main()
{
  /*create a tree*/ 
  struct node *root = new_node(1);
  root->left        = new_node(2);
  root->right       = new_node(3);
  root->left->left  = new_node(4);
  root->left->right = new_node(5);   
   
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d", binary_count(root));
   
  getchar();
  return 0;
}
