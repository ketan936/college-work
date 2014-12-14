#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void print_list(struct node* head)
{
    while (head)
    {  
        printf(" %d ",head->data);
        head =  head->next; 
    }
}
int main()
{
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;
   
  // allocate 3 nodes in the heap 
  head  = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));
  
  head->data = 1; //assign data in first node
  head->next = second; // Link first node with the second node 
  
  second->data = 2; //assign data to second node
  second->next = third; 
  
  third->data = 3; //assign data to third node
  third->next = NULL;
   
  print_list(head);
  
  getchar();
  return 0;
}
