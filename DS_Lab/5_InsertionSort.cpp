#include <iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> a[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int k = j; k >= 1; k--)
        {
            if (a[k] < a[k - 1])
            {
                int tmp = a[k];
                a[k] = a[k - 1];
                a[k - 1] = tmp;
            }
        }
    }

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
