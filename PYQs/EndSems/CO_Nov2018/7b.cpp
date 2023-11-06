// The 'insertSorted' function is used to insert a node into a sorted list in ascending order.

// The 'insertionSort' function iterates through the original list, removes nodes one by one, and inserts 
// them into the sorted list.

#include<iostream>

struct Node{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertSorted(Node* &head, Node* newNode){}
void insertionSort(Node* &head){
    if (head == NULL || head->next == NULL){
        return; // Already sorted or empty list
    }

    // Initialize an empty sorted linked list 
    Node *sorted = nullptr;

    while (head != nullptr){
        Node *current = head;
        head = head->next;
        current->next = nullptr;

        insertSorted(sorted, current); // Insert the node into sorted list
    }

    head = sorted;
}