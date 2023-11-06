#include <iostream>
using namespace std;
int main(){
    int n, pos, element;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Input the element to be inserted
    cout << "Enter the element to be inserted: ";
    cin >> element;
    // Input the position at which the element should be inserted
    cout << "Enter the position (0-based index) at which to insert the element: ";
    cin >> pos;
    // Check if the position is valid
    if (pos < 0 || pos > n){
        cout << "Invalid position. Position should be between 0 and " << n << endl;
        return 1; // Exit with an error code
    }
    // Shift elements to make space for the new element
    for (int i = n - 1; i >= pos; i--){
        arr[i + 1] = arr[i];
    }
    // Insert the element at the specified position
    arr[pos] = element;
    n++; // Increase the size of the array
    // Print the updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
