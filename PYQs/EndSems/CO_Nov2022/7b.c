// RECURSIVE FUNCTION TO CREATE A COPY OF GIVEN LINKED LIST

#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
};

// Function to recursively copy Linked List 
struct Node* copyLinkedList(struct Node* original){
    if (original == NULL) {
        return NULL;    // An empty linked list
    } else {
        // Create a new node with same data 
        struct Node* copy = createNode(original->data);
        // Recursively copy the rest of the list 
        copy->next = copyLinkedList(original->next);
        return copy;
    }
};