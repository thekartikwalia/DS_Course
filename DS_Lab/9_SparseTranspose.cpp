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

Sparse *transpose(const Sparse &s)
{
    Sparse *result = new Sparse;
    result->m = s.n;
    result->n = s.m;
    result->num = s.num;
    result->e = new Element[result->num];

    int *colCount = new int[s.n]();
    int *colPosition = new int[s.n]();

    for (int i = 0; i < s.num; i++)
    {
        colCount[s.e[i].j]++;
    }

    colPosition[0] = 0;

    for (int i = 1; i < s.n; i++)
    {
        colPosition[i] = colPosition[i - 1] + colCount[i - 1];
    }

    for (int i = 0; i < s.num; i++)
    {
        int j = s.e[i].j;
        result->e[colPosition[j]].i = s.e[i].j;
        result->e[colPosition[j]].j = s.e[i].i;
        result->e[colPosition[j]].x = s.e[i].x;
        colPosition[j]++;
    }

    delete[] colCount;
    delete[] colPosition;

    return result;
}

int main()
{
    Sparse s;

    create(s);
    cout << "Original Matrix:" << endl;
    display(s);

    Sparse *transposedMatrix = transpose(s);

    cout << "\nTranspose Matrix:" << endl;
    display(*transposedMatrix);

    delete[] s.e;
    delete[] transposedMatrix->e;
    delete transposedMatrix;

    return 0;
}
