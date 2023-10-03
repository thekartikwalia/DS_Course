#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function for inserting new node 'p' into doubly linked list after node pointed by node pointer 'q'
/*
struct Node** head is a double pointer (pointer to a pointer) to the head of the linked list. 
We use a double pointer because we want to modify the head of the list within this function. 
If we pass a single pointer, any modifications to head within this function will be local and won't 
affect the head outside of the function.
*/
void insertAfter(struct Node **head, struct Node *q, int p_data){
    // Allocate memory for a new Node
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=p_data;

    // Case 1: If the list is empty, set 'newNode' as the head
    if(*head==NULL){
        newNode->prev=NULL;
        newNode->next=NULL;
        *head = newNode;    // Update the head to point to the new node
        return;
    }

    // Case 2: If 'q' is NULL, insert 'newNode' at the beginning
    if(q==NULL){
        newNode->prev=NULL;
        newNode->next=*head;
        (*head)->prev=newNode;
        *head = newNode; // Update the head to point to the new node
        return;
    }
    // Below is wrong way
    /* f (q == NULL)
    {
        newNode->prev = NULL;
        newNode->next = q->next; // This line will result in undefined behavior
        q->next->prev = newNode; // This line will also result in undefined behavior
        *head = newNode;
        return;
    }
    */

    // Case 3: Insert 'newNode' after 'q'
    newNode->next=q->next;
    newNode->prev=q;
    if(q->next!=NULL){
        q->next->prev=newNode;
    }
    q->next=newNode;

}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    // Example usage
    insertAfter(&head, NULL, 1);       // Insert 1 when the list is empty
    insertAfter(&head, NULL, 0);       // Insert 0 at the beginning
    insertAfter(&head, head, 2);       // Insert 2 after 0
    insertAfter(&head, head->next, 3); // Insert 3 after 2
    display(head);                     // Output: 0 <-> 2 <-> 1 <-> 3 <-> NULL

    return 0;
}