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

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
        {
            cout << "Element is at " << mid + 1 << "th position" << endl;
            l += 1;
            break;
        }
        else if (a[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    if (l == 0)
    {
        cout << "Element is not in the array" << endl;
    }

    return 0;
}
