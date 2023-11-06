#include <iostream>

struct Node{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void deleteLinkedList(Node * &head){
    if (head == nullptr) {
        return; // List is empty, nothing to delete
    }
    Node *nextNode = head->next; // Saving reference of next node
    delete head; // Deleting current node
    head = nullptr; // Set the current node's pointer to NULL

    deleteLinkedList(nextNode); // Recursively delete the rest of linked list
}