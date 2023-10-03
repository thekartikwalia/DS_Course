#include <stdio.h>
#include <stdlib.h> // For using malloc function

struct Element
{
    int i, j, x; // i->rows, j->columns, x->non-zero elements
};

struct Sparse
{
    int m, n, num;     // m->rows, n->columns, num->non-zero elements
    struct Element *e; // pointer e which holds list of elements
};

void create(struct Sparse *s)
{
    printf("Enter dimensions (row x column): ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter no. of non-zero elements: ");
    scanf("%d", &s->num);
    // Create list of elements
    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter all non-zero elements: ");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
};

void display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                printf("%d ", s.e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to multiply 2 Sparse Matrices
struct Sparse *multiply(struct Sparse *s1, struct Sparse *s2){
    // Check if multiplication of matrix is possible
    if(s1->n != s2->m){
        printf("Matrix Multiplication not possible!\n");
        return NULL;
    }
    struct Sparse *result;
    // Create an object of Sparse Matrix
    result = (struct Sparse *)malloc(sizeof(struct Sparse));
    result->m = s1->m; // Set the number of rows for the result matrix
    result->n = s2->n; // Set the number of columns for the result matrix
    result->num = 0;   // Initialize the number of non-zero elements to 0

    // Create an array of elements
    result->e = (struct Element *)malloc(result->num * sizeof(struct Element));

    int sum, k=0;
    for(int i=0; i < s1->m; i++){
        for(int j=0; j < s2->n; j++){
            sum = 0;
            // Iterate through elements of first matrix
            for (int l = 0; l < s1->num; l++)
            {
                // Iterate through elements of second matrix
                for (int m = 0; m < s2->num; m++)
                {
                    // Check if elements match for multiplication
                    if (s1->e[l].j == s2->e[m].i && s1->e[l].i == i && s2->e[m].j == j)
                    {
                        sum += s1->e[l].x * s2->e[m].x;
                    }
                }
            }
            // If the sum is not zero, add it to the result matrix
            if (sum != 0){
                result->num++;
                result->e = (struct Element *)realloc(result->e, result->num * sizeof(struct Element));
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
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = multiply(&s1, &s2);
    printf("First Matrix\n");
    display(s1);
    printf("Second Matrix\n");
    display(s2);
    printf("Product Matrix\n");
    display(*s3);
    return 0;
}