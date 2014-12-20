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

void tree_delete(struct node* node)
{
	 if (node == NULL)
		return;
	tree_delete(node->left);
	tree_delete(node->right);
	printf("deleting node: %d \n",node->data);
	free(node);
}


int main()
{
    struct node *root = new_node(1);
    root->left            = new_node(2);
    root->right          = new_node(3);
    root->left->left     = new_node(4);
    root->left->right   = new_node(5);
   
    tree_delete(root); 
    root = NULL;
 
    printf("\n Tree deleted ");
   
    getchar();
    return 0;
}
