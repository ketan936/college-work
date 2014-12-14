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
int height(struct node* node)
{
   if (node==NULL)
       return 0;
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     if (lheight > rheight)
         return(lheight+1);
     else 
        return(rheight+1);
} 
void printGivenLevel(struct node* root,int level)
{
	if (root == NULL)
		return;
	if (level == 1 )
		printf("%d ", root->data);
     else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    
    } 
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    printf("Height of Tree %d \n",h);
    int i;
    for (i=1; i < h; i++ ) 
        printGivenLevel(root,i); 
        
}   

int main()
{
  struct node *root = new_node(1);
  root->left        = new_node(2);
  root->right       = new_node(3);
  root->left->left  = new_node(4);
  root->left->right = new_node(5);
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}


   
