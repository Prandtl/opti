#include <stdio.h>
#include <stdlib.h>

#define X 3
#define Y 4
#define Z 5

double A[X * Y], B[Y * Z];

void generate_matrices() {
    int i, j;
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            A[Y * i + j] = (double)rand()/RAND_MAX*20.0 - 10.0;
        }
    }
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < Z; j++)
        {
            B[Z * i + j] = (double)rand()/RAND_MAX*20.0 - 10.0;
        }
    }
}

void print_matrice(double M[], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%lf ", M[c * i + j]);
        }
        printf("\n");
    }
}

void main()
{
    generate_matrices();
    print_matrice(A, X, Y);
    printf("\n");
    print_matrice(B, Y, Z);
}
