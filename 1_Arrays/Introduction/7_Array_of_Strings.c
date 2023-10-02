// C Program to illustrate strings
// We store sequence of characters in form of array of characters terminated by a NULL character.
#include <stdio.h>
int main()
{
    // creating array of character
    char arr[6] = {'G', 'e', 'e', 'k', 's', '\0'};
    // printing string
    int i = 0;
    while (arr[i])
    {
        printf("%c", arr[i++]);
    }
    return 0;
}
