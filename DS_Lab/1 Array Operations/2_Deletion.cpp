#include <iostream>
using namespace std;
int main(){
    int n, pos;
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0){
        cout << "Array size must be greater than 0." << endl;
        return 1; // Exit with an error code
    }
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Input the position from which to delete the element
    cout << "Enter the position (0-based index) from which to delete the element: ";
    cin >> pos;
    // Check if the position is valid
    if (pos < 0 || pos >= n){
        cout << "Invalid position. Position should be between 0 and " << n - 1 << endl;
        return 1; // Exit with an error code
    }
    // Shift elements to remove the element at the specified position
    for (int i = pos; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--; // Decrease the size of the array
    // Print the updated array
    cout << "Updated array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
