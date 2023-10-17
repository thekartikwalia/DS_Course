#include <iostream>
using namespace std;

int main()
{
    int n, a[100], min, loc, tmp;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> a[i];
    }
    for (int p = 0; p < n - 1; p++)
    {
        min = a[p];
        loc = p;
        for (int j = p + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                loc = j;
            }
        }
        tmp = a[p];
        a[p] = min;
        a[loc] = tmp;
    }
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
