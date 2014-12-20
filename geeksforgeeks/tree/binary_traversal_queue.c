#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left, *right;  
};

struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data; 
    node->left = NULL;
    node->right = NULL;
    return node;
}


