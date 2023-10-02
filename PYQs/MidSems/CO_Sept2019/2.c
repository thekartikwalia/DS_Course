#include<stdio.h>
#include<stdlib.h>


// Define the structure for a singly linked list node 
struct Node{
    int data;
    struct Node *next;
};


// Function to delete the first node with a duplicate data value
struct Node *deleteDuplicateNode(struct Node *head){
    // Condition for no Node or 1 Node
    if(head==NULL || head->next==NULL){
        return head;    // No duplicates in an empty list or a list with 1 element
    }
    // Creating a new pointer for iteration
    struct Node *current = head;
    while(current->next!=NULL){     // Last data would be stored in node just before NULL
        // Creating pointer runner so that it's next node is duplicate one
        struct Node *runner=current;
        while(runner->next!=NULL){
            if(runner->next->data==current->data){
                // Duplicate found, remove the next node
                struct Node *duplicate = runner->next;
                runner->next=duplicate->next;
                free(duplicate);
                break; // Break out of the inner while loop when a duplicate is found
            } else{
                runner=runner->next;
            }
        }
        current=current->next;
    }
}


// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current!= NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    // Requested memory in Heap for new Node creation
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}


int main()
{
    struct Node *head = NULL;
    // Insert some elements (including duplicates)
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    deleteDuplicateNode(head);

    printf("Modified Linked List: ");
    printList(head);

    return 0;
}