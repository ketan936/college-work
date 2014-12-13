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
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

int tree_equal(struct node* tree1, struct node* tree2)
{
	if (tree1 == NULL && tree2 == NULL )	
		return 1;

	if(tree_equal(tree1->left,tree2->left) && tree1->data == tree2->data && tree_equal(tree1->right, tree2->right) )
		return 1;
	return 0;
	
}

int main()
{
    struct node *root1 = new_node(1);
    struct node *root2 = new_node(1);
    root1->left = new_node(2);
    root1->right = new_node(3);
    root1->left->left  = new_node(4);
    root1->left->right = new_node(5);
 
    root2->left = new_node(2);
    root2->right = new_node(3);
    root2->left->left = new_node(4);
    root2->left->right = new_node(5);
 
    if(tree_equal(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
 
    getchar();
  return 0;
}
