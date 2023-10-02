// C Program to return array from a function
#include <stdio.h>
// function
int *func()
{
    static int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}
// driver code
int main()
{
    int *ptr = func();
    printf("Array Elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *ptr++);
    }
    return 0;
}

/* 
NOTE :
You may have noticed that we declared static array using static keyword. This is due to fact that when 
function returns value, all local variables & other entities declared inside that function are deleted. 
So, if we create a local array instead of static, we will get segmentation fault while trying to 
access the array in the main function. 
*/
