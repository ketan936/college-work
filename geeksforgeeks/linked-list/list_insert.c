#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* head = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insertAfter(struct node* prev_node, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(struct node** head_ref,int data)
{
    struct node* head = *head_ref;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL){
        *head_ref = new_node;
        return;
    }
    while (head->next)
        head = head->next;
    head->next = new_node;
    new_node->next = NULL;
}

void printList(struct node* head)
{
    while (head)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
}

int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);
 
  printf("\n Created Linked list is: ");
  printList(head);
 
  getchar();
  return 0;
}
