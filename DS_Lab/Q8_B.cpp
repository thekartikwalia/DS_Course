// ============================================ QUEUE USING ARRAY ============================================
#include <iostream>
using namespace std;
class Queue{
private:
    int *arr;
    int front, rear, capacity;
public:
    Queue(int size){
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    ~Queue(){
        delete[] arr;
    }
    void enqueue(int data){
        if (front == -1){
            front = rear = 0;
            arr[rear] = data;
        }else if (rear == capacity - 1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }else{
            arr[++rear] = data;
        }
    }
    int dequeue(){
        if (front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear){
            front = rear = -1;
        }else if (front == capacity - 1){
            front = 0;
        }else{
            front++;
        }
        return data;
    }
    int peek(){
        if (front != -1){
            return arr[front];
        }
        cout << "Queue is empty" << endl;
        return -1;
    }
    bool isEmpty(){
        return front == -1;
    }
};
int main(){
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeuing elements: ";
    while (!queue.isEmpty()){
        cout << queue.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

