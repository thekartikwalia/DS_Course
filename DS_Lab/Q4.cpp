#include <iostream>
using namespace std;
// ================================================ QUICK SORT ================================================
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// ================================================ MERGE SORT ================================================
void merge(int arr[], int left[], int leftSize, int right[], int rightSize){
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize){
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int size){
    if (size <= 1){
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++){
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Running Quick Sort"<<endl;
    cout << "Original array: ";
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArray(arr, size);
    cout<<"Running Merge Sort"<<endl;
    cout << "Original array: ";
    printArray(arr, size);
    mergeSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}
