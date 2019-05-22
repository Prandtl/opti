#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <mkl.h>

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

void main() 
{
    A = (double*) mkl_malloc(X * Y * sizeof(double), 64);printf("A.\n");
    B = (double*) mkl_malloc(Y * Z * sizeof(double), 64);printf("\tB.\n");
    C = (double*) mkl_malloc(X * Z * sizeof(double), 64);printf("\t\tC.\n");

    struct timeval start, stop;

    double seconds;
    generate_matrices();

    printf("starting multiplication\n");
    gettimeofday(&start, NULL);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        X, Z, Y, 1.0, A, Y, B, Z, 0.0, C, Z);
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

    // free(A);
    // free(B);
    // free(C);
}
