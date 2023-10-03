#include <stdio.h>
#include <stdlib.h> // For using malloc function

struct Element
{
    int i, j, x; // i->rows, j->columns, x->non-zero elements
};

struct Sparse
{
    int n, m, num;     // m->rows, n->columns, num->non-zero elements
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

// Function for finding tranpose of a Sparse matrix
struct Sparse *transpose(struct Sparse *s){
    struct Sparse *result = (struct Sparse *)malloc(sizeof(struct Sparse));
    // Transpose rows and columns
    result->m = s->n;
    result->n = s->m;
    result->num = s-> num;
    result->e = (struct Element *)malloc(result->num * sizeof(struct Element));

    // Initialize a frequency array to store the count of elements in each column
    int colCount[s->n];
    for (int i = 0; i < s->n; i++)
    {
        colCount[i] = 0;
    }

    // Calculate the count of elements in each column
    for (int i = 0; i < s->num; i++)
    {
        colCount[s->e[i].j]++;
    }

    // Calculate the cumulative count for each column
    int colPosition[s->n];
    colPosition[0] = 0;
    for (int i = 1; i < s->n; i++)
    {
        colPosition[i] = colPosition[i - 1] + colCount[i - 1];
    }

    // Fill the transpose matrix
    for (int i = 0; i < s->num; i++)
    {
        int j = s->e[i].j;
        result->e[colPosition[j]].i = s->e[i].j;
        result->e[colPosition[j]].j = s->e[i].i;
        result->e[colPosition[j]].x = s->e[i].x;
        colPosition[j]++;
    }

    return result;
}

int main()
{
    struct Sparse s;

    create(&s);
    printf("Original Matrix:\n");
    display(s);

    // Find the transpose of the matrix
    struct Sparse *transposedMatrix = transpose(&s);

    printf("\nTranspose Matrix:\n");
    display(*transposedMatrix);

    return 0;
}