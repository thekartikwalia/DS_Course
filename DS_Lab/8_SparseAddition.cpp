#include <iostream>
using namespace std;

struct Element
{
    int i, j, x;
};

struct Sparse
{
    int n, m, num;
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

Sparse *add(const Sparse &s1, const Sparse &s2)
{
    Sparse *sum = new Sparse;
    sum->e = new Element[s1.num + s2.num];
    int i = 0, j = 0, k = 0;

    while (i < s1.num && j < s2.num)
    {
        if (s1.e[i].i < s2.e[j].i)
        {
            sum->e[k++] = s1.e[i++];
        }
        else if (s1.e[i].i > s2.e[j].i)
        {
            sum->e[k++] = s2.e[j++];
        }
        else
        {
            if (s1.e[i].j < s2.e[j].j)
            {
                sum->e[k++] = s1.e[i++];
            }
            else if (s1.e[i].j > s2.e[j].j)
            {
                sum->e[k++] = s2.e[j++];
            }
            else
            {
                sum->e[k] = s1.e[i];
                sum->e[k].x = s1.e[i++].x + s2.e[j++].x;
                k++;
            }
        }
    }
    while (i < s1.num)
    {
        sum->e[k++] = s1.e[i++];
    }
    while (j < s2.num)
    {
        sum->e[k++] = s2.e[j++];
    }
    sum->m = s1.m;
    sum->n = s1.n;
    sum->num = k;

    return sum;
}

int main()
{
    Sparse s1, s2, *s3;

    create(s1);
    create(s2);

    s3 = add(s1, s2);

    cout << "First Matrix" << endl;
    display(s1);
    cout << "Second Matrix" << endl;
    display(s2);
    cout << "Sum Matrix" << endl;
    display(*s3);

    delete[] s1.e;
    delete[] s2.e;
    delete[] s3->e;
    delete s3;

    return 0;
}
