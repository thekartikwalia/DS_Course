#include <iostream>
using namespace std;
void insert(int arr[], int &size, int pos, int val){
    if (size >= 100 || pos < 0 || pos > size){
        cout << "Invalid insertion." << endl;
        return;
    }
    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    size++;
}
void remove(int arr[], int &size, int pos){
    if (pos < 0 || pos >= size){
        cout << "Invalid deletion." << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
}
void display(int arr[], int size){
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[100];
    int size = 0;
    insert(arr, size, 0, 10);
    insert(arr, size, 1, 20);
    insert(arr, size, 2, 30);
    display(arr, size);
    remove(arr, size, 1);
    display(arr, size);
    return 0;
}

