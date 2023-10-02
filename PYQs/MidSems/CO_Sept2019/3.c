#include<stdio.h>
#include<stdlib.h>


// Define the structure for a singly linked list node 
struct Node{
    int data;
    struct Node *next;
};


// Function to find value of kth Node from end
int kthNodeFromEnd(struct Node *head, int k){
    if(head==NULL || k<=0){
        return -1;  // Linked list doesn't exist or k is non-positive
    }
    struct Node *firstPtr=head;
    struct Node *secondPtr=head;

    // Move firstPtr k nodes ahead
    for(int i=0; i<k; i++){
        if(firstPtr==NULL){
            return -1;  // List isn't long enough
        }
        firstPtr=firstPtr->next;
    }

    // Move both pointers until firstPtr reaches end
    while(firstPtr!=NULL){
        firstPtr=firstPtr->next;
        secondPtr=secondPtr->next;
    }

    // Return the data of kth Node from the end
    return secondPtr->data;
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
    // Insert some elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    int k = 3; // Find the 3rd node from the end
    int result = kthNodeFromEnd(head, k);
    if (result != -1)
    {
        printf("Value of the %dth node from the end is: %d\n", k, result);
    }
    else
    {
        printf("Invalid input or k is too large.\n");
    }
    // Free memory
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
