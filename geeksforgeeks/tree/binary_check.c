#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isBSTUtil(struct node* node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->data < min || node->data > max )
        return 0;
    return isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data +1,max);
}
int isBST(struct node* node)
{
    return  isBSTUtil(node, INT_MIN, INT_MAX); 

}

int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
} 

