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


// Function to compute union of 2 linked lists 
struct Node *computeUnion(struct Node *s1, struct Node *s2){
    struct Node *result = NULL;

    while(s1!=NULL && s2!=NULL){
        if(s1->data==s2->data){
            insertAtEnd(&result, s1->data);
            s1=s1->next;
            s2=s2->next;
        } else if(s1->data<s2->data){
            insertAtEnd(&result, s1->data);
            s1=s1->next;
        } else{
            insertAtEnd(&result, s2->data);
            s2=s2->next;
        }
    }

    while(s1!=NULL){
        insertAtEnd(&result, s1->data);
        s1=s1->next;
    }

    while(s2!=NULL){
        insertAtEnd(&result, s2->data);
        s2 = s2->next;
    }

    return result;
};


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
    struct Node *s2 = NULL;

    // Populate s1 and s2 with elements (e.g., 1, 2, 3, 4)
    insertAtEnd(&s1, 1);
    insertAtEnd(&s1, 3);
    insertAtEnd(&s1, 5);

    insertAtEnd(&s2, 2);
    insertAtEnd(&s2, 4);
    insertAtEnd(&s2, 6);

    printf("Set 1: ");
    printList(s1);

    printf("Set 2: ");
    printList(s2);

    struct Node *unionSet = computeUnion(s1, s2);

    printf("Union Set: ");
    printList(unionSet);

    return 0;
}

/*
Time Complexity : The time complexity of this algorithm is O(m + n), where m is the number of
elements in s1 and n is the number of elements in s2.This is because we traverse both linked
lists once, and the time taken is linearly proportional to the total number of elements in both lists.
*/