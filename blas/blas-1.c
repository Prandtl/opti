#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define X 1000
#define Y 1000
#define Z 2000

double *A, *B, *C;

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
    A = (double*) malloc(X * Y * sizeof(double));printf("A.\n");
    B = (double*) malloc(Y * Z * sizeof(double));printf("\tB.\n");
    C = (double*) malloc(X * Z * sizeof(double));printf("\t\tC.\n");

    struct timeval start, stop;

    double seconds;
    generate_matrices();

    printf("starting multiplication\n");
    gettimeofday(&start, NULL);
    multiply_matrices(A, B, C, X, Y, Z);
    gettimeofday(&stop, NULL);
    printf("finished.\n");

    if (C[0] < 0)
    {
        printf("negative\n");
    }
    else {
        printf("positive\n");
    }
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("multiplication took %lf s.\n", duration);

    free(A);
    free(B);
    free(C);
}
