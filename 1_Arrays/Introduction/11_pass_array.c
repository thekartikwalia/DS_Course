// C Program to pass an array to a function
#include <stdio.h>
void printArray(int arr[])
{
    printf("Size of Array in Functions: %d\n", sizeof(arr));
    printf("Array Elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}

// driver code
int main()
{

    int arr[5] = {10, 20, 30, 40, 50};

    printf("Size of Array in main(): %d\n", sizeof(arr));
    printArray(arr);
    return 0;
}
