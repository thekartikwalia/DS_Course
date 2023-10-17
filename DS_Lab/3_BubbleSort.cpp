#include <iostream>
using namespace std;

int main()
{
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> a[i];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
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
