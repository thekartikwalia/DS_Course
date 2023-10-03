#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node
{
    int data; 
    struct Node *next;
};

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

// Function to create a new list C with elements from A and B alternately
struct Node *alternateLists(struct Node* A, struct Node* B) {
    struct Node *result = NULL;
    struct Node *currentA = A;
    struct Node *currentB = B;
    while(currentA!=NULL && currentB!=NULL){
        insertAtEnd(&result, currentA->data);
        insertAtEnd(&result, currentB->data);
        currentA=currentA->next;
        currentB=currentB->next;
    }

    // If there are remaining elements in A or B, append them to C
    while(currentA!=NULL){
        insertAtEnd(&result, currentA->data);
        currentA=currentA->next;
    }
    while(currentB!=NULL){
        insertAtEnd(&result, currentB->data);
        currentB=currentB->next;
    }

    return result;
}



// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *A = NULL;
    struct Node *B = NULL;

    // Populate linked lists A and B with elements
    // Example:
    // A: 1 -> 2 -> 3 -> NULL
    // B: 4 -> 5 -> NULL
    insertAtEnd(&A, 1);
    insertAtEnd(&A, 2);
    insertAtEnd(&A, 3);
    insertAtEnd(&B, 4);
    insertAtEnd(&B, 5);

    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    // Create and print the alternating list C
    struct Node *C = alternateLists(A, B);
    printf("Alternating List C: ");
    printList(C);

    return 0;
}