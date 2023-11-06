#include <iostream>
using namespace std;

struct Element
{
    int i, j, x;
};

struct Sparse
{
    int m, n, num;
    Element *e;
};

void create(Sparse &s)
{
    cout << "Enter dimensions (row x column): ";
    cin >> s.m >> s.n;
    cout << "Enter no. of non-zero elements: ";
    cin >> s.num;
    s.e = new Element[s.num];
    cout << "Enter all non-zero elements: ";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
}

void display(const Sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

Sparse *multiply(const Sparse &s1, const Sparse &s2)
{
    if (s1.n != s2.m)
    {
        cout << "Matrix Multiplication not possible!" << endl;
        return nullptr;
    }

    Sparse *result = new Sparse;
    result->m = s1.m;
    result->n = s2.n;
    result->num = 0;
    result->e = new Element[result->num];

    int sum, k = 0;
    for (int i = 0; i < s1.m; i++)
    {
        for (int j = 0; j < s2.n; j++)
        {
            sum = 0;
            for (int l = 0; l < s1.num; l++)
            {
                for (int m = 0; m < s2.num; m++)
                {
                    if (s1.e[l].j == s2.e[m].i && s1.e[l].i == i && s2.e[m].j == j)
                    {
                        sum += s1.e[l].x * s2.e[m].x;
                    }
                }
            }
            if (sum != 0)
            {
                result->num++;
                result->e = new Element[result->num];
                result->e[k].i = i;
                result->e[k].j = j;
                result->e[k].x = sum;
                k++;
            }
        }
    }

    return result;
}

int main()
{
    Sparse s1, s2, *s3;

    create(s1);
    create(s2);

    s3 = multiply(s1, s2);
    cout << "First Matrix" << endl;
    display(s1);
    cout << "Second Matrix" << endl;
    display(s2);
    cout << "Product Matrix" << endl;
    display(*s3);

    delete[] s1.e;
    delete[] s2.e;
    delete[] s3->e;
    delete s3;

    return 0;
}
