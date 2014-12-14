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
	struct node* root = (struct node*) malloc(sizeof(struct node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;		
}
struct node* lca(struct node* node, int left , int right)
{	
	if (node == NULL)
		return NULL;
        if (node->data < left && node->data < right )
		return lca(node->right, left,right);
	else if (node->data > left && node->data > right )
		return lca(node->left, left,right);
	else
		return node;
}
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = new_node(20);
    root->left               = new_node(8);
    root->right              = new_node(22);
    root->left->left         = new_node(4);
    root->left->right        = new_node(12);
    root->left->right->left  = new_node(10);
    root->left->right->right = new_node(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    getchar();
    return 0;
}
