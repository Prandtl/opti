#include <stdio.h>
#include <stdlib.h>

#define X 1000
#define Y 1500
#define Z 1000

double A[X * Y], B[Y * Z], C[X * Z];

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

void multiply_matrices(double A[], double B[], double C[], int x, int y, int z) {
    int i, j, k;
    double sum;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < z; j++)
        {
            sum = 0;
            for (k = 0; k < y; k++)
            {
                sum = sum + A[i * y + k] * B[k * z + j];
            }
            C[z * i + j] = sum;
        }
    }
}

void main()
{
    generate_matrices();
    print_matrice(A, X, Y);
    printf("\n");
    print_matrice(B, Y, Z);
    printf("\n");

    multiply_matrices(A, B, C, X, Y, Z);

    printf("\n");
    print_matrice(C, X, Z);
}
