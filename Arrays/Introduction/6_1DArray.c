// C Program to illustrate the use of 1D array
#include <stdio.h>
int main()
{
    // 1d array declaration
    int arr[5];
    // 1d array initialization using for loop
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * i - 2 * i + 1;
    }
    printf("Elements of Array: ");
    // printing 1d array by traversing using for loop
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
