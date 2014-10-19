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

int tree_depth(struct node* node )
{
	if (node == NULL)
	return 0;

	int l = tree_depth(node->left);
	int r = tree_depth(node->right);
	if(l>r)
	{
		return l+1;
	}else{
		return r+1;

}

}
int main()
{
    struct node *root = new_node(1);
 
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
   
    printf("Hight of tree is %d", tree_depth(root));
   
    getchar();
    return 0;
}







