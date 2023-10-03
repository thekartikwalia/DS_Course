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


// Function to add 2 Sparse Matrices
struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;

    // Create an object of Sparse Matrix
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    // Create an array of elements
    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    int i = 0, j = 0, k = 0;
    // This while loop will terminate when any one of the matrix has finished
    while (i < s1->e[i].i && j < s2->e[i].j)
    {
        if (s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[i].j)
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    // Copying rest of elements from remaining matrix
    for(;i < s1->num; i++){
        sum->e[k++]=s1->e[i];
    }
    for(;j < s2->num; j++){
        sum->e[k++]=s2->e[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;   // k stores no. of non-zero elements

    return sum;

}

int main()
{
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);
    printf("First Matrix\n");
    display(s1);
    printf("Second Matrix\n");
    display(s2);
    printf("Sum Matrix\n");
    display(*s3);
    return 0;
}