// ========================================= STACK USING LINKED LIST =========================================
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
class Stack{
private:
    Node *top;
public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        while (!isEmpty()){
            pop();
        }
    }
    void push(int data){
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    int pop(){
        if (!isEmpty()){
            Node *temp = top;
            int data = top->data;
            top = top->next;
            delete temp;
            return data;
        }
        cout << "Stack is empty" << endl;
        return -1;
    }
    int peek(){
        if (!isEmpty()){
            return top->data;
        }
        cout << "Stack is empty" << endl;
        return -1;
    }
    bool isEmpty(){
        return top == nullptr;
    }
};
int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popping elements: ";
    while (!stack.isEmpty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}

