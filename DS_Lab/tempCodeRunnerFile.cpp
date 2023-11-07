#include <iostream>
using namespace std;
void bubbleSort(int a[], int n){
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n - 1; i++){
            int j = i + 1;
            if (a[i] > a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void selectionSort(int a[], int n){
    for (int p = 0; p < n - 1; p++){
        int min = a[p],loc = p;
        for (int j = p + 1; j < n; j++){
            if (min > a[j]){
                min = a[j];
                loc = j;
            }
        }
        int tmp = a[p];
        a[p] = min;
        a[loc] = tmp;
    }
}
void insertionSort(int a[], int n){
    for (int j = 1; j < n; j++){
        for (int k = j; k >= 1; k--){
            if (a[k] < a[k - 1]){
                int tmp = a[k];
                a[k] = a[k - 1];
                a[k - 1] = tmp;
            }
        }
    }
}
int main(){
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Enter " << i << "th element: ";
        cin >> a[i];
    }
    cout<<"Running Bubble Sort"<<endl;
    bubbleSort(a, n);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Running Selection Sort" << endl;
    selectionSort(a, n);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Running Insertion Sort" << endl;
    insertionSort(a, n);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}

