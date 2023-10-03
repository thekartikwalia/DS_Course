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

// Function for adding 2 polynomials
struct Poly *add(struct Poly *p1, struct Poly *p2){
    struct Poly *sum;

    sum = (struct Poly*)malloc(sizeof(struct Poly));
    sum->terms = (struct Term*)malloc((p1->n + p2->n) * sizeof(struct Term));
    int i=0, j=0, k=0;
    while(i < p1->n && j < p2->n){
        if(p1->terms[i].exp > p2->terms[j].exp){
            sum->terms[k++] = p1->terms[i++];
        } else if(p1->terms[i].exp < p2->terms[j].exp){
            sum->terms[k++] = p2->terms[j++];
        } else {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    // Copying the remaining elements
    for(;i < p1->n; i++){
        sum->terms[k++] = p1->terms[i];
    }
    for(;j < p2->n; j++){
        sum->terms[k++] = p2->terms[j];
    }

    sum->n = k; // No. of elements in sum is k
    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("Polynomial 1 :\n");
    display(p1);
    printf("Polynomial 2 :\n");
    display(p2);
    printf("Polynomial sum:\n");
    display(*p3);

    return 0;
}