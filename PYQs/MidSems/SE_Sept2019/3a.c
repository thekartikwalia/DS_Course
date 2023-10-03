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

// Function to concatenate two linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2){
    if (list1==NULL){
        return list2;
    } else if (list2==NULL){
        return list1;
    } else {
        struct Node *current=list1;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=list2;
        return list1;
    }
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
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    // Insert elements into list1
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // Insert elements into list2
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);

    printf("List 1 : ");
    printList(list1);
    printf("List 2 : ");
    printList(list2);

    // Concatenate list2 to list1
    list1 = concatenateLists(list1, list2);

    // Print the concatenated list
    printf("Concatenated List: ");
    printList(list1);

    return 0;
}