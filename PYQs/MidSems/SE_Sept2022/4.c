#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to find middle of linked list

/*
You can find the middle of a singly linked list by using two pointers, often referred to as the 
slow pointer and the fast pointer.The fast pointer moves twice as fast as the slow pointer. 
When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. 
*/

struct Node *findMiddle(struct Node *head)
{
    if(head==NULL){     // empty list
        return NULL;
    }
    struct Node *slowPtr=head;
    struct Node *fastPtr=head;
    struct Node *prevSlowPtr = NULL;

    /*
    fastPtr->next != NULL : This part checks if the next pointer of the fast pointer is not pointing
    to NULL.Again, this is necessary bcoz when you move the fast pointer two steps
    ahead(fastPtr = fastPtr->next->next), you need to ensure that both fastPtr and fastPtr->next are
    valid pointers.If fastPtr->next is NULL, attempting to access fastPtr->next->next would result in
    an error.
    */
   while(fastPtr!=NULL && fastPtr->next!=NULL){
    fastPtr=fastPtr->next->next;
    prevSlowPtr = slowPtr;
    slowPtr=slowPtr->next;
   }
   
   // If fastPtr is NULL, the list has an even number of elements
   if (fastPtr == NULL)
   {
    printf("Second middle: %d\n", prevSlowPtr->data);
   }

   return slowPtr;
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
    struct Node *s1 = NULL;

    // Populate s1  with elements (e.g., 1, 2, 3, 4)
    insertAtEnd(&s1, 1);
    insertAtEnd(&s1, 3);
    insertAtEnd(&s1, 4);
    insertAtEnd(&s1, 5);
    insertAtEnd(&s1, 6);

    printf("Original Linked List: ");
    printList(s1);

    struct Node *middle = findMiddle(s1);

    if (middle != NULL)
    {
        printf("Middle of the Linked List: %d\n", middle->data);
    }
    else
    {
        printf("The list is empty.\n");
    }

    return 0;
}