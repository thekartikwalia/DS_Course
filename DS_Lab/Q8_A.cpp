// ============================================ STACK USING ARRAY ============================================
#include <iostream>
using namespace std;
class Stack{
private:
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack(){
        delete[] arr;
    }
    void push(int data){
        if (top < capacity - 1){
            arr[++top] = data;
        }else{
            cout << "Stack Overflow" << endl;
        }
    }
    int pop(){
        if (top >= 0){
            return arr[top--];
        }
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int peek(){
        if (top >= 0){
            return arr[top];
        }
        cout << "Stack is empty" << endl;
        return -1;
    }
    bool isEmpty(){
        return top == -1;
    }
};
int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popping elements: ";
    while (!stack.isEmpty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}

