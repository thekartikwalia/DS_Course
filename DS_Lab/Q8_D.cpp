// ========================================= QUEUE USING LINKED LIST =========================================
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue(){
        front = rear = nullptr;
    }
    ~Queue(){
        while (!isEmpty()){
            dequeue();
        }
    }
    void enqueue(int data){
        Node *newNode = new Node(data);
        if (isEmpty()){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue(){
        if (!isEmpty()){
            Node *temp = front;
            int data = front->data;
            front = front->next;
            delete temp;
            if (front == nullptr){
                rear = nullptr;
            }
            return data;
        }
        cout << "Queue is empty" << endl;
        return -1;
    }
    int peek(){
        if (!isEmpty()){
            return front->data;
        }
        cout << "Queue is empty" << endl;
        return -1;
    }
    bool isEmpty(){
        return front == nullptr;
    }
};
int main(){
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeuing elements: ";
    while (!queue.isEmpty()){
        cout << queue.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

