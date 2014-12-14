#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
void push (struct node** head_ref, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
int getNth(struct node* head, int index)
{
    if (head==NULL){
        printf("sorry list em=mpty");
        return;
    }
    int count = 0;
    while (head)
    {
        if (count == index)
            return head->data;
        count++;
        head = head->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1); 
   
    /* Check the count function */
    printf("Element at index 3 is %d", getNth(head, 3)); 
    getchar();
}
