#include <iostream>
#include <map>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        // memory free
        if (this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node *&head, int d){
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d){
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void traverse(Node *&head){
    if (head == NULL){
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtPosition(Node *&tail, Node *&head, int position, int d){
    // insert at Start
    if (position == 1){
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1){
        temp = temp->next;
        cnt++;
    }
    // inserting at Last Position
    if (temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(int position, Node *&head){
    // deleting first or start node
    if (position == 1){
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }else{
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node *node1 = new Node(10);
    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(tail, head, 4, 22);
    traverse(head);
    deleteNode(4, head);
    traverse(head);
    return 0;
}


