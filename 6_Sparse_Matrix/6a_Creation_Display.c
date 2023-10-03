#include<stdio.h>
#include<stdlib.h>  // For using malloc function

struct Element{
    int i, j, x;    // i->rows, j->columns, x->non-zero elements
};

struct Sparse{
    int n, m, num;  // m->rows, n->columns, num->non-zero elements
    struct Element *e;  // pointer e which holds list of elements
};


// Function for creating Sparse Matrix
void create(struct Sparse *s){
    printf("Enter dimensions (row x column): ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter no. of non-zero elements: ");
    scanf("%d",&s->num);
    // Create list of elements
    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter all non-zero elements: ");
    for(int i=0; i<s->num; i++){
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
};


// Function for displaying Sparse Matrix
void display(struct Sparse s){
    int k=0;
    for(int i=0; i<s.m; i++){
        for(int j=0; j<s.n; j++){
            if(i==s.e[k].i && j==s.e[k].j){
                printf("%d ", s.e[k++].x);
            } else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Sparse s;

    create(&s);
    display(s);
    return 0;
}