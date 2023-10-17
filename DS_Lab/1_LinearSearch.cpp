#include <iostream>
using namespace std;

int main()
{
    int a[100], n, key, l = 0;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> a[i];
    }

    cout << "Enter number to find: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Element is at " << i + 1 << "th position" << endl;
            l += 1;
        }
    }

    if (l == 0)
    {
        cout << "Element is not in the array" << endl;
    }

    return 0;
}
