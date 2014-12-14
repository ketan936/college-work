#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;   
    struct node* next;
};

void push(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void deleteNode(struct node** head_ref, int key)
{
    if (*head_ref == NULL){
        printf("sorry list is empty\n");
        return;
    }
    struct node* head = *head_ref;
    struct node* prev_node; 
    while(head)
    {  
        if (head->data == key)
            break;
        
        prev_node = head;
        head= head->next;
    }    
    if (head==NULL){
        printf("not found\n");
        return;
    }
    printf(" prev node %d \n",prev_node->data);
    prev_node->next = head->next;
    free(head);
    
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}


