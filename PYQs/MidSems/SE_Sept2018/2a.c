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
struct Node *computeUnion(struct Node *s1, struct Node *s2)
{
    struct Node *result = NULL;

    while (s1 != NULL && s2 != NULL)
    {
        if (s1->data == s2->data)
        {
            insertAtEnd(&result, s1->data);
            s1 = s1->next;
            s2 = s2->next;
        }
        else if (s1->data < s2->data)
        {
            insertAtEnd(&result, s1->data);
            s1 = s1->next;
        }
        else
        {
            insertAtEnd(&result, s2->data);
            s2 = s2->next;
        }
    }

    while (s1 != NULL)
    {
        insertAtEnd(&result, s1->data);
        s1 = s1->next;
    }

    while (s2 != NULL)
    {
        insertAtEnd(&result, s2->data);
        s2 = s2->next;
    }

    return result;
};


// Function to compute union of 2 linked lists
struct Node *computeIntersection(struct Node *s1, struct Node *s2){
    struct Node *result = NULL;

    while (s1 != NULL && s2 != NULL){
        if(s1->data==s2->data){
            insertAtEnd(&result, s1->data);
            s1=s1->next;
            s2=s2->next;
        } else if(s1->data<s2->data){
            s1=s1->next;
        } else{
            s2=s2->next;
        }
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
    struct Node *s1 = NULL;
    struct Node *s2 = NULL;

    // Populate s1 and s2 with elements (e.g., 1, 2, 3, 4)
    insertAtEnd(&s1, 1);
    insertAtEnd(&s1, 3);
    insertAtEnd(&s1, 5);

    insertAtEnd(&s2, 2);
    insertAtEnd(&s2, 3);
    insertAtEnd(&s2, 5);
    insertAtEnd(&s2, 6);

    printf("Set 1: ");
    printList(s1);

    printf("Set 2: ");
    printList(s2);

    struct Node *unionSet = computeUnion(s1, s2);
    struct Node *intersectionSet = computeIntersection(s1,s2);

    printf("Union Set: ");
    printList(unionSet);
    printf("Intersection: ");
    printList(intersectionSet);

    return 0;
}


/*
UNION OPERATION
Since the two linked lists have n elements each, the union operation will take O(n + n)
time since you traverse both lists once. so, Time complexity is O(n)
INTERSECTION OPERATION
SINCE the two linked lists have n elements EACH, and assuming that you have a hash set or other 
efficient data structure to check for element existence in constant time, the intersection
operation will take O(min(n, m)) time, as you traverse the shorter list & check each element in
other list. But since the both lists have same n elements, the traversing would be done till end, so
it will take O(n+n) time, so Time complexity is O(n)
*/