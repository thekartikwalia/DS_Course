#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

// Function for creating Polynomial
void create(struct Poly *p)
{
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);
    // Dynamic allocation of memory for terms
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));
    printf("Enter terms: \n");
    for (int i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

// Function for displaying polynomial
void display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%d(x^%d) + ", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

// Function for multiplication of 2 polynomials
struct Poly *multiply(struct Poly *p1, struct Poly *p2){
    // Create a result polynomial
    struct Poly *result = (struct Poly*)malloc(sizeof(struct Poly));
    // Calculate the maximum possible number of terms in the result
    result->n = p1->n + p2->n;
    // Allocate memory for the terms in the result
    result->terms = (struct Term*)malloc(result->n * sizeof(struct Term));

    // Initialize the index for the result polynomial
    int k = 0;

    // Multiply each term from p1 with each term from p2
    for(int i=0; i < p1->n; i++){
        for(int j=0; j < p2->n; j++){
            // Multiply coefficients and add exponents
            result->terms[k].coeff = p1->terms[i].coeff * p2->terms[j].coeff;
            result->terms[k].exp = p1->terms[i].exp + p2->terms[j].exp;
            k++;
        }
    }

    // Simplify the result polynomial by combining like terms
    for(int i=0; i < result->n -1; i++){
        for(int j=i+1; j < result->n; j++){
            if(result->terms[i].exp == result->terms[j].exp){
                // Combine coefficients of like terms
                result->terms[i].coeff += result->terms[j].coeff;
                // Shift remaining terms to the left
                for (int l = j; l < result->n - 1; l++){
                    result->terms[l] = result->terms[l + 1];
                }
                /*
                Above code is used to remove a term from the result polynomial when two terms with 
                same exponent are found. When two terms with the same exponent are combined, you only 
                want to keep one of them in the result polynomial. The loop iterates over the terms in 
                the result polynomial starting from the position j (where a duplicate term was found) 
                up to one position before the end of the result array (result->n - 1). It effectively 
                shifts all terms after the j-th position one position to the left, overwriting the 
                duplicate term. This way, duplicate term is effectively removed from result polynomial.
                */

                // Reduce the number of terms in the result
                result->n--;
                j--; // Check the same position again
                /*
                After shifting the terms to the left to remove the duplicate term, j is decremented by
                one(j--).This is done to ensure that the next iteration of the inner loop(j loop)
                checks the term that has replaced the duplicate term.Without decrementing j, the loop
                would skip checking the term that has now moved to the j - th position after the removal
                of the duplicate term.By decrementing j, the loop effectively rechecks the term that has
                taken the position of the removed duplicate term, ensuring that no duplicate terms are
                missed during the process of combining like terms.
                */
            }
        }
    }

    return result;

}

int main()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = multiply(&p1, &p2);

    printf("Polynomial 1 :\n");
    display(p1);
    printf("Polynomial 2 :\n");
    display(p2);
    printf("Polynomial after multiplication:\n");
    display(*p3);

    return 0;
}