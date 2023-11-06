#include <iostream>
using namespace std;

int main(){
    int n;
    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0){
        cout << "Array size must be greater than 0." << endl;
        return 1; // Exit with an error code
    }
    int arr[n];
    // Input elements of the array
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Traverse the array and print its elements
    cout << "Array elements: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
