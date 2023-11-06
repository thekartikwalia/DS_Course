#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    Term *terms;
};

// Function for creating Polynomial
void create(Poly &p)
{
    cout << "Enter no. of terms: ";
    cin >> p.n;
    // Dynamic allocation of memory for terms
    p.terms = new Term[p.n];
    cout << "Enter terms: \n";
    for (int i = 0; i < p.n; i++)
    {
        cin >> p.terms[i].coeff >> p.terms[i].exp;
    }
}

// Function for displaying polynomial
void display(const Poly &p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "(x^" << p.terms[i].exp << ") + ";
    }
    cout << endl;
}

// Function for multiplication of 2 polynomials
Poly *multiply(const Poly &p1, const Poly &p2)
{
    // Create a result polynomial
    Poly *result = new Poly;
    // Calculate the maximum possible number of terms in the result
    result->n = p1.n * p2.n;
    // Allocate memory for the terms in the result
    result->terms = new Term[result->n];

    // Initialize the index for the result polynomial
    int k = 0;

    // Multiply each term from p1 with each term from p2
    for (int i = 0; i < p1.n; i++)
    {
        for (int j = 0; j < p2.n; j++)
        {
            // Multiply coefficients and add exponents
            result->terms[k].coeff = p1.terms[i].coeff * p2.terms[j].coeff;
            result->terms[k].exp = p1.terms[i].exp + p2.terms[j].exp;
            k++;
        }
    }

    // Simplify the result polynomial by combining like terms
    for (int i = 0; i < result->n - 1; i++)
    {
        for (int j = i + 1; j < result->n; j++)
        {
            if (result->terms[i].exp == result->terms[j].exp)
            {
                // Combine coefficients of like terms
                result->terms[i].coeff += result->terms[j].coeff;
                // Shift remaining terms to the left
                for (int l = j; l < result->n - 1; l++)
                {
                    result->terms[l] = result->terms[l + 1];
                }
                // Reduce the number of terms in the result
                result->n--;
                j--;
            }
        }
    }

    return result;
}

int main()
{
    Poly p1, p2, *p3;

    create(p1);
    create(p2);

    p3 = multiply(p1, p2);

    cout << "Polynomial 1 :" << endl;
    display(p1);
    cout << "Polynomial 2 :" << endl;
    display(p2);
    cout << "Polynomial after multiplication:" << endl;
    display(*p3);

    delete[] p1.terms;
    delete[] p2.terms;
    delete[] p3->terms;
    delete p3;

    return 0;
}
