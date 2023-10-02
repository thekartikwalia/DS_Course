// C Program to demonstrate the use of array
#include <stdio.h>
int main()
{
    // array declaration and initialization
    int arr[5] = {10, 20, 30, 40, 50};
    // modifying element at index 2
    arr[2] = 100;
    // traversing array using for loop
    printf("Elements in Array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
