#include <iostream>
using namespace std;
int linearSearch(int a[], int n, int key){
    for (int i = 0; i < n; i++){
        if (a[i] == key){return i;}
    }
    return -1;
}
int binarySearch(int a[], int n, int key){
    int start = 0;
    int end = n - 1;
    while (start <= end){
        int mid = (start + end) / 2;
        if (a[mid] == key){return mid;}
        else if (a[mid] < key){start = mid + 1;}
        else{end = mid - 1;}
    }
    return -1;
}
int main(){
    int a[100], n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Enter " << i + 1 << "th element: ";
        cin >> a[i];
    }
    cout << "Enter number to find: ";
    cin >> key;
    int linearResult = linearSearch(a, n, key);
    int binaryResult = binarySearch(a, n, key);
    if (linearResult != -1){
        cout << "Element is at " << linearResult + 1 << "th position (Linear Search)" << endl;
    }else{cout << "Element is not in the array (Linear Search)" << endl;}
    if (binaryResult != -1){
        cout << "Element is at " << binaryResult + 1 << "th position (Binary Search)" << endl;
    }else{cout << "Element is not in the array (Binary Search)" << endl;}
    return 0;
}

