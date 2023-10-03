#include<stdio.h>
#include<stdlib.h>

struct Term{
    int coeff;
    int exp;
};

struct Poly{
    int n;
    struct Term *terms;
};

// Function for creating Polynomial
void create(struct Poly *p){
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);
    // Dynamic allocation of memory for terms
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));
    printf("Enter terms: \n");
    for(int i=0; i < p->n; i++){
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

// Function for displaying polynomial
void display(struct Poly p){
    for(int i=0; i < p.n; i++){
        printf("%d(x^%d) + ", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

int main(){
    struct Poly p1;

    create(&p1);
    display(p1);
    
    return 0;
}