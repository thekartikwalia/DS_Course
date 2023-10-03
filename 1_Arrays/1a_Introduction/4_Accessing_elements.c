// C Program to illustrate element access using array subscript
#include <stdio.h>

int main()
{
    // array declaration and initialization
    int arr[5] = {15, 25, 35, 45, 55};
    // accessing element at index 2 i.e 3rd element
    printf("Element at arr[2]: %d\n", arr[2]);
    // accessing element at index 4 i.e last element
    printf("Element at arr[4]: %d\n", arr[4]);
    // accessing element at index 0 i.e first element
    printf("Element at arr[0]: %d", arr[0]);
    return 0;
}
