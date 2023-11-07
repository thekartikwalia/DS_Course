#include <iostream>
using namespace std;
struct Term{
    int coeff;
    int exp;
};
struct Poly{
    int n;
    Term *terms;
};
void create(Poly &p){
    cout << "Enter no. of terms: ";
    cin >> p.n;
    // Dynamic allocation of memory for terms
    p.terms = new Term[p.n];
    cout << "Enter terms (co-efficient then exponent):\n";
    for (int i = 0; i < p.n; i++){
        cin >> p.terms[i].coeff >> p.terms[i].exp;
    }
}
void display(const Poly &p){
    for (int i = 0; i < p.n; i++){
        cout << p.terms[i].coeff << "(x^" << p.terms[i].exp << ") + ";
    }
    cout << endl;
}
Poly *add(const Poly &p1, const Poly &p2){
    Poly *sum = new Poly;
    sum->terms = new Term[p1.n + p2.n];
    int i = 0, j = 0, k = 0;
    while (i < p1.n && j < p2.n){
        if (p1.terms[i].exp > p2.terms[j].exp){
            sum->terms[k] = p1.terms[i];
            i++;
        }else if (p1.terms[i].exp < p2.terms[j].exp){
            sum->terms[k] = p2.terms[j];
            j++;
        }else{
            sum->terms[k] = p1.terms[i];
            sum->terms[k].coeff += p2.terms[j].coeff;
            i++;
            j++;
        }
        k++;
    }
    // Copy the remaining elements
    while (i < p1.n){
        sum->terms[k] = p1.terms[i];
        i++;
        k++;
    }
    while (j < p2.n){
        sum->terms[k] = p2.terms[j];
        j++;
        k++;
    }
    sum->n = k; // Update the number of terms in sum
    // Combine like terms in the result
    for (int i = 0; i < k - 1; i++){
        for (int j = i + 1; j < k; j++){
            if (sum->terms[i].exp == sum->terms[j].exp){
                sum->terms[i].coeff += sum->terms[j].coeff;
                // Shift the remaining terms to the left
                for (int l = j; l < k - 1; l++){
                    sum->terms[l] = sum->terms[l + 1];
                }
                k--; // Reduce the number of terms
                j--; // Recheck the current index since elements have shifted
            }
        }
    }
    sum->n = k; // Update the number of terms in sum
    return sum;
}
Poly *multiply(const Poly &p1, const Poly &p2){
    Poly *result = new Poly;
    result->n = p1.n * p2.n;
    result->terms = new Term[result->n];
    int k = 0;
    for (int i = 0; i < p1.n; i++){
        for (int j = 0; j < p2.n; j++){
            result->terms[k].coeff = p1.terms[i].coeff * p2.terms[j].coeff;
            result->terms[k].exp = p1.terms[i].exp + p2.terms[j].exp;
            k++;
        }
    }
    for (int i = 0; i < result->n - 1; i++){
        for (int j = i + 1; j < result->n; j++){
            if (result->terms[i].exp == result->terms[j].exp){
                result->terms[i].coeff += result->terms[j].coeff;
                for (int l = j; l < result->n - 1; l++){
                    result->terms[l] = result->terms[l + 1];
                }
                result->n--;
                j--;
            }
        }
    }
    return result;
}
int main(){
    Poly p1, p2, *p3, *p4;
    create(p1);
    create(p2);
    p3 = add(p1, p2);
    p4 = multiply(p1, p2);
    cout << "Polynomial 1:" << endl;
    display(p1);
    cout << "Polynomial 2:" << endl;
    display(p2);
    cout << "Polynomial sum:" << endl;
    display(*p3);
    cout << "Polynomial after multiplication:" << endl;
    display(*p4);
    delete[] p1.terms;
    delete[] p2.terms;
    delete[] p3->terms;
    delete[] p4->terms;
    delete p3;
    delete p4;
    return 0;
}

